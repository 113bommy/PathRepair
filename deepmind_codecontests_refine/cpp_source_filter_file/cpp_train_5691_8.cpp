#include <bits/stdc++.h>
const double pi = acos(-1);
const long long inf = 998244353;
using namespace std;
long long read() {
  long long x = 0, f = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
  return f * x;
}
int n, m;
long long ans, s, p[200005], inv[200005], invp[200005];
long long qpow(long long x, long long t) {
  long long s = 1;
  for (; t; t >>= 1, x = ((x) * (x)) % inf)
    if (t & 1) s = s * x % inf;
  return s;
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++) ans += read(), ans %= inf;
  p[0] = p[1] = invp[1] = invp[0] = inv[1] = 1;
  for (int i = 2; i <= m; i++)
    inv[i] = inv[inf % i] * (inf - inf / i) % inf,
    invp[i] = invp[i - 1] * inv[i] % inf, p[i] = p[i - 1] * i % inf;
  for (int k = 0; k <= m; k++) {
    long long t = qpow(m - k, n - 1);
    if (k & 1)
      s += inf - invp[k] * invp[m - k] % inf * t % inf * (m - k) % inf,
          s %= inf;
    else
      s += invp[k] * invp[m - k] % inf * t % inf * (m - k) % inf, s %= inf;
    if (k & 1)
      s += inf - invp[k] * invp[m - k] % inf * t % inf * (n - 1) % inf,
          s %= inf;
    else
      s += invp[k] * invp[m - k] % inf * t % inf * (n - 1) % inf, s %= inf;
  }
  return 0 * printf("%lld\n", ans * s % inf);
}
