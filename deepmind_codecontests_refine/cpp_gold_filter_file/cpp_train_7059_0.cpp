#include<cstdio>

using namespace std;

char mp[2000][2000];
int dp[2000][2000],MOD=1e9+7;

int main()
{
  int h=0,w=0;scanf("%d%d",&h,&w);
  for(int i=1;i<=h;i++)scanf("%s",mp[i]+1);
  for(int i=1;i<=h;i++)
  {
    for(int j=1;j<=w;j++)
    {
      if(i==1&&j==1)dp[i][j]=1;
      else if(mp[i][j]=='#')dp[i][j]=0;
      else dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
    }
  }
  printf("%d",dp[h][w]);
  return 0;
}
  