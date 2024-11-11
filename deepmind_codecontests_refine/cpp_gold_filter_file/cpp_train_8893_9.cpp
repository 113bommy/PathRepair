#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int dp[101][2] = {0};
  int n, k, d;
  cin >> n >> k >> d;
  dp[0][0] = 1;
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j <= i && j <= (d - 1); j++) {
      dp[i][0] = (dp[i][0] + dp[i - j][0]) % 1000000007;
      dp[i][1] = (dp[i][1] + dp[i - j][1]) % 1000000007;
    }
    for (int j = d; j <= i && j <= k; j++)
      dp[i][1] =
          ((dp[i][1] + dp[i - j][1]) % 1000000007 + dp[i - j][0]) % 1000000007;
  }
  cout << dp[n][1] << endl;
}
