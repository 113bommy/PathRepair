#include <iostream>
using namespace std;
int main(){
int a,b,c,d,x,y;
  cin>>a>>b>>c>>d;
  x = (a+d-1)/d; 
  y = (c+b-1)/b;
  if (x>=y){
  	cout<<"Yes";
  }
  else{
  	cout<<"No";
  }
  
}