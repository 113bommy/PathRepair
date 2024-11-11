#include <bits/stdc++.h>
using namespace std;
int a[105][105], num[105];
long long dp[105][105], f[105][105], pre[105][105];
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> num[i];
    for (int j = 1; j <= num[i]; j++) cin >> a[i][j];
    for (int j = 1; j <= num[i]; j++) pre[i][j] = pre[i][j - 1] + a[i][j];
  }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= num[i]; j++)
      for (int k = 0; k <= j; k++)
        dp[i][j] = max(dp[i][j],
                       pre[i][k] + (pre[i][num[i]] - pre[i][num[i] + k - j]));
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int k = 0; k <= min(j, num[i]); k++)
        f[i][j] = max(f[i][j], f[i - 1][j - k] + dp[i][k]);
  cout << f[n][m];
  return 0;
}
