#include <bits/stdc++.h>
const long long mod = 998244353;
const long long N = 301000;
long long n, m, ans;
long long l[N], r[N], a[N], b[N];
long long jie[N], inv[N];
long long cha[N], sum[41][N], s[N];
long long qpow(long long x, long long y) {
  long long base = x % mod, qpowans = 1;
  while (y) {
    if (y & 1) qpowans = qpowans * base % mod;
    base = base * base % mod;
    y >>= 1;
  }
  return qpowans;
}
void pre() {
  jie[0] = jie[1] = 1, inv[0] = inv[1] = 1;
  for (long long i = 2; i <= N - 1000; ++i) jie[i] = jie[i - 1] * i % mod;
  for (long long i = 2; i <= N - 1000; ++i)
    inv[i] = inv[i - 1] * qpow(i, mod - 2) % mod;
  return;
}
long long getC(long long x, long long y) {
  if (x < y || x < 0 || y < 0) return 0;
  return jie[x] * inv[y] % mod * inv[x - y] % mod;
}
inline long long lowbit(long long x) { return x & (-x); }
inline long long read() {
  long long r = 0, w = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') w = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    r = (r << 3) + (r << 1) + (ch ^ 48);
    ch = getchar();
  }
  return r * w;
}
signed main() {
  pre();
  n = read();
  m = read();
  for (long long i = 1; i <= n; ++i) {
    l[i] = read();
    r[i] = read();
    ++cha[l[i]];
    --cha[r[i] + 1];
  }
  for (long long i = 1; i <= m; ++i) a[i] = read(), b[i] = read();
  for (long long i = 1, ssum = 0; i <= n; ++i) {
    ssum += cha[i];
    s[i] = ssum;
  }
  for (long long i = 0; i <= 40; ++i)
    for (long long j = 1; j <= n; ++j) {
      sum[i][j] = (sum[i][j - 1] + getC(s[j] - i, j - i)) % mod;
    }
  for (long long i = 0; i < (1 << m); ++i) {
    long long ll = 1, rr = n;
    std::set<long long> vis;
    for (long long j = 1; j <= m; ++j)
      if ((i >> (j - 1)) & 1) {
        ll = std::max(ll, l[a[j]]);
        rr = std::min(rr, r[a[j]]);
        vis.insert(a[j]);
        ll = std::max(ll, l[b[j]]);
        rr = std::min(rr, r[b[j]]);
        vis.insert(b[j]);
      }
    if (ll > rr) continue;
    long long nowi = i, cnt = 0, cntvis = vis.size(),
              nowsum = (sum[cntvis][rr] - sum[cntvis][ll - 1] + mod) % mod;
    while (nowi) nowi -= lowbit(nowi), ++cnt;
    if (!(cnt & 1))
      ans = (ans + nowsum) % mod;
    else
      ans = (ans - nowsum + mod) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
