#include <iostream>

using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  if((a+b)%2==0){
    cout<<(a+b)/2;
  }else{
    cout<<"IMPOSSIBLE"
  }
  return 0;
}