#include<iostream>
using namespace std;

int main(){
  int a,b;
  cin>>a>>b;
  if((a*b)%3==1)cout<<"Impossible"<<endl;
  else cout<<"Possible"<<endl;
}