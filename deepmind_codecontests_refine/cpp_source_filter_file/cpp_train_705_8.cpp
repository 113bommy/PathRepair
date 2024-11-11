#include <bits.stdc++.h>
using namespace std;
int main(){
  int N,M; cin>>N>>M;
  vector<int>K(M);
  vector<vector<int>>S(M,vector<int>(N));
  vector<int>p(M);
  for(int i=0;i<M;i++){
    cin>>K[i];
    for(int j=0;j<K[i];j++)cin>>S[i][j];
  }
  for(int i=0;i<M;i++)cin>>p[i];
  long long ans=0;
  for(int bit=0;bit<=(1<<N);bit++){
    vector<bool>C(N,false);
    for(int i=0;i<N;i++)if(bit&(1<<i))C[i]=true;
    for(int i=0;i<M;i++){
      long long count=0;
      for(int j=0;j<K[i];j++)if(C[S[i][j]])count++;
      if(count%2!=p[i])break;
      if(i==M-1)ans++;
    }
  }
  cout<<ans<<endl;
}