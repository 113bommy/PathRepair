#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
long long fac[200010], inv[200010];
void init() {
  fac[0] = inv[0] = inv[1] = 1;
  for (long long i = 1; i < 200010; i++) fac[i] = fac[i - 1] * i % mod;
  for (long long i = 2; i < 200010; i++)
    inv[i] = mod - (long long)(mod / i) * inv[mod % i] % mod;
  for (long long i = 1; i < 200010; i++)
    inv[i] = (long long)inv[i - 1] * inv[i] % mod;
}
long long c(long long a, long long b) {
  return fac[a] * inv[b] % mod * inv[a - b] % mod;
}
int main() {
  long long n, m, q, ans = 0, g;
  scanf("%lld%lld%lld", &n, &m, &g);
  init();
  if (n == 0) {
    if (m == 1)
      printf("%d\n", g);
    else
      printf("%d\n", !g);
  } else if (m == 0) {
    if (n % 2)
      printf("0\n");
    else
      printf("%d\n", g);
  } else {
    for (long long i = 1; i <= n; i += 2)
      if (n + m - i - 1 != 0) ans = (ans + c(n + m - i - 1, m - 1)) % mod;
    if (m == 1 && n % 2 == 0) ans++;
    printf("%lld\n",
           g ? ((ans + mod) % mod) : ((c(n + m, n) - ans + mod) % mod));
  }
  return 0;
}
