#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int Mx(int a,int b){return a>b?a:b;}
int Mn(int a,int b){return a<b?a:b;}
const int N=190;
int n,m,sm[N][N],dp[2][N][N][N];
char ch[N][N];
bool chk(int x1,int y1,int x2,int y2)
{
  int s=sm[x2][y2]-sm[x2][y1-1]-sm[x1-1][y2]+sm[x1-1][y1-1];
  return (!s)||s==(x2-x1+1)*(y2-y1+1);
}
int main()
{
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;i++)
    scanf("%s",ch[i]+1);
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)sm[i][j]=sm[i][j-1]+(ch[i][j]=='.');
  for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)sm[i][j]+=sm[i-1][j];
  for(int i=1;i<=n;i++)
    for(int j1=1;j1<=m;j1++)
      for(int j2=j1;j2<=m;j2++)
	{
	  int l=i,r=n,ans=i-1;
	  while(l<=r)
	    {
	      int mid=l+r>>1;
	      if(chk(i,j1,mid,j2))ans=mid,l=mid+1;
	      else r=mid-1;
	    }
	  dp[0][i][j1][j2]=ans;
	}
  if(dp[0][1][1][m]==n){puts("0");return 0;}
  bool u=1,v=0;
  for(int t=1;t<=16;t++,swap(u,v))
    {
      for(int i=1;i<=n;i++)
	for(int j1=1;j1<=m;j1++)
	  for(int j2=j1;j2<=m;j2++)
	    {
	      int d=dp[v][dp[v][i][j1][j2]+1][j1][j2];
	      if(dp[v][i][j1][j2]==n)
		{ dp[u][i][j1][j2]=n;continue;}
	      int l=j1,r=j2-1;
	      while(l<=r)
		{
		  int mid=l+r>>1;
		  int t1=dp[v][i][j1][mid],t2=dp[v][i][mid+1][j2];
		  d=Mx(d,Mn(t1,t2));
		  if(t1>=t2)l=mid+1; else r=mid-1;
		}
	      dp[u][i][j1][j2]=d;
	    }
      if(dp[u][1][1][m]==n)
	{printf("%d\n",t);return 0;}
    }
}
q