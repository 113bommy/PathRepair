#include <bits/stdc++.h>
using namespace std;
int n, k, f[257], fac[257], ifac[257], ans;
const long long mod = 1e9 + 7;
int qpow(int x, int y) {
  int tamp = 1;
  while (y) {
    if (y & 1) tamp = 1ll * tamp * x % mod;
    x = 1ll * x * x % mod;
    y >>= 1;
  }
  return tamp;
}
int combination(int n, int m) {
  return 1ll * fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
int main() {
  int n, k;
  cin >> n >> k;
  fac[0] = 1;
  for (int i = 1; i <= n; ++i) {
    f[i] = qpow((qpow(k, i) - qpow(k - 1, i) + mod) % mod, n);
    fac[i] = 1ll * fac[i - 1] * i % mod;
  }
  ifac[n] = qpow(fac[n], mod - 2);
  for (int i = n - 1; i >= 0; --i) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
  for (int i = 0; i <= n; ++i)
    ans = (ans + ((i & 1) ? -1ll : 1ll) * combination(n, i) % mod *
                     qpow(k - 1, 1ll * n * i) % mod * f[n - i] % mod) %
          mod;
  cout << ans << endl;
  return 0;
}
