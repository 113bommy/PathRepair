#include <bits/stdc++.h>
using namespace std;
const long long mo = 1000000007;
template <typename _T>
_T Fabs(_T x) {
  return x < 0 ? -x : x;
}
template <typename _T>
void read(_T &x) {
  _T f = 1;
  x = 0;
  char s = getchar();
  while (s > '9' || s < '0') {
    if (s == '-') f = -1;
    s = getchar();
  }
  while ('0' <= s && s <= '9') {
    x = (x << 3) + (x << 1) + (s ^ 48);
    s = getchar();
  }
  x *= f;
}
long long n, fac[200005], inv[200005], f[200005], ans;
long long pow2[200005], inv2[200005], t[200005], T;
long long qkpow(long long a, long long s) {
  long long t = 1;
  while (s) {
    if (s & 1) t = 1ll * a * t % mo;
    a = 1ll * a * a % mo;
    s >>= 1;
  }
  return t;
}
void init() {
  inv[0] = fac[0] = f[1] = inv[1] = fac[1] = 1;
  for (int i = 2; i <= n; i++) {
    fac[i] = fac[i - 1] * i % mo;
    f[i] = (mo - mo / i) * f[mo % i] % mo;
    inv[i] = inv[i - 1] * f[i] % mo;
  }
  pow2[0] = inv2[0] = 1;
  for (int i = 1; i <= n; i++) {
    pow2[i] = pow2[i - 1] * 2ll % mo;
    inv2[i] = inv2[i - 1] * f[2] % mo;
  }
}
long long C(long long x, long long y) {
  if (x < 0 || y < 0 || y > x) return 0;
  return fac[x] * inv[y] % mo * inv[x - y] % mo;
}
signed main() {
  read(n);
  read(T);
  init();
  long long now = n, val = 1;
  for (int i = 1; i <= n; i++) read(t[i]), t[i] += t[i - 1];
  for (int i = 1; i <= n; i++) {
    int s = min(n, T - t[i]);
    if (s < 0) break;
    val = (2ll * val - C(i - 1, now) + mo) % mo;
    while (now > s) val = (val - C(i, now) + mo) % mo, now--;
    ans = (ans + val * inv2[i] % mo) % mo;
  }
  printf("%lld\n", (ans + mo) % mo);
  return 0;
}
