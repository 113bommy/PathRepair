#include <bits/stdc++.h>
using namespace std;

int main(){
  int a=0,x,y,z;
  cin>>x;
  for(int i=0;i<x;i++){
    cin>>y>>z;
    a+=z-y+1;
  }
  cout<<a<<endl;
}
