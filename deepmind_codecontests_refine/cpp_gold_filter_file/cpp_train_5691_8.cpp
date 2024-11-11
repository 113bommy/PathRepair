#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005, mod = 1000000007;
inline int read() {
  int ret, f = 1;
  char c;
  while ((c = getchar()) && (c < '0' || c > '9'))
    if (c == '-') f = -1;
  ret = c - '0';
  while ((c = getchar()) && (c >= '0' && c <= '9'))
    ret = (ret << 3) + (ret << 1) + c - '0';
  return ret * f;
}
long long add(long long x, long long y) {
  return x + y < mod ? x + y : x + y - mod;
}
long long rdc(long long x, long long y) {
  return x - y < 0 ? x - y + mod : x - y;
}
long long qpow(long long x, int y) {
  long long ret = 1;
  while (y) {
    if (y & 1) ret = ret * x % mod;
    x = x * x % mod;
    y >>= 1;
  }
  return ret;
}
int n, m;
long long ans, inv[maxn];
void init() {
  inv[0] = inv[1] = 1;
  for (int i = 2; i <= m; ++i)
    inv[i] = 1LL * (mod - mod / i) * inv[mod % i] % mod;
  for (int i = 2; i <= m; ++i) inv[i] = inv[i - 1] * inv[i] % mod;
}
int main() {
  n = read();
  m = read();
  int x;
  for (int i = 1; i <= n; ++i) {
    x = read();
    ans = add(ans, x);
  }
  if (n == 1) {
    printf("%lld", m == 1 ? ans : 0);
    return 0;
  }
  init();
  long long mul = 0, tmp;
  for (int i = 0; i < m; ++i) {
    tmp = ((i & 1) ? mod - 1 : 1);
    tmp = tmp * qpow(m - i, n - 2) % mod;
    tmp = (tmp * inv[i] % mod) * inv[m - i - 1] % mod;
    tmp = tmp * (m - i + n - 1) % mod;
    mul = add(mul, tmp);
  }
  printf("%lld", ans * mul % mod);
  return 0;
}
