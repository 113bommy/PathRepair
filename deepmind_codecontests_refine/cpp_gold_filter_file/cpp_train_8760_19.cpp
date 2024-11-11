#include <bits/stdc++.h>
const long long N = 1000005, INF = 0x3f3f3f3f3f3f3f3fll;
long long n, m, w, a[N], l, r;
struct twt {
  long long l, r, sum;
  std::vector<long long> c;
} t[4 * N];
void pushup(long long p) {
  t[p].sum = t[p + p].sum + t[p + p + 1].sum;
  long long y = 0;
  for (long long x = 0; x <= t[p + p].r - t[p + p].l + 1; x++) {
    if (y > t[p + p + 1].r - t[p + p + 1].l + 1) y--;
    for (; y <= t[p + p + 1].r - t[p + p + 1].l + 1; y++) {
      long long res = t[p + p + 1].c[y] + x * w - t[p + p].sum;
      long long max = t[p + p].c[x + 1] - 1 - x * w + t[p + p].sum;
      if (max < t[p + p + 1].c[y]) {
        if (y > 0) y--;
        break;
      }
      t[p].c[x + y] = std::min(t[p].c[x + y], std::max(t[p + p].c[x], res));
    }
  }
}
long long Query(long long p, long long l, long long r, long long x) {
  if (t[p].l == l && t[p].r == r) {
    long long pos =
        std::upper_bound(t[p].c.begin(), t[p].c.end(), x) - t[p].c.begin() - 1;
    return x + t[p].sum - w * pos;
  }
  long long mid = t[p].l + (t[p].r - t[p].l) / 2;
  if (r <= mid)
    return Query(p + p, l, r, x);
  else if (l > mid)
    return Query(p + p + 1, l, r, x);
  else
    return Query(p + p + 1, mid + 1, r, Query(p + p, l, mid, x));
}
void build(long long p, long long l, long long r) {
  t[p].l = l, t[p].r = r;
  for (long long i = 0; i <= t[p].r - t[p].l + 2; i++) t[p].c.push_back(INF);
  t[p].c[0] = -INF;
  if (l == r) {
    t[p].sum = a[l];
    t[p].c[1] = w - a[l];
    return;
  }
  long long mid = l + (r - l) / 2;
  build(p + p, l, mid);
  build(p + p + 1, mid + 1, r);
  pushup(p);
}
signed main() {
  scanf("%lld%lld%lld", &n, &m, &w);
  for (long long i = 1; i <= n; i++) scanf("%lld", &a[i]);
  build(1, 1, n);
  for (long long i = 1; i <= m; i++) {
    scanf("%lld%lld", &l, &r);
    printf("%lld\n", Query(1, l, r, 0));
  }
  return 0;
}
