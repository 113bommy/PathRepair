#include <bits/stdc++.h>
struct {
  inline operator int() {
    int x;
    return scanf("%d", &x), x;
  }
  inline operator long long() {
    long long x;
    return scanf("%lld", &x), x;
  }
  template <class T>
  inline void operator()(T &x) {
    x = *this;
  }
  template <class T, class... A>
  inline void operator()(T &x, A &...a) {
    x = *this;
    this->operator()(a...);
  }
} read;
const int maxn = 5050, mod = 998244353;
long long f[maxn][maxn], g[maxn];
long long fac[maxn], ifac[maxn];
inline long long power(long long x, int k) {
  if (k < 0) k += mod - 1;
  long long res = 1;
  while (k) {
    if (k & 1) (res *= x) %= mod;
    (x *= x) %= mod;
    k >>= 1;
  }
  return res;
}
inline long long C(int n, int m) {
  return fac[n] * ifac[m] % mod * ifac[n - m] % mod;
}
inline long long A(int n, int m) { return fac[n] * ifac[n - m] % mod; }
void combinator_init(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * i % mod;
  ifac[n] = power(fac[n], -1);
  for (int i = n; i; i--) ifac[i - 1] = ifac[i] * i % mod;
}
int main() {
  int n = read;
  combinator_init(n);
  f[0][0] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= i; j++)
      f[i][j] = (j * f[i - 1][j] + (i - j + 1) * f[i - 1][j - 1]) % mod;
  for (int i = 1; i <= n; i++) {
    long long ans = 0;
    for (int p = i; p <= n; p++) (ans += A(n, n - p) * f[p][i]) %= mod;
    printf("%lld ", ans);
  }
  puts("");
}
