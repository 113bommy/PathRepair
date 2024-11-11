#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

vector<int> ed[200000];

int dp[200000];
int dfs(int x)
{
  if(dp[x])return dp[x];
  dp[x]=0;for(int i=0;i<ed[x].size();i++)dp[x]=max(dp[x],dfs(ed[x][i])+1);
  return dp[x];
}

int main()
{
  int n=0,m=0;scanf("%d%d",&n,&m);for(int i=1,a=0,b=0;i<=m;i++){scanf("%d%d",&a,&b);ed[a].push_back(b);}
  for(int i=1;i<=n;i++)if(!dp[i])dfs(i);
  int maxn=0;for(int i=1;i<=n;i++)maxn=max(maxn,dp[i]);printf("%d,maxn);
  return 0;
}