#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
int n;
int x[101], y[101];
int f[101][1010];
int sum[1010];
int fac[1010], e[1010];
int pw(int a, int k) {
  int b = 1;
  while (k) {
    if (k & 1) b = ((long long)b * a) % MOD;
    a = ((long long)a * a) % MOD;
    k >>= 1;
  }
  return b;
}
void init() {
  fac[0] = 1;
  for (int i = 1; i < 1010; i++) fac[i] = ((long long)fac[i - 1] * i) % MOD;
  for (int i = 1; i < 1010; i++) e[i] = pw(fac[i], MOD - 2);
}
int C(int a, int b) {
  if (a - b == 1) return a;
  if (b == 1) return a;
  if (b == 0) return 1;
  if (b == a) return 1;
  return (long long)((long long)fac[a] * e[a - b] % MOD) * e[b] % MOD;
}
int main() {
  init();
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &x[i]);
  for (int i = 0; i < n; i++) scanf("%d", &y[i]);
  sum[0] = x[0];
  for (int i = 1; i < n; i++) sum[i] = sum[i - 1] + x[i];
  for (int i = 0; i <= min(y[0], x[0]); i++) f[0][i] = C(sum[0], i);
  for (int i = 1; i < n; i++)
    for (int j = 0; j <= sum[i]; j++)
      for (int k = 0; k <= min(y[i], j); k++)
        f[i][j] = (f[i][j] +
                   (long long)f[i - 1][j - k] * C(sum[i] - (j - k), k) % MOD) %
                  MOD;
  int ans = f[n - 1][sum[n - 1]];
  cerr << "ans"
       << "=" << ans << '\n';
  for (int i = 0; i < n; i++)
    ans = (long long)ans * C(sum[n - 1] - sum[i - 1], x[i]) % MOD;
  printf("%d\n", ans);
  return 0;
}
