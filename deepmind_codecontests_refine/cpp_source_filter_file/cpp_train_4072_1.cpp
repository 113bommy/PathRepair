#include <bits/stdc++.h>
const int mod = 998244353;
const int N = 3e5 + 5;
using namespace std;
int n, f[N], fac[N], inv[N], mx, a[N], cnt[N];
template <typename T>
inline T read() {
  T x = 0, w = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') w = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * w;
}
int fpow(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = 1ll * x * x % mod)
    if (y & 1) res = 1ll * res * x % mod;
  return res;
}
int C(int n, int m) {
  if (n < m || n < 0 || m < 0) return 0;
  return 1ll * fac[n] * inv[m] % mod * inv[n - m] % mod;
}
int main() {
  n = read<int>();
  for (int i = 1; i <= n; i++)
    a[i] = read<int>(), cnt[a[i]]++, mx = max(mx, a[i]);
  for (int i = 1; i <= mx; i++)
    for (int j = i; j <= mx; j += i) cnt[i] += cnt[j];
  for (int i = (fac[0] = 1); i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mod;
  inv[n] = fpow(fac[n], mod - 2);
  for (int i = n - 1; i >= 0; i--) inv[i] = 1ll * inv[i + 1] * (i + 1) % mod;
  for (int i = 1; i <= 7; i++) {
    for (int j = 0; j <= mx; j++) f[j] = 0;
    for (int j = mx; j >= 1; j--) {
      f[j] = C(cnt[j], i);
      for (int k = 2 * j; k <= mx; k += j) f[j] = (f[j] - f[k] + mod) % mod;
    }
    if (f[1]) {
      printf("%d\n", i);
      return 0;
    }
  }
  puts("-1");
  return 0;
}
