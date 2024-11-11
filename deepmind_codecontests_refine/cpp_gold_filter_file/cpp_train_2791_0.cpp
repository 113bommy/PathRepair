#include <bits/stdc++.h>
using namespace std;
int main(){
  int N,K;cin>>N>>K;int h[N],dp[N];dp[0]=0;
  for(int i=0;i<N;i++)cin>>h[i];
  for(int i=1;i<N;i++){
    dp[i]=2000000000;
    for(int j=1;j<=min(K,i);j++)dp[i]=min(dp[i],dp[i-j]+abs(h[i]-h[i-j]));
  }
  cout<<dp[N-1]<<endl;
}
