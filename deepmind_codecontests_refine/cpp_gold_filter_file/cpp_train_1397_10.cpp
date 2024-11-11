#include <bits/stdc++.h>
using namespace std;
long long inf1 = 1e18;
int mid = 103000;
int ch(int a) { return a < 0 ? mid - a - 1 : a; }
int ch1(int a) { return a >= mid ? a : mid - a - 1; }
int dp[105][210007];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  int n, k;
  cin >> n >> k;
  int b[n], a[n];
  for (int i = (0); i < (n); i++) cin >> b[i];
  for (int i = (0); i < (n); i++) cin >> a[i];
  for (int i = (0); i < (n); i++) a[i] = b[i] - a[i] * k;
  dp[0][ch(a[0])] = b[0];
  int ans = dp[0][0];
  for (int i = (1); i < (n); i++) {
    dp[i][ch(a[i])] = b[i];
    for (int j = (0); j < (100001); j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      if (dp[i - 1][j] != 0)
        dp[i][ch(j + a[i])] = max(dp[i][ch(j + a[i])], dp[i - 1][j] + b[i]);
    }
    for (int j = (mid); j < (205000); j++) {
      dp[i][j] = max(dp[i][j], dp[i - 1][j]);
      if (dp[i - 1][j] != 0)
        dp[i][ch1(j - a[i])] = max(dp[i][ch1(j - a[i])], dp[i - 1][j] + b[i]);
    }
    ans = max(ans, dp[i][0]);
  }
  ans == 0 ? cout << -1 : cout << ans;
}
