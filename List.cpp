#include <iostream>
#include "ListNode.h"
#include "ListItr.h"
using namespace std;

List::List() {
  head = new ListNode();
  tail = new ListNode();
  head->next=tail;
  tail->previous=head;
  count = 0;
}
List::~List(){
  makeEmpty();   
  delete head;
  delete tail; 
}

bool List::isEmpty() const{
  return count==0;
}


void List::makeEmpty() {
  ListItr a = first();
  while(!isEmpty()){
    remove(a.current->value);
    a.moveForward();
 
  }
  }

ListItr List::first(){
  ListItr a(head->next);
  return a; 

}

ListItr List::last(){
  ListItr a(tail->previous);
  return a;
}

void List::insertAfter(int x, ListItr position){
  ListNode *a = new ListNode();
  a-> value = x;
  a-> previous = position.current;
  a->next=position.current->next;
  position.current -> next = a;
  a->next ->previous = a;
  count++;
}

void List::insertBefore(int x, ListItr position){
  ListNode *a = new ListNode();
  a-> value =  x;
  a-> next = position.current;
  a-> previous = position.current->previous;
  position.current->previous = a; 
  a->previous->next=a; 
  count++;
}

void List::insertAtTail(int x){
  ListNode *a = new ListNode();
  ListItr b = last();
  a-> value = x;
  b.current->next=a;
  a->previous = b.current;
  a->next=tail;
  tail->previous=a;
  count++; 

}

void List::remove(int x){
  ListItr a = find(x);
  if(a.current != NULL) {
  a.current->previous->next = a.current->next;
  a.current->next->previous = a.current->previous;
  delete a.current;
  count--;
  }
}

ListItr List::find(int x){
  ListItr itr = first();
  while(!itr.isPastEnd()){
    if(itr.current->value!=x){
      itr.moveForward();
    }
    else{
      return itr;
    }
  }
  return NULL;
}

int List::size() const{
  return count;
}


List::List(const List& source) {      // Copy Constructor
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
};

List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
};

void printList(List& theList, bool forward){
  ListItr a = theList.first();
   int x=1;
  if(forward){
    while(!a.isPastEnd() && x<=theList.size()){
      cout<<a.retrieve()<<endl;
      a.moveForward();
           x++;
    }
  }
 
 else{
   //&& x<=theList.size()
ListItr b=theList.last();
   int y=1;
 while(y<=theList.size()){
     cout<<b.retrieve()<<endl;
     b.moveBackward();
      y++;
   }
 }
}
