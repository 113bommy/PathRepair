#include <bits/stdc++.h>
#pragma GCC optimize(4)
using namespace std;
char _buf[100000], *_p1 = _buf, *_p2 = _buf;
inline int gi() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return (f == 1) ? x : -x;
}
inline int max(int a, int b) { return a > b ? a : b; }
inline int min(int a, int b) { return a < b ? a : b; }
const int maxn = 2e5 + 5, mod = 998244353;
int n, k, a[maxn];
int aa, b;
long long inv[maxn], fac[maxn];
inline void init() {}
inline void input() {
  n = gi(), k = gi();
  if (n == 1) {
    printf("0\n");
    exit(0);
  }
  for (int i = 1; i <= n; ++i) a[i] = gi();
  a[n + 1] = a[1];
  for (int i = 1; i <= n; ++i) {
    if (a[i] == a[i + 1])
      aa++;
    else
      b++;
  }
  inv[0] = fac[0] = inv[1] = fac[1] = 1;
  for (int i = 2; i <= 200000; ++i)
    fac[i] = fac[i - 1] * i % mod,
    inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  for (int i = 2; i <= 200000; ++i) inv[i] = inv[i - 1] * inv[i] % mod;
}
inline long long C(int x, int y) {
  if (x < y) return 0;
  return (fac[x] * inv[y] % mod) * inv[x - y] % mod;
}
inline long long qpow(long long x, long long k) {
  long long ret = 1;
  while (k) {
    if (k & 1) ret = (ret * x) % mod;
    x = (x * x) % mod, k >>= 1;
  }
  return ret;
}
inline void solve() {
  long long ans = 0;
  for (int i = 1; i <= b; ++i) {
    long long sum = C(b, b - i) * qpow(k - 2, b - i) % mod;
    long long now = 0;
    if (i % 2 == 0)
      now = qpow(2, i) - C(i, i / 2);
    else
      now = qpow(2, i);
    now = (now + mod) % mod;
    sum = (sum * now) % mod;
    ans += sum * inv[2] % mod;
    ans %= mod;
  }
  ans = (ans * qpow(k, aa)) % mod;
  printf("%lld\n", ans);
}
int main() {
  init();
  input();
  solve();
  return 0;
}
