#include <bits/stdc++.h>
using namespace std;
struct node {
  long long lp, rp;
  node(long long nlp = 0, long long nrp = 0) {
    lp = nlp;
    rp = nrp;
  }
} b[400005];
long long n, T, m, k, a[400005], cnt = 0, x, hd, tot = 0, mx;
long long ans = 0, pre, l, r, mid, pl, pr, sum;
long long dow(long long x, long long y) { return x / y; }
long long up(long long x, long long y) { return x / y + (x % y > 0); }
bool cmp(node a, node b) { return a.lp < b.lp; }
int main() {
  scanf("%lld", &T);
  while (T--) {
    scanf("%lld%lld%lld", &n, &m, &k);
    cnt = tot = 0;
    m++;
    pre = 0;
    k += m;
    for (int i = 1; i < m; i++) {
      scanf("%lld", &x);
      a[i] = x - pre;
      pre = x;
    }
    a[m] = n - pre;
    l = 1;
    r = n + 1;
    while (l < r) {
      mid = (l + r) / 2;
      sum = 0;
      for (int i = 1; i <= m; i++) {
        sum += a[i] / mid;
        if (a[i] / mid == 0) {
          sum = 0;
          break;
        }
      }
      if (sum >= k)
        l = mid + 1;
      else
        r = mid;
    }
    pl = r - 1;
    l = 1;
    r = n + 1;
    while (l < r) {
      mid = (l + r) / 2;
      sum = 0;
      for (int i = 1; i <= m; i++) sum += up(a[i], mid);
      if (sum <= k)
        r = mid;
      else
        l = mid + 1;
    }
    pr = l;
    for (int i = 1; i <= m; i++) {
      if (a[i] / pl >= up(a[i], pr)) continue;
      tot++;
      b[tot] = node(a[i] / up(a[i], pr), up(a[i], a[i] / pl));
    }
    sort(b + 1, b + tot + 1, cmp);
    ans = n + 1;
    mx = r;
    for (int i = 1; i <= tot; i++) {
      ans = min(ans, mx - b[i].lp);
      mx = max(mx, b[i].rp);
    }
    ans = min(ans, mx - l);
    if (!tot) ans = pr - pl;
    printf("%lld\n", ans);
  }
  return 0;
}
