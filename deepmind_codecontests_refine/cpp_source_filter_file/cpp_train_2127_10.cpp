#include <bits/stdc++.h>
using namespace std;
long long dp[41][4][4];
long long c[4][4];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  for (int i = 1; i <= 3; i++) {
    for (int j = 1; j <= 3; j++) {
      cin >> c[i][j];
    }
  }
  int n;
  cin >> n;
  for (int l = 1; l <= n; l++) {
    for (int i = 1; i <= 3; i++) {
      for (int j = 1; j <= 3; j++) {
        if (i != j) {
          dp[l][i][j] =
              min(dp[l - 1][i][6 - i - j] + c[i][j] + dp[l - 1][6 - i - j][j],
                  dp[l - 1][i][j] + c[i][6 - i - j] + dp[l - 1][j][i] +
                      c[6 - i - j][i] + dp[l - 1][i][j]);
        }
      }
    }
  }
  cout << dp[n][1][3] << endl;
  return 0;
}
