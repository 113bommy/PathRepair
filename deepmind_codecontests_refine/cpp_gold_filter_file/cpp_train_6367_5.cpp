#include <bits/stdc++.h>
#pragma GCC optimize(3, "Ofast", "inline")
using namespace std;
mt19937 rng_32(chrono::steady_clock::now().time_since_epoch().count());
const int mod = 1e9 + 7;
const int seed = 233;
const double PI = acos(-1.0);
const double eps = 1e-7;
const int inf = 0x3f3f3f3f;
const int max_n = 1000005;
namespace {
inline int Add(int x, int y) { return (x += y) >= mod ? x - mod : x; }
inline int Sub(int x, int y) { return (x -= y) < 0 ? x + mod : x; }
inline int Mul(int x, int y) { return 1ll * x * y % mod; }
inline int Pow(int x, int y = mod - 2) {
  int res = 1;
  while (y) {
    if (y & 1) res = 1ll * res * x % mod;
    x = 1ll * x * x % mod;
    y >>= 1;
  }
  return res;
}
}  // namespace
long long f[max_n * 2];
long long inv[max_n * 2];
long long invn[max_n * 2];
long long C(int n, int m) {
  if (n < m || m < 0) return 0;
  return f[n] * inv[n - m] % mod * inv[m] % mod;
}
long long A(int n, int m) {
  if (n < m || m < 0) return 0;
  return f[n] * inv[n - m] % mod;
}
void init(int n) {
  f[0] = 1;
  for (int i = 1; i <= n; i++) f[i] = f[i - 1] * i % mod;
  inv[n] = Pow(f[n]);
  for (int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
  invn[1] = 1;
  for (int i = 2; i <= n; i++) invn[i] = invn[mod % i] * (mod - mod / i) % mod;
}
int n;
int c[22];
int b[22];
int main() {
  scanf("%d", &n);
  init(max_n - 1);
  long long ans = 0;
  for (int i = 20; i >= 0; i--) {
    c[i] = n / (1 << i);
  }
  for (int i = 0; i <= 20; i++) c[i] -= c[i + 1];
  int mx;
  for (int i = 20; i >= 0; i--) {
    if (c[i] != 0) {
      mx = i;
      break;
    }
  }
  long long res = 1;
  int m = n - 1;
  for (int i = mx - 1; i >= 0; i--) {
    res *= C(c[i], 1) * A(m - 1, c[i] - 1) % mod;
    res %= mod;
    m -= c[i];
  }
  ans = res;
  if (mx >= 1 && 3 * (1 << (mx - 1)) <= n) {
    for (int j = mx - 1; j >= 0; j--) {
      int m = n - 1;
      long long res = 1;
      for (int i = mx - 1; i >= 0; i--) {
        if (i > j) {
          int x = n / (3 * (1 << i));
          int y = n / (3 * (1 << (i - 1)));
          y -= x;
          res *= C(y, 1) * A(m - 1, y - 1) % mod;
          res %= mod;
          m -= y;
        } else if (i == j) {
          int x = n / (3 * (1 << (i)));
          int y = n / (1 << (i));
          y -= x;
          res *= C(y, 1) * A(m - 1, y - 1) % mod;
          res %= mod;
          m -= y;
        } else {
          int x = n / (1 << (i + 1));
          int y = n / (1 << i);
          y -= x;
          res *= C(y, 1) * A(m - 1, y - 1) % mod;
          res %= mod;
          m -= y;
        }
      }
      ans += res;
      ans %= mod;
    }
  }
  printf("%lld\n", ans);
}
