#include <bits/stdc++.h>
using namespace std;
const long long BINF = 9e8, LINF = 2e9, mod = 998244353, P = 179,
                Q = 1791791791;
const long long MAXN = 3600;
long long fact[MAXN], finv[MAXN];
long long fa[3][MAXN / 2 + 4];
long long fb[3][MAXN / 2 + 4];
long long pow(long long a, long long p) {
  if (!p) return 1;
  if (p & 1) return pow(a, p ^ 1) * a % mod;
  long long ans = pow(a, p >> 1);
  return ans * ans % mod;
}
long long inv(long long a) { return pow(a, mod - 2); }
long long cnk(long long n, long long k) {
  if (k < 0 || k > n)
    return 0;
  else
    return fact[n] * finv[k] % mod * finv[n - k] % mod;
}
long long av[MAXN];
long long bv[MAXN];
void solve() {
  fa[0][0] = 1;
  fb[0][0] = 1;
  fa[1][0] = 1;
  fb[1][0] = 1;
  long long h, w, n;
  cin >> h >> w >> n;
  long long nh = h - n;
  long long nw = w - n;
  for (long long i = 0; i < n; ++i) {
    long long a, b, c, d;
    cin >> a >> b >> c >> d;
    av[a - 1] = 1;
    av[c - 1] = 1;
    bv[b - 1] = 1;
    bv[d - 1] = 1;
    if (a != c)
      --nh;
    else
      --nw;
  }
  for (long long i = 2; i <= h; ++i)
    for (long long k = 0; k < h / 2 + 2; ++k) {
      fa[i % 3][k] = fa[(i - 1) % 3][k];
      if (!(av[i - 1] + av[i - 2]) && k) fa[i % 3][k] += fa[(i - 2) % 3][k - 1];
      if (fa[i % 3][k] >= mod) fa[i % 3][k] -= mod;
    }
  for (long long i = 2; i <= w; ++i)
    for (long long k = 0; k < w / 2 + 2; ++k) {
      fb[i % 3][k] = fb[(i - 1) % 3][k];
      if (!(bv[i - 1] + bv[i - 2]) && k) fb[i % 3][k] += fb[(i - 2) % 3][k - 1];
      if (fb[i % 3][k] >= mod) fb[i % 3][k] -= mod;
    }
  fact[0] = 1;
  for (long long i = 1; i < MAXN; ++i) fact[i] = fact[i - 1] * i % mod;
  for (long long i = 0; i < MAXN; ++i) finv[i] = inv(fact[i]);
  long long ans = 0;
  for (long long a = 0; a < MAXN; ++a)
    for (long long b = 0; b < MAXN; ++b)
      if (a * 2 + b <= nh && b * 2 + a <= nw)
        ans = (ans + cnk(nh - 2 * a, b) * cnk(nw - 2 * b, a) % mod *
                         fa[h % 3][a] % mod * fb[w % 3][b] % mod * fact[a] %
                         mod * fact[b]) %
              mod;
  cout << ans;
  return;
}
signed main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
