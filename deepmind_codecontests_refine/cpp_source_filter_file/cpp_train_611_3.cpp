#include<bits/stdc++.h>
using namespace std;
#define r(i,n) for(int i=0;i<n;i++)
string s[9999];
int h,w,dp[1002][10002][3],a,b,c,d,n;
main(){
  cin>>h>>w>>n;
  r(i,w+1)s[0]+='@';
  r(i,h)cin>>s[i+1],s[i+1]='@'+s[i+1];
  for(int i=1;i<=h;i++)
    for(int j=1;j<=w;j++){
      r(k,3)dp[i][j][k]+=dp[i][j-1][k];
      if(s[i][j]=='J')dp[i][j][0]++;
      if(s[i][j]=='O')dp[i][j][1]++;
      if(s[i][j]=='I')dp[i][j][2]++;
    }
  for(int i=1;i<=h;i++)
    for(int j=1;j<=w;j++)
      r(k,3)dp[i][j][k]+=dp[i-1][j][k];
  while(n--){
    scanf("%d%d%d%d",&a,&b,&c,&d)a--;b--;
    cout<<dp[c][d][0]-dp[a][d][0]-dp[c][b][0]+dp[a][b][0]<<' ';
    cout<<dp[c][d][1]-dp[a][d][1]-dp[c][b][1]+dp[a][b][1]<<' ';
    cout<<dp[c][d][2]-dp[a][d][2]-dp[c][b][2]+dp[a][b][2]<<endl;
  }
}