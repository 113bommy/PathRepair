#include<bits/stdc++.h>
using namespace std;
int main(){
  int N;
  cin>>N;
  for(int i=0;i<=N;i++){
    int X=i*108/100;
    if(X==N){
      cout<<i<<endl;
    return 0;
    }
  }
  cout<<":("<<endl;
  return 0;
}
