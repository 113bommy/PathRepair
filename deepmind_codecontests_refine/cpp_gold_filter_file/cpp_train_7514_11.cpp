#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long n, m, p, q, c[2][3605], f[2][3605][3605], fac[3605], ifac[3605], ans;
bool vis[2][3605];
void upd(long long &x, long long y) { x = (x + y) % mod; }
long long inv(long long x) {
  return x == 1 ? 1 : (mod - mod / x) * inv(mod % x) % mod;
}
long long C(long long x, long long y) {
  return x < y || y < 0 ? 0 : fac[x] * ifac[y] % mod * ifac[x - y] % mod;
}
int main() {
  scanf("%lld%lld%lld", &n, &m, &q);
  for (long long i = 1; i <= q; ++i) {
    long long xa, ya, xb, yb;
    scanf("%lld%lld%lld%lld", &xa, &ya, &xb, &yb);
    if (xa == xb) {
      c[0][yb] = 1;
      ++c[0][0];
      vis[0][ya] = vis[0][yb + 1] = vis[1][xa] = vis[1][xa + 1] = 1;
    } else {
      c[1][xb] = 1;
      ++c[1][0];
      vis[1][xa] = vis[1][xb + 1] = vis[0][ya] = vis[0][ya + 1] = 1;
    }
  }
  p = max(n, m);
  fac[0] = 1;
  for (long long i = 1; i <= p; ++i) fac[i] = fac[i - 1] * i % mod;
  ifac[p] = inv(fac[p]);
  for (long long i = p - 1; ~i; --i) ifac[i] = ifac[i + 1] * (i + 1) % mod;
  for (long long op : {0, 1}) {
    long long len = op ? n : m;
    f[op][0][0] = 1;
    for (long long i = 1; i <= len; ++i) {
      for (long long j = 0; j <= i / 2; ++j) {
        if (i > 1 && !vis[op][i]) {
          upd(f[op][i][j], f[op][i - 2][j - 1]);
        }
        if (!c[op][i]) {
          upd(f[op][i][j], f[op][i - 1][j]);
        }
      }
    }
  }
  for (long long i = c[0][0]; i * 2 <= m; ++i) {
    for (long long j = c[1][0]; j * 2 <= n; ++j) {
      upd(ans,
          f[0][m][i] * f[1][n][j] % mod * C(n - j * 2 - c[0][0], i - c[0][0]) %
              mod * fac[i - c[0][0]] % mod *
              C(m - i * 2 - c[1][0], j - c[1][0]) % mod * fac[j - c[1][0]]);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
