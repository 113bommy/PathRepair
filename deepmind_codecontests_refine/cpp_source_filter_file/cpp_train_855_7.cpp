#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 20, mod = 998244353;
long long n, m, q, jc[N], inv[N], ans, f;
long long power(long long a, long long b = mod - 2) {
  long long c = 1;
  while (b) {
    if (b & 1) c = c * a % mod;
    a = a * a % mod;
    b = b >> 1;
  }
  return c;
}
long long C(long long x, long long y) {
  return jc[x] * inv[y] % mod * inv[x - y] % mod;
}
int main() {
  scanf("%lld%lld", &n, &m);
  if (m >= n)
    puts("0");
  else {
    jc[0] = 1;
    for (int i = 1; i <= n; i++) jc[i] = jc[i - 1] * i % mod;
    if (!m) return printf("%lld\n", jc[n]), 0;
    inv[n] = power(jc[n]);
    for (int i = n; i; i--) inv[i - 1] = inv[i] * i % mod;
    f = 1;
    q = n - m;
    for (int i = q; i > 0; i--) {
      ans += f * power(i, n) * C(q, i - q) % mod;
      f = -f;
    }
    ans = (ans % mod + mod) % mod;
    printf("%lld\n", ans * 2 * C(n, m) % mod);
  }
  return 0;
}
