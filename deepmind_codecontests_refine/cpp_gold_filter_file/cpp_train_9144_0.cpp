#include <cstdio>
#include <algorithm>

#define Rep(i, n) for (int i = 1; i <= n; i ++)
#define Rep0(i, n) for (int i = 0; i <= n; i ++)

using namespace std;

typedef long long LL;
const int N = 100010;

int t[N * 8];
int num = 0;
void build(int x, int l, int r)
{
	t[x] = 2e9;
	if (l == r) return;
	int mid = (l + r) >> 1;
	build(x << 1, l, mid); build(x << 1 | 1, mid + 1, r);
}
void modify(int x, int l, int r, int a, int b, int c)
{
	if (a > b) return;
	if (a <= l && r <= b){ t[x] = c; return;}
	int mid = (l + r) >> 1;
	if (a <= mid) modify(x << 1, l, mid, a, b, c);
	if (b > mid) modify(x << 1 | 1, mid + 1, r, a, b, c);
}
int query(int x, int l, int r, int a)
{
	int ret = t[x];
	if (l == r) return ret;
	int mid = (l + r) >> 1;
	if (a <= mid) ret = min(ret, query(x << 1, l, mid, a));
	else ret = min(ret, query(x << 1 | 1, mid + 1, r, a));
	return ret;
}

int b[N], cnt;
LL L[N], R[N], s[N], f[N], a[N], h[N];
int main()
{
	
	int n, k;
	scanf("%d%d", &n, &k);
	Rep(i, n) scanf("%lld%d", &a[i], &b[i]);
	Rep(i, n){
		if (b[i] == 1 && a[i] * 2 > k) { printf("-1\n"); return 0;}
		a[i] += a[i - 1], s[i] = a[i] % k;
		if (b[i] == 1){
			L[i] = ((-s[i - 1] * 2) % k + k) % k, h[++ cnt] = L[i];
			R[i] = ((-s[i] * 2) % k + k) % k, h[++ cnt] = R[i];
		}
	}
	h[++ cnt] = 0, h[++ cnt] = k - 1;
	sort(h + 1, h + 1 + cnt);
	cnt = unique(h + 1, h + 1 + cnt) - h - 1;
	Rep(i, n) if (b[i] == 1) {
		L[i] = lower_bound(h + 1, h + 1 + cnt, L[i]) - h;
		R[i] = lower_bound(h + 1, h + 1 + cnt, R[i]) - h;
	}
	build(1, 1, cnt);//printf("%d\n", cnt);
	for (int i = n; i; i --) if (b[i] == 1) {
		int tmp = query(1, 1, cnt, L[i]);
		if (tmp != 2e9) f[i] = f[tmp] + (h[L[tmp]] - h[L[i]] + k) % k;
		else f[i] = 0;
		if (L[i] <= R[i]){
			modify(1, 1, cnt, 1, L[i] - 1, i);
			modify(1, 1, cnt, R[i] + 1, cnt, i);
		}
		else modify(1, 1, cnt, R[i] + 1, L[i] - 1, i);
	}
	LL ans = 1e18;
	Rep(i, n) if (b[i] == 1){
		int tmp = query(1, 1, cnt, L[i]);
		if (tmp != 2e9) ans = min(ans, f[tmp] + (h[L[tmp]] - h[L[i]] + k) % k); 
		else ans = 0;
		tmp = query(1, 1, cnt, R[i]);
		if (tmp != 2e9) ans = min(ans, f[tmp] + (h[L[tmp]] - h[R[i]] + k) % k);
		else ans = 0;
	}
	
	printf("%lld\n", ans + a[n] * 2);
	
	return 0;
}