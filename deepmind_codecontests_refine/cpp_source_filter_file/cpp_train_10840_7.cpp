#include <bits/stdc++.h>
int d, m, g[21], n, b[30001];
long long l, r;
struct info {
  std::bitset<30001> pre, suf;
  long long cnt;
  long long len;
  info() {
    pre.reset();
    suf.reset();
    cnt = len = 0;
  }
} f[101][61];
std::bitset<30001> all;
info merge(info a, info b) {
  if (!a.len) return b;
  if (!b.len) return a;
  info c;
  int l = std::max(n - b.len, 1ll), r = std::min(a.len, 1ll * (n - 1));
  c.cnt = a.cnt + b.cnt;
  if (l <= r)
    c.cnt +=
        (((a.suf & b.pre) >> l).count() - ((a.suf & b.pre) >> (r + 1)).count());
  c.len = a.len + b.len;
  c.pre = a.pre;
  if (a.len < n) c.pre &= (b.pre >> a.len) | (all << (n - a.len));
  c.suf = b.suf;
  if (b.len < n) c.suf &= (a.suf << b.len) | (all >> (30000 - b.len));
  return c;
}
info calc(long long len, int pre) {
  if (!len) return info();
  long long x = 1, p = 0;
  while (x <= len) x *= d, ++p;
  x /= d, --p;
  info ans;
  for (; len;) {
    int t = -1;
    for (long long i = 1; i * x <= len; i++) {
      ans = merge(ans, f[p][(pre + g[i]) % m]);
      t = i;
    }
    (pre += g[t + 1]) %= m;
    len %= x;
    x /= d, --p;
  }
  return ans;
}
int main() {
  scanf("%d%d", &d, &m);
  for (int i = 1; i <= d; i++) scanf("%d", g + i);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", b + i);
  scanf("%lld%lld", &l, &r);
  all.set();
  for (int i = 0; i < m; i++) {
    f[0][i].len = 1;
    f[0][i].cnt = (n == 1 && i == 0);
    for (int j = 1; j < n; j++) {
      if (i <= b[n - j + 1] && j < n) f[0][i].pre.set(n - j);
      if (i <= b[j] && j) f[0][i].suf.set(j);
    }
  }
  for (long long i = 1, Mul = 1; Mul <= r; Mul *= d, i++) {
    for (int j = 0; j < m; j++) {
      f[i][j] = f[i - 1][j];
      for (int k = 2; k <= d; k++)
        f[i][j] = merge(f[i][j], f[i - 1][(j + g[k]) % m]);
    }
  }
  printf("%lld\n", calc(r, 0).cnt - calc(l + n - 2, 0).cnt);
}
