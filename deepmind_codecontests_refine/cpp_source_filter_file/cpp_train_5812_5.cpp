#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,T;
  cin>>N>>T;
  int C=1001
  for(int i=0;i<N;i++){
    int c,t;
    cin>>c>>t;
    if(t<=T)
      C=min(C,c);
  }
  if(C==1001)
    cout<<"TLE"<<endl;
  else
    cout<<C<<endl;
}