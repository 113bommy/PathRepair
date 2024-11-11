#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>

const int maxn = 1e5 + 20;
const int maxs = (1 << 16) + 7;

int n;
int val[maxn], cnt[16], ans;
int dp[maxs];

template<class TAT>void checkmin(TAT &x,const TAT &y)
{
	if(y < x) x = y;
}
int dfs(int x)
{
	if(dp[x] != -1) return dp[x];
	
	dp[x] = maxs;
	
	for(int i = 0; i < 16; i++)
		for(int j = 0; j < 16; j++)
			if(x != y && ((x >> i) & 1) && ((x >> j) & 1))
			{
				int tmp = x ^ (1 << i) ^ (1 << j);
				int modify = i ^ j;
				
				checkmin(dp[x], tmp ^ (1 << modify) + 1 + ((tmp >> modify) & 1));
			}
	
	return dp[x];
}
int main()
{
	scanf("%d", &n);
	for(int i = 1, x, y, a; i < n; i++)
	{
		scanf("%d%d%d", &x, &y, &a);
		++x, ++y;
		val[x] ^= a, val[y] ^= a;
	}
	
	for(int i = 1; i <= n; i++)
	{
		if(val[i])
		{
			ans += cnt[val[i]];
			cnt[val[i]] ^= 1;
		}
	}
	
	int now = 0;
	
	for(int i = 0; i < 16; i++) now |= (1 << i) * cnt[i];
	
	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	ans += dfs(now);
	
	printf("%d\n", ans);
	return 0;
}