#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long long mod = 1000000007;
long long dp[1001][1001];
int main() {
  scanf("%d %d %d", &n, &m, &k);
  int l = max(n, m);
  for (int i = 1; i <= n; i++) dp[i][0] = 1;
  for (int i = 1; i <= k; i++) {
    for (int j = 2; j <= l; j++) {
      dp[j][i] = 2 * dp[j - 1][i] - dp[j - 2][i] + dp[j - 2][i - 1] + mod;
      dp[j][i] %= mod;
    }
  }
  printf("%lld", (dp[n][k] * dp[m][k]) % mod);
  return 0;
}
