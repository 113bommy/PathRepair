#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+5;

int main(){
  int n,h;
  cin>>n>>h;
  vector<int>dp(h+1,INF);
  dp[0]=0;
  while(n--){
    int weight,value;
    cin>>value>>weight;
    for(int i=0;i<=h;i++){
      int j=min(h,i+value);
      dp[j]=min(dp[j],dp[i]+cost);
    }
  }
  cout<<dp[h];
  return 0;
}