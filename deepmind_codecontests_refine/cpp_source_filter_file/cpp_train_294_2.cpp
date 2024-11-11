#include <bits/stdc++.h>

#define maxn 100010
#define cmin(_a, _b) (_a > (_b) ? _a = (_b) : 0)
int a[maxn], q[maxn];
long long f[maxn];
int main()
{
	int n,m,T;
        scanf("%d%d%d",&n,&m,&T);
	for (int i=1;i<=n;++i)scanf("%d",&a[i]);
	int p = 1, h = 0, t = 0;
        long long fp = 1234567891234567ll;
	for (int i = 1; i <= n; ++i)
	{
		while ((a[i] - a[p]) * 2 > T) cmin(fp, f[p - 1] - 2 * a[p]), ++p;
		while (head < tail && (a[i] - a[q[head + 1]]) * 2 > T) ++head;
		f[i] = 1ll * i * T;
		cmin(f[i], fp + 2 * a[i]);
		head < tail ? cmin(f[i], f[q[head + 1] - 1] + T) : 0;
		cmin(f[i], f[i - 1] + T);
		while (head < tail && f[q[tail] - 1] > f[i]) --tail;
		q[++tail] = i;
	}
	printf("%lld\n", f[n] + m);
	return 0;
}