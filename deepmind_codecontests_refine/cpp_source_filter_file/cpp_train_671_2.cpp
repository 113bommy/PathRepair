#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
const int inf = 0x3f3f3f3f;
const long long INF = 0x3f3f3f3f3f3f3f3f;
const int mod = 1e9 + 7;
long long inv[N], f[N], finv[N];
long long a[N], sum[N], Pow[N];
int n, k;
void init() {
  inv[1] = f[0] = finv[0] = Pow[0] = 1;
  for (int i = 2; i < N; i++) inv[i] = (mod - mod / i) * inv[mod % i] % mod;
  for (int i = 1; i < N; i++) f[i] = f[i - 1] * i % mod;
  for (int i = 1; i < N; i++) finv[i] = finv[i - 1] * inv[i] % mod;
  for (int i = 1; i < N; i++) Pow[i] = Pow[i - 1] * 10 % mod;
}
long long comb(int n, int m) {
  if (n < m || n < 0) return 0;
  return f[n] * finv[m] % mod * finv[n - m] % mod;
}
int main() {
  init();
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%1lld", &a[i]);
    sum[i] = (sum[i - 1] + a[i]) % mod;
  }
  long long ans = 0;
  for (int i = 0; i <= n - 2; i++) {
    ans = (ans + sum[n - i - 1] * Pow[i] % mod * comb(n - 2 - i, k - 1) % mod) %
          mod;
    ans = (ans + a[n - i] * Pow[i] % mod * comb(n - 1 - i, k) % mod) % mod;
  }
  printf("%lld\n", ans);
  return 0;
}
