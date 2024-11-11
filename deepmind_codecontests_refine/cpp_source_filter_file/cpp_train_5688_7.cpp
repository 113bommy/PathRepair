#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
int n, k, a[5010];
long long c[5010], ans = 0;
long long Pow(long long x, long long y) {
  long long ans = 1;
  for (; y; y >>= 1, x = x * x % mod)
    if (y & 1) ans = ans * x % mod;
  return ans;
}
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  c[0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int j = i; j > 0; j--) c[j] = c[j] * a[i] % mod - c[j - 1];
    c[0] = c[0] * a[i] % mod;
  }
  long long now = Pow(n, k), invn = Pow(n, mod - 2);
  for (int i = 0; i <= min(n, k); i++) {
    (ans += c[i] * now % mod) %= mod;
    now = now * (k - i) % mod * invn % mod;
  }
  printf("%lld\n",
         ((c[0] - ans * Pow(n, 1LL * k * (mod - 2)) % mod) % mod + mod) % mod);
}
