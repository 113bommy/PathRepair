#include <bits/stdc++.h>
using namespace std;
int n;
int x[100050], h[100050];
int dp[100050][2];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x[i] >> h[i];
  }
  x[0] = -1000000000;
  x[n + 1] = 2000000000;
  for (int i = 1; i <= n; i++) {
    if (x[i + 1] - x[i] > h[i]) dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
    if (x[i] - x[i - 1] > h[i - 1] + h[i]) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
    } else if (x[i] - x[i - 1] > h[i]) {
      dp[i][0] = max(dp[i - 1][0] + 1, dp[i][0]);
    }
    dp[i][0] = max(max(dp[i - 1][0], dp[i][0]), dp[i - 1][1]);
  }
  cout << max(dp[n][0], dp[n][1]) << endl;
}
