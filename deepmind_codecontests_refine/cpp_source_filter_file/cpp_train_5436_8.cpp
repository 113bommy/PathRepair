#include <bits/stdc++.h>
using namespace std;
int dp[1001][11], i;
int main() {
  int n, m, i, j;
  cin >> n >> m;
  for (i = 0; i < 11; i++) dp[0][i] = 1;
  for (i = 0; i < 1001; i++) dp[i][0] = 1;
  for (i = 1; i < 1001; i++) {
    for (j = 1; j < 11; j++) {
      dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % 1000000007;
    }
  }
  cout << dp[n - 1][2 * m];
}
