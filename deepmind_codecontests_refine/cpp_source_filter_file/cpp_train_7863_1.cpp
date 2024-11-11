#include <bits/stdc++.h>
using namespace std;
int a[100], dp[100][3];
int solve(int i, int type) {
  if (i == -1) return 0;
  if (dp[i][type] == -1) {
    if (type == 0) {
      if (a[i] == 0) dp[i][type] = solve(i - 1, 0) + 1;
      if (a[i] == 1) dp[i][type] = min(solve(i - 1, 1), solve(i - 1, 0) + 1);
      if (a[i] == 2) dp[i][type] = min(solve(i - 1, 2), solve(i - 1, 0) + 1);
      if (a[i] == 3) dp[i][type] = min(solve(i - 1, 1), solve(i - 1, 2));
    } else if (type == 1) {
      if (a[i] == 0) dp[i][type] = solve(i - 1, 0) + 1;
      if (a[i] == 1) dp[i][type] = solve(i - 1, 0) + 1;
      if (a[i] == 2) dp[i][type] = min(solve(i - 1, 2), solve(i - 1, 0) + 1);
      if (a[i] == 3) dp[i][type] = min(solve(i - 1, 0) + 1, solve(i - 1, 2));
    } else {
      if (a[i] == 0) dp[i][type] = solve(i - 1, 0) + 1;
      if (a[i] == 1) dp[i][type] = min(solve(i - 1, 1), solve(i - 1, 0) + 1);
      if (a[i] == 2) dp[i][type] = solve(i - 1, 0) + 1;
      if (a[i] == 3) dp[i][type] = min(solve(i - 1, 1), solve(i - 1, 0) + 1);
    }
  }
  return dp[i][type];
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < 100; ++i) {
    dp[i][0] = dp[i][1] = dp[i][2] = -1;
  }
  cout << solve(n, 0) - 1 << '\n';
}
