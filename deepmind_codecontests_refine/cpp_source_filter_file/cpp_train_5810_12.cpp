#include<iostream>
using namespace std;
int main(){
  int a,b;
  cin<<a<<b;
  int n;
  n=a+b;
  if(n%2==0)
    cout<<n/2;
  else
    cout<<"IMPOSSIBLE";
  return 0;
}