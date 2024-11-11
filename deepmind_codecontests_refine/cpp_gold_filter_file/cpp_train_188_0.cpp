
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1<<15;
int n,m,c[15][15];
int p[N],dp[N][15];
void init()
{
	memset(p,0,sizeof(p));
	for(int i=0;i<(1<<n);i++)
		for(int j=0;j<n;j++)
			dp[i][j]=-1;
	for(int i=0;i<(1<<n);i++)
	{
		for(int j=0;j<n;j++)
		{
			if(((i>>j)&1)==0)
				continue;
			for(int k=j+1;k<n;k++)
			{
				if(((i>>k)&1)==0)
					continue;
				p[i]+=c[j][k];
			}
		}
	}
}
int main()
{
	while(cin>>n>>m)
	{
		int sum=0; 
		int u,v,w;
		memset(c,0,sizeof(c));
		while(m--)
		{
			scanf("%d%d%d",&u,&v,&w);
			u--,v--;
			c[u][v]=c[v][u]=w;
			sum+=w;
		}

        
		init();
		dp[1][0]=0;
		for(int i=0;i<(1<<n);i++)
		{
			for(int j=0;j<n;j++)
			{
				if(dp[i][j]==-1)
					continue;
				int x=(((1<<n)-1)^i)|(1<<j);	//y is some subset of x
				for(int y=x;y>=0;y--)
					y&=x,dp[i|y][j]=max(dp[i|y][j],dp[i][j]+p[y]);	
					
				for(int k=0;k<n;k++)
				{
					if((i>>k)&1)
						continue;
					if(c[j][k]==0)
						continue;
					dp[i|(1<<k)][k]=max(dp[i|(1<<k)][k],dp[i][j]+c[j][k]);
				}
			}
		}
		int ans=1e9;
		for(int i=0;i<(1<<n);i++)
			ans=min(ans,sum-dp[i][n-1]);
		cout<<ans<<endl;
	}
	return 0;
}
