#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int mod = 1e9 + 7;
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
const int INF = 0x3f3f3f3f;
using namespace std;
int n, m, a, b;
long long fac[maxn], inv[maxn];
long long expmod(long long a, long long b) {
  if (b < 0) b = -b;
  long long res = 1;
  while (b) {
    if (b & 1) res = res * a % mod;
    a = a * a % mod;
    b = b >> 1;
  }
  return res;
}
int main() {
  fac[0] = 1;
  for (int i = 1; i < maxn; i++) fac[i] = fac[i - 1] * i % mod;
  inv[maxn - 1] = expmod(fac[maxn - 1], mod - 2);
  for (int i = maxn - 2; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % mod;
  scanf("%d %d %d %d", &n, &m, &a, &b);
  long long ans = 0;
  for (int i = 1; i <= n - 1; i++) {
    long long cnt1 = fac[m - 1] * inv[i - 1] % mod * inv[m - i] % mod;
    long long cnt2 = fac[n - 2] * inv[n - i - 1] % mod;
    long long cnt3 = expmod(m, n - i - 1) % mod;
    long long cnt4 =
        (i + 1) *
        (n - i - 2 >= 0 ? expmod(n, n - i - 2)
                        : expmod(expmod(n, -(n - i - 2)), mod - 2)) %
        mod;
    ans = (ans + cnt1 % mod * cnt2 % mod * cnt3 % mod * cnt4 % mod) % mod;
    ;
  }
  printf("%lld\n", ans);
  return 0;
}
