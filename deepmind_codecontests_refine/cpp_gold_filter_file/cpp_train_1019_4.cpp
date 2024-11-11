#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;
  string S;cin>>S;
  vector<int>A(N+1);
  vector<int>B(N+1);
  for(int i=0;i<N;i++){
    if(i!=0)A[i+1]+=A[i];
    if(S.at(i)=='#')A[i+1]++;
  }
  for(int i=N-1;i>=0;i--){
    if(i!=N-1)B[i]+=B[i+1];
    if(S.at(i)=='.')B[i]++;
  }
  int ans=10000000;
  for(int i=0;i<=N;i++){
    ans=min(ans,A[i]+B[i]);
  }
  cout<<ans<<endl;
}