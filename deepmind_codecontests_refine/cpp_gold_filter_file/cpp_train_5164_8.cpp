#include <bits/stdc++.h>
const int maxn = 2e5 + 100;
const int MOD = 1e9 + 7;
long long a[maxn];
long long c[maxn / 2];
long long d[maxn];
int n;
void inc(long long &a, long long b) {
  a += b;
  a %= MOD;
}
long long mul(long long a, long long b) {
  long long ans = 0;
  while (b) {
    if (b & 1) inc(ans, a);
    inc(a, a);
    b >>= 1;
  }
  return ans;
}
long long pow_mod(long long a, long long b) {
  long long ans = 1;
  while (b) {
    if (b & 1) ans = mul(ans, a);
    a = mul(a, a);
    b >>= 1;
  }
  return ans;
}
long long inv(long long a) { return pow_mod(a, MOD - 2); }
void init(int x) {
  c[0] = 1;
  for (int i = 0; i < x; i++)
    c[i + 1] = c[i] * (x - i) % MOD * inv(i + 1) % MOD;
}
void solve() {
  if (n == 1) {
    printf("%I64d\n", a[0] % MOD);
    return;
  } else if (n % 4 == 0) {
    init(n / 2 - 1);
    for (int i = 0; i < n; i++) {
      int sgn = i % 2 ? -1 : 1;
      d[i] = sgn * c[i / 2];
    }
  } else if (n % 4 == 1) {
    init(n / 2);
    for (int i = 0; i < n; i++) {
      int sgn = i % 2 ? 0 : 1;
      d[i] = sgn * c[i / 2];
    }
  } else if (n % 4 == 2) {
    init(n / 2 - 1);
    for (int i = 0; i < n; i++) {
      d[i] = c[i / 2];
    }
  } else {
    init((n - 3) / 2);
    {
      d[0] = 1;
      for (int i = 1; i < n / 2; i++) {
        if (i % 2)
          d[i] = 2 * c[i / 2];
        else
          d[i] = c[i / 2] - c[i / 2 - 1];
      }
      d[n / 2] = 2 * c[(n - 3) / 4];
      for (int i = n / 2 + 1; i < n; i++) {
        int sgn = i % 2 ? 1 : -1;
        d[i] = sgn * d[n - i - 1];
      }
    }
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) inc(ans, a[i] * d[i] % MOD);
  ans = ((ans % MOD) + MOD) % MOD;
  printf("%I64d\n", ans);
}
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%I64d", &a[i]);
  solve();
  return 0;
}
