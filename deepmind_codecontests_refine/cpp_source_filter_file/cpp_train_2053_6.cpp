#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 3e3 + 10;
long long qpow(long long x, long long k) {
  long long res = 1;
  while (k > 0) {
    if (k & 1) res = res * x % mod;
    x = x * x % mod;
    k >>= 1;
  }
  return res;
}
long long dp[maxn][maxn], sum[maxn][maxn], inv[maxn * 2];
int f[maxn], n, D;
int main() {
  for (int i = 0; i < 2 * maxn; i++) inv[i] = qpow(i - maxn, mod - 2);
  scanf("%d", &n);
  scanf("%d", &D);
  for (int i = 2; i <= n; i++) scanf("%d", &f[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) dp[i][j] = 1;
  for (int i = n; i >= 1; i--)
    for (int j = 1; j <= n; j++) {
      dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
      dp[f[i]][j] = (dp[f[i]][j] * dp[i][j]) % mod;
    }
  long long ans = 0;
  for (int i = 0; i <= n; i++) {
    long long k = 1;
    for (int j = 0; j <= n; j++)
      if (j != i) k = k * (D - j) * inv[i - j + maxn] % mod;
    ans += k * dp[1][i] % mod;
  }
  cout << (ans % mod + mod) % mod << endl;
  return 0;
}
