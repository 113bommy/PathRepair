#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,T;
  cin>>N>>T;
  int Z=10000;
  for(int i=0;i<N;i++){
    int c,t;
    cin>>c>>t;
    if(t<=T){
      Z=min(c,Z);
    }
  }
  if(Z==100000){
    cout<<"TLE"<<endl;
  }
  else{
    cout<<c<<endl;
  }
}
