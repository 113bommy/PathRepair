#include <bits/stdc++.h>
using namespace std;
int arr[2000];
int dp[2000][2000];
int main() {
  int t, n, k;
  cin >> t;
  for (int g = 0; g < t; g++) {
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i <= n; i++)
      for (int j = 0; j <= n; j++) {
        if (j > i)
          dp[i][j] = -1000000;
        else
          dp[i][j] = 0;
      }
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= i; j++) {
        dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]);
        if (arr[i - 1] == j) dp[i][j] = max(dp[i - 1][j - 1] + 1, dp[i - 1][j]);
      }
    int ans = -1;
    for (int i = 0; i <= n; i++) {
      if (dp[n][n - i] >= k) {
        ans = i;
        break;
      }
    }
    cout << ans << endl;
  }
}
