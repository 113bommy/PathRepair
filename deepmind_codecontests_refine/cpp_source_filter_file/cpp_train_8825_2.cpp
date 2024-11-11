#include<bits/stdc++.h>
using namespace std;

int main(){
  int a,b;
  cin>>a>>b;
  for(int i=b*10; i<=10*b+9; i++){
    if((i*8)/100==a){
      cout<<i;
      return 0;
    }
  }
  
  
  cout<<-1;