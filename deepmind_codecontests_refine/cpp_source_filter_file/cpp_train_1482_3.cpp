#include <bits/stdc++.h>
using namespace std;
int n, m, k;
long long res, dp[52][20002], a[52][20002], maxL[20002], maxR[20002];
long long sum(int i, int l, int r) {
  return l <= r ? a[i][r] - a[i][l - 1] : 0;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) cin >> a[i][j], a[i][j] += a[i][j - 1];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; m - j + 1 >= k; j++) {
      long long S = sum(i, j, j + k - 1) + sum(i + 1, j, j + k - 1);
      dp[i][j] =
          max(dp[i][j], max(maxL[max(j - k, 0)], maxR[min(j + k, m - k + 1)])) +
          S;
      for (int l = max(1, j - k + 1); l <= min(j + k - 1, m - k + 1); l++)
        dp[i][j] = max(dp[i][j],
                       S + dp[i - 1][l] - sum(i, max(l, j), min(l, j) + k - 1));
    }
    for (int j = 1; j <= m - k + 1; j++) maxL[j] = max(dp[i][j], maxL[j - 1]);
    for (int j = m - k; j >= 1; j--) maxR[j] = max(dp[i][j], maxR[j + 1]);
  }
  for (int i = 1; i <= m; i++) res = max(res, dp[n][i]);
  cout << res;
  return 0;
}
