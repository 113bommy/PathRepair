#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007ll;
long long coeff[200010] = {0}, a[200010], f[200010], inv[200010];
long long exp(long long b, long long e) {
  long long ret = 1;
  while (e > 0) {
    if (e & 1) ret = (ret * b) % mod;
    b = (b * b) % mod;
    e = (e >> 1);
  }
  return ret;
}
long long C(long long n, long long r) {
  return (((f[n] * inv[r]) % mod) * inv[n - r]) % mod;
}
int main() {
  long long n, m, r;
  f[0] = f[1] = inv[0] = inv[1] = 1ll;
  for (int i = 2; i < 200010; ++i) {
    f[i] = (f[i - 1] * i) % mod;
    inv[i] = exp(f[i], mod - 2);
  }
  scanf("%lld", &n);
  for (int i = 1; i <= n; ++i) scanf("%lld", &a[i]);
  if ((n & 3) == 1) {
    for (int i = 1; i <= n; ++i) {
      if (i & 1)
        coeff[i] = C((n >> 1), (i >> 1));
      else
        coeff[i] = 0;
    }
  } else if ((n & 3) == 2) {
    for (int i = 1; i <= n; ++i) {
      if (i & 1)
        coeff[i] = C((n >> 1) - 1, (i >> 1));
      else
        coeff[i] = coeff[i - 1];
    }
  } else if ((n & 3) == 3) {
    for (int i = 1; i < n; ++i) {
      if (i & 1)
        coeff[i] = C(((n - 2) >> 1), (i >> 1));
      else
        coeff[i] = coeff[i - 1];
    }
    coeff[n] = 0;
    m = 1;
    long long prv = 1;
    for (int i = 2; i <= n; ++i) {
      long long t = coeff[i];
      coeff[i] = (coeff[i] + m * prv + mod) % mod;
      prv = t;
      m = -m;
    }
  } else {
    long long t = (n >> 1) - 1;
    for (int i = 1; i <= n; ++i) {
      if (i & 1)
        coeff[i] = C(t, (i >> 1));
      else
        coeff[i] = mod - coeff[i - 1];
    }
  }
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += (coeff[i] * a[i]) % mod;
    if (ans >= mod) ans -= mod;
  }
  printf("%lld\n", ans);
  return 0;
}
