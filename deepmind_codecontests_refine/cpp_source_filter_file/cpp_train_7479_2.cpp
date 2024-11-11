#include <bits/stdc++.h>
#define maxn 200010
using namespace std;
typedef long long LL;
LL c[maxn], a[maxn], b[maxn];
int n, k;
int lowbit(int x) { return x & (-x); }
LL query(int x) { LL ret=0; while (x) ret += c[x], x -= lowbit(x); return ret; }
void add(int x) { while (x <= tot) ++c[x], x += lowbit(x); }
int main() {
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]), a[i] -= k;
    for (int i = 1; i <= n; ++i) b[i] = (a[i] += a[i-1]);
    b[n+1] = 0;
    sort(b+1, b+2+n);
    int tot = unique(b+1, b+2+n) - (b+1);

    LL ans=0;
    a[0] = 0;
    for (int i = 0; i <= n; ++i) {
        int p = lower_bound(b+1, b+1+tot, a[i]) - b;
        ans += query(p);
        add(p);
    }
    printf("%lld\n", ans);
    return 0;
}
