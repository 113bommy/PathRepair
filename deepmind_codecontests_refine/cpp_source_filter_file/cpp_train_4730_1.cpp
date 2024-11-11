#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
const int maxm = 1e3 + 5;
const int mod = 1e9 + 7;
long long C[maxm][maxm], fac[maxm], f[maxm][maxm];
inline void init() {
  fac[0] = 1;
  for (int i = 1; i < maxm - 4; i++) fac[i] = fac[i - 1] * i % mod;
  C[0][0] = 1;
  for (int i = 1; i < maxm - 4; i++) {
    C[i][0] = C[i][i] = 1;
    for (int j = 1; j < i; j++) {
      C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
    }
  }
  f[0][0] = 1;
  for (int i = 1; i < maxm - 4; i++) {
    for (int j = 1; j < i + 1; j++)
      f[i][j] = (f[i - j][j] + f[i - j][j - 1]) % mod;
  }
}
inline void solve() {
  int n, k;
  scanf("%d%d", &n, &k);
  long long ans = 0;
  for (int len = k * (k + 1) / 2; len < n + 1; len++)
    ans = (ans + f[len][k] * C[n - len + k][k]) % mod;
  printf("%lld\n", ans * fac[k]);
}
int main() {
  init();
  int t;
  scanf("%d", &t);
  while (t--) solve();
  return 0;
}
