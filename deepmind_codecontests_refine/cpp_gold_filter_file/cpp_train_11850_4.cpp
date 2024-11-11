#include<bits/stdc++.h>
using namespace std;
int main(){
  int N,M;cin>>N>>M;
  int x=M/2+1;
  if(N==1){
    cout<<M;return 0;
  }
  
  while(1){
    if(M%x==0&&M/x>=N){
      cout<<x;return 0;
    }x--;
  }
  
}
