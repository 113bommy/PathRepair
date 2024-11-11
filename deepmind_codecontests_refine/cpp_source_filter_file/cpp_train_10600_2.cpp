#include<iostream>
using namespace std;
int main(){
  int n;
  cint>>n;
  int a,b=0;
  for(int i=0;i<n;++i){
    cin>>a;
    while(!(a%2))b++,a/=2;
  }
  cout<<b;
  return 0;
}