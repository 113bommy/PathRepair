#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 9;
long long n, f[1000010], g[1000010], p = 1;
int main() {
  scanf("%lld", &n);
  f[0] = 0, f[1] = 2, g[1] = 4;
  for (int i = 2; i <= n; i++) g[i] = (g[i - 1] * 2 + 4) % mod;
  for (int i = 2; i <= n - 2; i++) {
    if (i & 1)
      f[i] = (2 * p % mod + f[i - 1] + 2 * g[i / 2] * p % mod) % mod;
    else
      f[i] = (2 * p % mod + f[i - 1] + 2 * g[0] * p % mod) % mod;
    if (i & 1) p = p * (g[i / 2] + 1) % mod;
  }
  printf("%lld\n",
         (2 * f[n - 2] * f[n - 2] % mod + 8 * f[n - 2] % mod + 10) % mod);
}
