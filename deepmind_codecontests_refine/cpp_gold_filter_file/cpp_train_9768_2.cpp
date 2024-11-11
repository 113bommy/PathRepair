#include <bits/stdc++.h>

using namespace std;

int n,m,d;
int fa[55];
long long dp[51][125500],val[55],sz[55];
long long pre[55],pre2[55];
int id[55];

bool cmp(int a,int b)
{
	return sz[a] * val[b] > sz[b] * val[a];
}

int main()
{
	scanf("%d%d%d",&n,&m,&d);
	scanf("%lld",&val[1]); sz[1] = 1;
	for(int i = 2;i <= n; ++ i)
		scanf("%lld%d",&val[i],&fa[i]),sz[i] = 1;
	for(int i = n;i >= 2; -- i)
		sz[fa[i]] += sz[i],val[fa[i]] += val[i];
	memset(dp,0x3f3f3f3f,sizeof(dp));
	dp[0][0] = 0;
	int lim = min(d,n);
	for(int i = 1;i <= n; ++ i)
	{
		id[i] = i;
		for(int j = 0;j <= (i - 1) * lim * n; ++ j)
			if(dp[i - 1][j] <= m)
			{
				for(int k = 0;k <= lim; ++ k)
				{
					dp[i][j + k * sz[i]] = min(dp[i][j + k * sz[i]],dp[i - 1][j] + val[i] * k);
					if(dp[i][j + k * sz[i]] > m) break;
				}
			}
	}
	sort(id + 1,id + 1 + n,cmp);
	for(int i = 1;i <= n; ++ i)
	{
		if(pre[i - 1] >= m)
		{
			pre[i] = pre[i - 1] + 1;
			continue;
		}
		int fuck = id[i];
		int tmp = fuck == 1 ? 1e9 : d - lim;
		if(val[fuck] >= m && tmp)
			pre[i] = m;
		else
			pre[i] = pre[i - 1] + tmp * val[fuck],
			pre2[i] = pre2[i - 1] + tmp * sz[fuck];
	}
	long long ans = 0;
	for(int i = 0;i <= n * n * lim; ++ i)
		if(dp[n][i] <= m)
		{
			long long fuck = m - dp[n][i];
			int pos = upper_bound(pre + 1,pre + 1 + n,fuck) - pre - 1;
			ans = max(ans,i + pre2[pos] + sz[id[pos + 1]] * ((fuck - pre[pos]) / val[id[pos + 1]]));
		}
	printf("%lld\n",ans);
	return 0;
}