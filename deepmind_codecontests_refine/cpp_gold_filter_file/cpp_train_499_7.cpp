#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
  int A,B,C,X,Y,val=0;
  cin>>A>>B>>C>>X>>Y;
  val = min(A+B,2*C) * min(X,Y);
  if(X>Y){
    val += ((X-Y) * min(A,2*C));
  }else{
    val += ((Y-X) * min(B,2*C));
  }
  cout<<val;

  return 0;
}