#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline bool upmin(T &x, T y) {
  return y < x ? x = y, 1 : 0;
}
template <typename T>
inline bool upmax(T &x, T y) {
  return x < y ? x = y, 1 : 0;
}
const long double eps = 1e-11;
const long double pi = acos(-1);
const int oo = 1 << 30;
const long long loo = 1ll << 62;
const int mods = 1e9 + 7;
const int MAXN = 5005;
const int INF = 0x3f3f3f3f;
inline int read() {
  int f = 1, x = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 3) + (x << 1) + (c ^ 48);
    c = getchar();
  }
  return x * f;
}
int a[MAXN], f[MAXN][MAXN], inv[MAXN], fac[MAXN];
int upd(int x, int y) { return x + y >= mods ? x + y - mods : x + y; }
int quick_pow(int x, int y) {
  int ret = 1;
  for (; y; y >>= 1) {
    if (y & 1) ret = 1ll * ret * x % mods;
    x = 1ll * x * x % mods;
  }
  return ret;
}
void Init(int n) {
  fac[0] = 1;
  for (int i = 1; i <= n; i++) fac[i] = 1ll * fac[i - 1] * i % mods;
  inv[n] = quick_pow(fac[n], mods - 2);
  for (int i = n - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mods;
}
signed main() {
  int n = read(), k = read(), mul = 1;
  for (int i = 1; i <= n; i++) a[i] = read(), mul = 1ll * mul * a[i] % mods;
  Init(n), f[0][0] = 1;
  for (int i = 0; i < n; i++)
    for (int j = 0; j <= n; j++)
      f[i + 1][j] = upd(f[i + 1][j], 1ll * a[i + 1] * f[i][j] % mods),
            f[i + 1][j + 1] = upd(f[i + 1][j + 1], mods - f[i][j]);
  int ans = 0;
  for (int i = 0, t = 1, p = 1; i <= n; i++) {
    ans = upd(ans, 1ll * p * t % mods * f[n][i] % mods);
    t = 1ll * t * (k - i) % mods,
    p = 1ll * p * fac[n - 1] % mods * inv[n] % mods;
  }
  printf("%lld\n", (mul + mods - ans) % mods);
  return 0;
}
