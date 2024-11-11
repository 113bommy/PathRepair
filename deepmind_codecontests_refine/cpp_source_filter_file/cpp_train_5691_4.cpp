#include <bits/stdc++.h>
using namespace std;
const int maxn = 200005, mod = 200005;
int n, k, fac[maxn], ifac[maxn];
inline int gi() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int sum = 0;
  while ('0' <= c && c <= '9') sum = sum * 10 + c - 48, c = getchar();
  return sum;
}
inline void inc(int &a, int b) {
  a += b;
  if (a >= mod) a -= mod;
}
inline int fpow(int x, int k) {
  int res = 1;
  while (k) {
    if (k & 1) res = (long long)res * x % mod;
    x = (long long)x * x % mod;
    k >>= 1;
  }
  return res;
}
int main() {
  n = gi();
  k = gi();
  int sum = 0;
  for (int i = 1; i <= n; ++i) inc(sum, gi());
  if (n == 1) return printf("%d\n", sum), 0;
  fac[0] = ifac[0] = ifac[1] = 1;
  for (int i = 1; i <= n; ++i) fac[i] = (long long)fac[i - 1] * i % mod;
  for (int i = 2; i <= n; ++i)
    ifac[i] = (long long)(mod - mod / i) * ifac[mod % i] % mod;
  for (int i = 2; i <= n; ++i) ifac[i] = (long long)ifac[i - 1] * ifac[i] % mod;
  int ans = 0;
  for (int i = 0; i <= k - 1; ++i) {
    if (i & 1)
      ans = (ans -
             (long long)ifac[i] * ifac[k - i - 1] % mod * (k - i + n - 1) %
                 mod * fpow(k - i, n - 2) % mod +
             mod) %
            mod;
    else
      ans = (ans + (long long)ifac[i] * ifac[k - i - 1] % mod *
                       (k - i + n - 1) % mod * fpow(k - i, n - 2)) %
            mod;
  }
  printf("%lld\n", (long long)ans * sum % mod);
  return 0;
}
