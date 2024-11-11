#include<iostream>
using namespace std;

int main(){
  int a,b;
  char p;
  cin>>a>>p>>b;
  if(p=="+")
    cout<<a+b;
  else
    cout<<a-b;
  return 0;
}