#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 9;
const long long Mod = 1e9 + 7;
long long dp[N][N];
long long sum[N][N];
char s[N];
int main() {
  int n, k;
  scanf("%d%d%s", &n, &k, s + 1);
  dp[0][0] = 1;
  sum[0][0] = 1;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= k; ++j) {
      dp[i][j] = sum[i - 1][j] * (s[i] - 'a');
      dp[i][j] %= Mod;
      int pi, pj;
      for (int o = 0;; ++o) {
        pi = i - o - 1;
        pj = j - (o + 1) * (n - i + 1);
        if (pi >= 0 && pj >= 0)
          ;
        else
          break;
        dp[i][j] += dp[pi][pj] * ('z' - s[i]);
        dp[i][j] %= Mod;
      }
      sum[i][j] = sum[i - 1][j] + dp[i][j];
      sum[i][j] %= Mod;
    }
  }
  long long ans = 0;
  for (int i = 0; i <= n; ++i) {
    ans += dp[i][k];
    ans %= Mod;
  }
  cout << ans << endl;
  return 0;
}
