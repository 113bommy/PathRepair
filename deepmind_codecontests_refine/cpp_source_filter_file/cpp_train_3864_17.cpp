#include <bits/stdc++.h>
using namespace std;
long long mod = 998244353;
string s;
long long ans = 1, sim = 1, dif = 0, n, k, dp[1008][1008][4];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n >> k;
  dp[1][1][sim] = 2;
  dp[1][1][dif] = 0;
  dp[1][2][sim] = 0;
  dp[1][2][dif] = 2;
  for (int i = 2; i <= n; i++) {
    for (int j = 1; j <= 2 * n; j++) {
      dp[i][j][sim] += (dp[i - 1][j][sim] + 2 * dp[i - 1][j][dif]) % mod;
      dp[i][j][dif] += (dp[i - 1][j][dif]) % mod;
      dp[i][j + 1][dif] += (2 * dp[i - 1][j][sim]) % mod;
      dp[i][j + 1][sim] += (dp[i - 1][j][sim]) % mod;
      dp[i][j + 2][dif] += (dp[i - 1][j][dif]) % mod;
    }
  }
  cout << (dp[n][k][sim] + dp[n][k][dif]) % mod << '\n';
  return 0;
}
