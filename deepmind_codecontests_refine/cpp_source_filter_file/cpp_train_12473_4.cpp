#include <bits/stdc++.h>
using namespace std;
int main(){
  int N;cin>>N;int h[N],dp[N];dp[0]=0;
  for(int i=0;i<N;i++)cin>>h[i];
  dp[1]=abs(h[0]-h[1]);
  for(int i=2;i<N;i++){
    dp[i]=min(dp[i-1]+abs(h[i]-h[i-1],dp[i-2]+abs(h[i]-h[i-2]));
  }
  cout<<dp[N-1]<<endl;
}