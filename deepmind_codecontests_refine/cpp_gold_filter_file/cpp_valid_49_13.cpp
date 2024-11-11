#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007ll;
const int N = 14;
long long power(long long a, long long x) {
  long long ans = 1;
  while (x) {
    if (x & 1) ans = ans * a % mod;
    a = a * a % mod;
    x >>= 1;
  }
  return ans;
}
long long inv(long long x) { return power(x, mod - 2); }
long long h[N + 5][1 << N];
long long p[N + 5][N + 5];
long long a[N + 5], f[1 << N];
long long g[1 << N];
int cal(int x) {
  int ans = 0;
  while (x) {
    ans += x & 1;
    x >>= 1;
  }
  return ans;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) p[i][j] = a[i] * inv(a[i] + a[j]) % mod;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j < (1 << n); j++) {
      if (j & (1 << (i - 1))) continue;
      h[i][j] = 1;
      for (int k = 1; k <= n; k++)
        if (j & (1 << (k - 1))) h[i][j] = h[i][j] * p[i][k] % mod;
    }
  long long ans = 0;
  for (int i = 1; i < 1 << n; i++) {
    g[i] = 1;
    for (int j = i & (i - 1); j; j = (j - 1) & i) {
      for (int k = 1; k <= n; k++)
        if ((i & (1 << (k - 1))) && !(j & (1 << (k - 1)))) {
          g[j] = g[j ^ (1 << (k - 1))] * h[k][((1 << n) - 1) ^ i] % mod;
          break;
        }
      f[i] = (f[i] + (mod - f[j]) * g[j] % mod) % mod;
    }
    for (int k = 1; k <= n; k++)
      if ((i & (1 << (k - 1)))) {
        g[0] = g[(1 << (k - 1))] * h[k][((1 << n) - 1) ^ i] % mod;
        break;
      }
    f[i] = (f[i] + g[0]) % mod;
    ans = (ans + f[i] * cal(i) % mod) % mod;
  }
  printf("%lld", ans);
  return 0;
}
