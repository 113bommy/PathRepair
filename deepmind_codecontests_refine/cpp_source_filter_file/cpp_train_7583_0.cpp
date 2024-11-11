#include<cmath>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
const int MAXN = 5005;
const int MAXM = 205;
int a[MAXN][MAXM], suf[MAXN][MAXM], c[MAXM];
int n, m, i, j, k, LG[MAXN];
long long tot, ans, d[MAXN];
inline int get()
{
	char c;
	while ((c = getchar()) < 48 || c > 57);
	int res = c - 48;
	while ((c = getchar()) >= 48 && c <= 57)
	res = res * 10 + c - 48;
	return res;
}
int main()
{
	LG[0] = -1;
	for(i = 1; i <= 5000; i ++)
		LG[i] = LG[i >> 1] + 1;
	cin >> n >> m;
	for(i = 2; i <= n; i ++)
		d[i] = get(), d[i] += d[i - 1];
	for(i = 1; i <= n; i ++)
		for(j = 1; j <= m; j ++)
			a[i][j] = get(), f[]
	for(i = 1; i <= n; i ++)
	{
		for(j = 1; j <= m; j ++)
			c[j] = 0;
		tot = 0;
		for(j = i; j <= n; j ++)
		{
			for(k = 1; k <= m; k ++)
				if (a[j][k] > c[k]) tot += a[j][k] - c[k], c[k] = a[j][k];
			ans = max(ans, tot - (d[j] - d[i]));
			int tt = 0;
			for(k = 1; k <= m; k ++)
				if (a[i][k] < c[k]) tt ++;
			if (tt == m) break;
		}
	}
	cout << ans << endl;
}