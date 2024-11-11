#include<iostream>
using namespace std;
int main(){
  int e,r;
  cin>>e>>r;
  if(!e){
    if(y<1912)cout<<'M'<<y-1867<<endl;
    else if(y<1926)cout<<'T'<<y-1911<<endl;
    else if(y<1989)cout<<'S'<<y-1925<<endl;
    else cout<<'H'<<y-1988<<endl;
  }
  if(e==1)cout<<y+1867<<endl;
  if(e==2)cout<<y+1911<<endl;
  if(e==3)cout<<y+1925<<endl;
  if(e==4)cout<<y+1988<<endl;
}