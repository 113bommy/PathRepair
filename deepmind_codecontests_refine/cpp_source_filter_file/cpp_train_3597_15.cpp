#include <bits/stdc++.h>
using namespace std;
const long long N = (long long)2e5 + 5, mod = (long long)1e9 + 7, M = 3005;
long long pw(long long a, long long b) {
  return b != 0 ? pw(a * a % mod, b >> 1) * (b & 1 ? a : 1) % mod : 1;
}
long long f[N], invf[N], pickp[N], pickn[N], sd[N], dest[N], lp[M], rp[M],
    olp[M], orp[M], lps[M];
long long comb(long long n, long long r) {
  if (n < 0 || r < 0 || n - r < 0) return 0;
  return f[n] * invf[r] % mod * invf[n - r] % mod;
}
long long mul(long long x, long long y) { return x * y % mod; }
long long add(long long x, long long y) { return (x + y + 100 * mod) % mod; }
long long sadd(long long &x, long long y) { return x = add(x, y); }
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  f[0] = invf[0] = 1;
  for (long long i = 1; i < N; ++i)
    f[i] = f[i - 1] * i % mod, invf[i] = pw(f[i], mod - 2);
  long long n, m;
  cin >> n >> m;
  long long pa, pb;
  cin >> pa >> pb;
  for (long long i = 0; i < N; ++i)
    pickp[i] = pw(pa, i) * pw(pw(pb, mod - 2), i) % mod,
    pickn[i] = pw(pb - pa, i) * pw(pw(pb, mod - 2), i) % mod;
  long long k;
  cin >> k;
  for (long long j = 0; j <= k; ++j) {
    dest[j] = comb(k, j) * pickp[j] % mod * pickn[k - j] % mod;
    sadd(sd[j], add(j == 0 ? 0 : sd[j - 1], dest[j]));
  }
  lp[0] = 1;
  rp[m - 1] = 1;
  for (long long d = 0; d < n + 1; ++d) {
    memcpy(olp, lp, sizeof lp);
    memcpy(orp, rp, sizeof rp);
    memset(lp, 0, sizeof lp);
    memset(lps, 0, sizeof lps);
    memset(rp, 0, sizeof rp);
    long long sumrp = 0, all = 0, cur_val = 0;
    for (long long j = 0; j < m; ++j) sadd(all, olp[j]);
    if (d == n) {
      cout << all;
      return 0;
    }
    for (long long j = m - 1; j >= 0; --j) lps[j] = add(lps[j + 1], olp[j]);
    for (long long j = 0; j < m; ++j) {
      sadd(rp[j], -mul(cur_val, dest[m - j - 1]));
      sadd(rp[j], -mul(lps[j + 1], mul(sd[j], dest[m - j - 1])));
      sadd(rp[j], mul(mul(all, sd[j]), dest[m - j - 1]));
      sadd(sumrp, orp[j]);
      sadd(cur_val, mul(sumrp, dest[j + 1]));
    }
    for (long long j = 0; j < m; ++j) {
      lp[j] = rp[m - j - 1];
    }
  }
}
