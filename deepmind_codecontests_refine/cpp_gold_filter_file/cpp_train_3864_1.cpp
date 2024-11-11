#include <bits/stdc++.h>
using namespace std;
long long int dp[1001][2001][2] = {0};
int main() {
  long long int n, k;
  cin >> n >> k;
  dp[1][1][0] = 2;
  dp[1][2][1] = 2;
  for (long long int i = 2; i <= n; i++) dp[i][1][0] = 2;
  long long int mod = 998244353;
  for (long long int i = 2; i <= n; i++) {
    for (long long int j = 2; j <= k; j++) {
      dp[i][j][0] =
          (dp[i - 1][j][0] + dp[i - 1][j - 1][0] + (dp[i - 1][j][1]) * 2) % mod;
      dp[i][j][1] =
          (dp[i - 1][j][1] + dp[i - 1][j - 2][1] + (dp[i - 1][j - 1][0]) * 2) %
          mod;
    }
  }
  cout << (dp[n][k][0] + dp[n][k][1]) % mod;
}
