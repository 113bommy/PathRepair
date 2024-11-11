#include <bits/stdc++.h>
using namespace std;
const int MAX = 3001;
int n, k;
long long dp[MAX][MAX];
long long a[MAX];
int main(int argc, char const *argv[]) {
  while (scanf("%d%d", &n, &k) == 2) {
    for (int i = 1; i <= n; ++i) {
      scanf("%d", &a[i]);
    }
    memset(dp, 0, sizeof(dp));
    for (int j = 1; j <= k; ++j) {
      long long maxv = dp[0][j - 1] - a[1];
      for (int i = 1; i <= n; ++i) {
        dp[i][j] = max(dp[i - 1][j], maxv + a[i]);
        maxv = max(maxv, dp[i][j - 1] - a[i + 1]);
      }
    }
    printf("%I64d\n", dp[n][k]);
  }
  return 0;
}
