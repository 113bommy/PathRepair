#include<iostream>
using namespace std;
int main(){
int a,b,c[100000],d,e;
cin>>a>>b;
  d=0;
  e=1;
for(int i=0;i<a;i++){
    cin>>c[i];
  d+=c[i];
  if(d<=b){e++;}
  
}
  cout<<e;
}
