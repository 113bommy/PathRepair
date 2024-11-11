#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b,x,y,z;
  cin>>a>>b>>x>>y>>z;
  string c;
  cin>>c;
  for(int i=0;i<a-b;i++){
  if(c.at(i)==c.at(i+b)){
  c.at(i+b)='f';
  }
  }
  int sum=0;
  for(int j=0;j<a;j++){
  if(c.at(j)=='r'){
  sum+=z;
  }
  if(c.at(j)=='s'){
  sum+=x;
  }
  if(c.at(j)=='p'){
  sum+=y;
  }
  }
  cout<<sum<<endl;
