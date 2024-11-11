#include <bits/stdc++.h>
using namespace std;
const int mod = (int)(1e9) + 7;
int fac[200005], ifac[200005];
int qpow(int x, int y) {
  int ret = 1;
  while (y) {
    if (y & 1) ret = (long long)ret * x % mod;
    x = (long long)x * x % mod;
    y >>= 1;
  }
  return ret;
}
int C(int n, int i) {
  return (long long)fac[n] * ifac[i] % mod * ifac[n - i] % mod;
}
int S(int n, int k) {
  int ret = 0, flg;
  for (int i = 0; i <= k; i++) {
    if ((k + i) & 1)
      flg = mod - 1;
    else
      flg = 1;
    ret = (ret + (long long)flg * C(k, i) % mod * qpow(i, n) % mod) % mod;
  }
  ret = (long long)ret * ifac[k] % mod;
  return ret;
}
int w;
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  fac[0] = ifac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = (long long)fac[i - 1] * i % mod;
  for (int i = 1; i <= n; i++) ifac[i] = qpow(fac[i], mod - 2);
  int ans = 0, cf;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &w);
    ans = (ans + w) % mod;
  }
  cf = (S(n, m) + (long long)(n - 1) * S(n - 1, m) % mod) % mod;
  ans = (long long)ans * cf % mod;
  printf("%d", ans);
  return 0;
}
