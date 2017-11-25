//
//  main.cpp
//  ArrayList
//
//  Created by Tatyana Volkorezova on 18.11.2017.
//  Copyright © 2017 shpp.com. All rights reserved.
//
#include <iostream>
using namespace std;

class ArrayList{
private:
    const int ARRAY_SIZE = 10;
    
    int* array;
    int currentSize;
    int allocatedSize;
    int size = ARRAY_SIZE;
    
    void fillNewArray(int* newArray){
        for(int i = 0; i < currentSize; i++){
            newArray[i] = array[i];
        }
    }
    void addToNotFullArray(int newValue){
        array[currentSize] = newValue;
        currentSize++;
    }
    
    void addToFullArray(int newValue){
        doubleCapacityOfArray();
        addToNotFullArray(newValue);
    }
    
public:
    ArrayList(){
        array = new int [ARRAY_SIZE];
        currentSize = 0;
        allocatedSize = ARRAY_SIZE;
    }
    
    //method of doubling capacity of array
    void doubleCapacityOfArray(){
        int* newArray = new int (allocatedSize  *2);
        allocatedSize *= 2;
        fillNewArray(newArray);
        delete []array;
        array = newArray;
    }
    
    //method for adding new element by value
    void add(int newValue){
        if(currentSize < allocatedSize){
            addToNotFullArray(newValue);
        }else{
            addToFullArray(newValue);
        }
    }
    
    //method for adding new element by index
    void add(int newValue, int index){
        
        //if out from array - error
        if(index >= currentSize){
            cout<<"ERROR! OUT OF BOUND"<<endl;
            return;
        }
        
        if(currentSize >= allocatedSize){
            doubleCapacityOfArray();
        }
        
        //shift array
        for(int i = currentSize; i > index; i--){
            array[i] = array[i-1];
        }
        array[index] = newValue;
        currentSize++;
    }
    
    
    //method for trim array size
    void trimToSize(){
        
        int* tmpArray = new int[currentSize];
        for(int i = 0; i < currentSize; i++){
            tmpArray[i] = array[i];
        }
        delete[] array;
        array = new int[currentSize];
        for(int i = 0; i < currentSize; i++){
            array[i] = tmpArray[i];
        }
        delete []tmpArray;
    }
    
    
    //method for getting element by index
    int get(int index){
        
        if(index >= currentSize){
            cout<<"Error!!! Index is out"<<endl;
            return -1;
        }
        return array[index];
    }
    
    //method for removing element from array
    void remove(int index){
        
        for(int i = 0; i < currentSize; i++){
            if(array[i] == index){
                for( ; i < currentSize - 1; i++){
                    //assign the next element to current location.
                    array[i] = array[i + 1];
                }
                
                //remove the last element as it has been moved to previous index.
                array[currentSize - 1] = 0;
                currentSize = currentSize - 1;
            }
        }
    }
    
    //method for print array
    void print(){
        for(int i = 0; i < currentSize; i++){
            cout<<array[i]<<" ";
        }
    }
};




int main(int argc, const char * argv[]){
    ArrayList* list = new ArrayList();
   
    for(int i = 0; i < 10; i++){
        list->add(i);
    }
    list->print();
    cout<<endl;
    
    list->remove(0);
    list->remove(1);
    list->remove(7);
    list->print();
    
    list->trimToSize();
    
    list->add(13, 1);
    cout<<endl;
    list->print();
    list->add(10, 0);
    cout<<endl;
    list->print();
    list->add(12, 2);
    cout<<endl;
    list->print();
}



