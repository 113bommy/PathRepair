#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n,i;
  cin>>n;
  int h[n],dp[n];
  for(i=0;i<n;i++){
    cin>>h[i];
  }
  dp[0]=0;
  dp[1]=abs(h[1]-h[0]);
  for(i=0;i<n-2;i++){
    dp[i+2]=min(dp[i+1]+abs(h[i+2]-h[i+1]),dp[i]+abs(h[i+2]-h[i]));
  }
  cout<<dp[n-1];
}
