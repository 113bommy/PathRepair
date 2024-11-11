#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll N,M;
  cin>>N>>M;
  vector<string> A(N);
  for(ll i=;i<N;i++) {
cin>>A[i];
  }
  vector<string> B(M);
  for(ll i=0;i<M;i++) {
cin>>B[i];
  }
  
  for(ll i=0;i<N-M+1;i++) {
for(ll j=0;j<N-M+1;j++) {
  bool a=true;
  
for(ll h=0;h<M;h++) {
for(ll k=0;k<M;k++) {
  if(S[i+h][j+k]!=T[h][k]) {
a=false;
  }
}
}
  if(a) {
cout<<"Yes"<<endl;
  return 0;
  }
}
  }
  
  cout<<"No"<<endl;
}
  

  
  
  
  
  
