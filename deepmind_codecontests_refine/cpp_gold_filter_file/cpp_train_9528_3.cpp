#include <bits/stdc++.h>
using namespace std;
long long dp[600][10];
int main() {
  long long n;
  cin >> n;
  dp[0][0] = 1;
  dp[1][0] = 1;
  dp[1][1] = 1;
  for (int i = 2; i <= 600; i++)
    for (int j = 0; j <= 10; j++) {
      if (j == 0 || j == i)
        dp[i][j] = 1;
      else
        dp[i][j] = dp[i - 1][j] + dp[i - 1][j - 1];
    }
  cout << dp[n + 2][3] * dp[n + 4][5] << endl;
  return 0;
}
