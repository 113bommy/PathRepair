#include <bits/stdc++.h>
using namespace std;
long long a[5005];
long long val(long long x, long long y) {
  if (a[x] <= a[y])
    return (a[y] - a[x] + 1);
  else
    return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n;
  cin >> n;
  for (long long i = 1; i <= n; i++) cin >> a[i];
  if (n == 1) {
    cout << 0;
    return 0;
  }
  long long k = (n + 1) / 2;
  long long dp[k + 1][n + 1][2];
  for (long long i = 0; i <= k; i++)
    for (long long j = 0; j <= n; j++) {
      dp[i][j][0] = 1e9;
      dp[i][j][1] = 1e9;
    }
  dp[1][1][1] = val(1, 2);
  dp[1][2][0] = dp[1][1][1];
  dp[1][2][1] = val(2, 3) + val(2, 1);
  long long mn = min(dp[1][1][1], dp[1][2][1]);
  for (long long j = 3; j <= n; j++) {
    dp[1][j][1] = val(j, j + 1) + val(j, j - 1);
    dp[1][j][0] = mn;
    mn = min(mn, dp[1][j][1]);
  }
  for (long long i = 2; i <= k; i++)
    for (long long j = (2 * i - 1); j <= n; j++) {
      dp[i][j][0] = min(dp[i][j - 1][0], dp[i][j - 1][1]);
      long long x;
      if (a[j - 1] >= a[j - 2])
        x = a[j - 2] - 1 - a[j] + 1;
      else
        x = a[j - 1] - a[j] + 1;
      if (x < 0) x = 0;
      dp[i][j][1] = min(dp[i - 1][j - 2][1] + val(j, j + 1) + x,
                        dp[i - 1][j - 2][0] + val(j, j + 1) + val(j, j - 1));
    }
  long long ans = 1e9;
  for (long long j = 1; j <= k; j++)
    cout << min(dp[j][n][0], dp[j][n][1]) << " ";
  return 0;
}
