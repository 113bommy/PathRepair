#include <bits/stdc++.h>
using namespace std;
int a[309];
int b[309];
int f[309][309];
long long dp[100861];
int n, q, t;
const long long mod = 1000000007;
void DP() {
  int i, j;
  memset(dp, 0, sizeof(dp));
  dp[0] = 1;
  for (i = 1; i <= n; i++) {
    f[i][i] = 1;
    long long v = 0;
    for (j = 1; j <= n; j++)
      if (f[j][i]) v += a[j];
    if (b[i]) {
      for (j = t; j >= v; j--) dp[j] = dp[j - v];
      while (j >= 0) {
        dp[j--] = 0;
      }
    }
    for (j = v; j <= t; j++) {
      (dp[j] += dp[j - v]) %= mod;
    }
  }
  cout << dp[t] << endl;
  ;
}
int main() {
  cin >> n >> q >> t;
  int i;
  for (i = 1; i <= n; i++) cin >> a[i];
  memset(f, 0, sizeof(f));
  memset(b, 0, sizeof(b));
  for (i = 1; i <= q; i++) {
    int u, v;
    cin >> u >> v;
    f[u][v] = 1;
    b[u] = 1;
  }
  int k, j;
  for (k = 1; k <= n; k++)
    for (i = 1; i <= n; i++)
      for (j = 1; j <= n; j++) {
        f[i][j] |= f[i][k] & f[k][j];
      }
  int flag = 0;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) flag |= f[i][j] & f[j][i];
  if (flag) {
    printf("0\n");
  } else
    DP();
  return 0;
}
