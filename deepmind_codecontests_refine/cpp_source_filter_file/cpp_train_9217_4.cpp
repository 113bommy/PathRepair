#include <bits/stdc++.h>
using namespace std;
int dp[1000][1000], a[1000], n;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  memset(dp, 1000, sizeof dp);
  dp[0][0] = 1;
  if (a[0] == 2 || a[0] == 3) dp[0][1] = 0;
  if (a[0] == 1 || a[0] == 3) dp[0][2] = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] == 2 || a[i] == 3) dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
    if (a[i] == 1 || a[i] == 3) dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
    dp[i][0] = min(dp[i - 1][1], min(dp[i - 1][0], dp[i - 1][2])) + 1;
  }
  cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2]));
  return 0;
}
