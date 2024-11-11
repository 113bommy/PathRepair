#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000011, p = 1000000007;
int n, k;
void init() { scanf("%d%d", &n, &k); }
int Fact[maxn], f[maxn], ny[maxn];
void work() {
  Fact[0] = 1;
  for (int i = 1; i <= n; ++i) Fact[i] = 1LL * Fact[i - 1] * i % p;
  ny[1] = 1;
  for (int i = 2; i <= n; ++i) ny[i] = 1LL * (p - p / i) * ny[p % i] % p;
  f[-1] = 0;
  f[0] = 1;
  for (int i = 1; i <= k; ++i) f[i] = (f[i - 1] + 1) % p;
  for (int i = k + 1; i <= n; ++i)
    f[i] = (f[i - 1] + 1LL * ny[i] * (f[i - 1] - f[i - k - 1])) % p;
  long long ans = 0;
  for (int i = k + 1; i < n; ++i)
    ans = (ans + 1LL * Fact[n - 1] * (n - i) % p * ny[i] % p *
                     (f[i - k - 1] - f[i - k - 2])) %
          p;
  ans = (ans % p + p) % p;
  printf("%lld\n", ans);
}
int main() {
  init();
  work();
  return 0;
}
