#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int mod = 998244353;
inline int read() {
  int x = 0;
  char ch = getchar();
  while (ch < '0' || ch > '9') ch = getchar();
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  return x;
}
int n;
long long fac[N], inv[N], f[N];
long long qp(long long x, long long k) {
  long long res = 1;
  while (k) {
    if (k & 1) res = res * x % mod;
    k >>= 1, x = x * x % mod;
  }
  return res;
}
long long c(int n, int m) {
  if (n < m || n < 0 || m < 0) return 0;
  return fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main() {
  n = read();
  fac[0] = inv[0] = inv[1] = 1;
  for (register int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  for (register int i = 2; i <= n; i++)
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  for (register int i = 3; i <= n; i++) inv[i] = inv[i - 1] * inv[i] % mod;
  long long ans = 0, res = 0;
  for (register int i = 1; i <= n; i++) {
    if ((i - 1) & 1)
      (res += mod - c(n, i) * qp(3, 1LL * n * n - 1LL * n * i + i) % mod) %=
          mod;
    else
      (res += c(n, i) * qp(3, 1LL * n * n - 1LL * n * i + i) % mod) %= mod;
  }
  (ans += 2 * res % mod) %= mod;
  res = 0;
  for (register int i = 1; i <= n; i++) {
    long long inv = (mod - qp(qp(3, n - i), mod - 2)) % mod;
    long long tmp = (qp((inv + 1) % mod, n) + mod - 1) % mod;
    if ((i - 1) & 1) tmp = (mod - tmp) % mod;
    (res += tmp * c(n, i) % mod * qp(3, 1LL * n * n - 1LL * n * i + 1) % mod) %=
        mod;
  }
  (ans += res) %= mod;
  printf("%lld", ans);
}
