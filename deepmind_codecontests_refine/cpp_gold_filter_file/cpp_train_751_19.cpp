#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
int a[5000005];
long long f[10000100], Inv[10000100];
inline long long qpow(long long x, int k, long long r = 1) {
  for (; k; k >>= 1, x = x * x % mod)
    if (k & 1) r = r * x % mod;
  return r;
}
int main() {
  int n, s = 0;
  scanf("%d", &n);
  if (n == 1) return puts("0"), 0;
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]), s += a[i];
  for (int i = (Inv[1] = 1, 2); i <= s; ++i)
    Inv[i] = (mod - mod / i) * Inv[mod % i] % mod;
  for (int i = (f[0] = n - 1, 1); i < s; ++i)
    f[i] = (i * f[i - 1] + s) % mod * (n - 1) % mod * Inv[s - i] % mod;
  for (int i = s - 1; ~i; --i) (f[i] += f[i + 1]) %= mod;
  long long sum = -(n - 1) * f[0] % mod;
  for (int i = 1; i <= n; ++i) (sum += f[a[i]]) %= mod;
  printf("%lld\n", (sum + mod) * qpow(n, mod - 2) % mod);
  return 0;
}
