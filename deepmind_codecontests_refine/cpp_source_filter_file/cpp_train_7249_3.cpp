#include <bits/stdc++.h>
using namespace std;
long long x, k, n, q, cnt, Ans, c[10], s[80], mp[1024];
struct node {
  long long pos, w;
  friend bool operator<(node a, node b) { return a.pos < b.pos; }
} t[30];
struct point {
  long long a[80][80];
} base, ans, st;
point mul(point a, point b) {
  point ret = st;
  for (long long i = 1; i <= cnt; i++)
    for (long long j = 1; j <= cnt; j++)
      for (long long k = 1; k <= cnt; k++)
        ret.a[i][k] = min(ret.a[i][k], a.a[i][j] + b.a[j][k]);
  return ret;
}
point qpow(long long k) {
  point ret = st, x = base;
  for (long long i = 1; i <= cnt; i++) ret.a[i][i] = 0;
  while (k) {
    if (k & 1) ret = mul(ret, x);
    x = mul(x, x);
    k >>= 1;
  }
  return ret;
}
signed main() {
  scanf("%lld%lld%lld%lld", &x, &k, &n, &q);
  for (long long i = 1; i <= k; i++) scanf("%lld", &c[i]);
  for (long long i = 1; i <= q; i++) scanf("%lld%lld", &t[i].pos, &t[i].w);
  for (long long i = 1; i < (1 << k); i++) {
    long long tmp = 0;
    for (long long j = 0; j < k; j++)
      if (i & (1 << j)) tmp++;
    if (tmp == x) s[++cnt] = i, mp[i] = cnt;
  }
  for (long long i = 1; i <= cnt; i++)
    for (long long j = 1; j <= cnt; j++)
      base.a[i][j] = st.a[i][j] = ans.a[i][j] = 1e9;
  for (long long i = 1; i <= cnt; i++) {
    if (!(s[i] & 1))
      base.a[i][mp[s[i] >> 1]] = 0;
    else
      for (long long j = 1; j <= k; j++)
        if (!(s[i] & (1 << j))) base.a[i][mp[(s[i] + (1 << j)) >> 1]] = c[j];
  }
  sort(t + 1, t + q + 1);
  ans.a[1][mp[(1 << x) - 1]] = 0;
  long long lst = 1;
  for (long long i = 1; i <= q; i++) {
    if (t[i].pos > n - q) {
      Ans += t[i].w;
      continue;
    }
    ans = mul(ans, qpow(t[i].pos - lst));
    lst = t[i].pos;
    for (long long j = 1; j <= cnt; j++)
      if (s[j] & 1)
        for (long long k = 1; k <= cnt; k++) ans.a[k][j] += t[i].w;
  }
  ans = mul(ans, qpow(n - x + 1 - lst));
  printf("%lld\n", ans.a[1][mp[(1 << x) - 1]] + Ans);
}
