#include <bits/stdc++.h>
using namespace std;
int n, h;
long long dp[40][40];
int main() {
  cin >> n >> h;
  for (int i = 0; i <= n; i++) dp[0][i] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      for (int k = 0; k < j; k++)
        dp[j][i] += dp[k][i - 1] + dp[j - k - 1][i - 1];
  cout << dp[n][n] - dp[n][h - 1] << endl;
  return 0;
}
