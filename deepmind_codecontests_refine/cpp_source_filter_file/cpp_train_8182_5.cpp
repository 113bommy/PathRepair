#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long SUM = 0, ff = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') ff = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    SUM = (SUM << 3) + (SUM << 1) + (ch ^ 48);
    ch = getchar();
  }
  return SUM * ff;
}
const int N = 2510;
const int M = 100000;
const long long mod = 1000000007;
inline void add(long long &x, long long y) {
  x += y;
  if (x >= mod) x -= mod;
}
inline long long qpow(long long a, long long p) {
  long long res = 1;
  while (p) {
    if (p & 1) res = res * a % mod;
    a = a * a % mod;
    p >>= 1;
  }
  return res;
}
long long n, sum, ans;
long long a[M + 10], f[M + 10];
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read(), sum += a[i];
  f[1] = 1ll * (sum - 1) * (sum - 1) * qpow(sum, mod - 2) % mod;
  f[2] = 1ll * (2 * f[1] % mod + mod - 1) % mod;
  for (int i = 2; i < M; i++)
    f[i + 1] = (1ll * (2 * f[i] % mod - f[i - 1] + mod) % mod -
                1ll * (sum - 1) * qpow(sum - i, mod - 2) % mod + mod) %
               mod;
  for (int i = 1; i <= n; i++) ans = (ans + f[a[i]]) % mod;
  printf("%lld\n", ans);
  return 0;
}
