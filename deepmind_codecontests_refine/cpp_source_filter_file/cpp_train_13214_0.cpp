#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
P dp[105][50005];
int p[100];
void Max(P &a,P b){a=max(a,b);}

int main(){
  int n;
  while(cin>>n && n){
    memset(dp,-1,sizeof(dp));
    for(int i=0;i<n;i++)cin>>p[i];
    dp[0][0] = P(0,0);
    for(int i=0;i<n;i++){
      for(int j=0;j<50000;j++){
        if(dp[i][j]==P(-1,-1)) continue;
        int nf=dp[i][j].first,ns=dp[i][j].second-p[i];
        Max(dp[i+1][j],dp[i][j]);
        if(p[i]%1000==0)
          {if(j>=500) Max(dp[i+1][j-500],P(nf+1,ns));}
        else if(p[i]%1000<500) Max(dp[i+1][j+500-p[i]%500],P(nf+1,ns));
        else if(p[i]%500<=j) Max(dp[i+1][j-p[i]%500],P(nf+1,ns));
        else Max(dp[i+1][j+500-p[i]%500],P(nf,ns)); 
      
    }
    P ans(0,0);
    for(int i=0;i<50000;i++) Max(ans,dp[n][i]);
    cout<<ans.first<<" "<<-ans.second<<endl;
  }  
  return 0;
}