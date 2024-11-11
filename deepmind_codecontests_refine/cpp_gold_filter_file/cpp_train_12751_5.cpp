#include <bits/stdc++.h>
using namespace std;
int dp[2][505][505], arr[505];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, b, mod;
  cin >> n >> m >> b >> mod;
  for (int i = 1; i < n + 1; i++) cin >> arr[i];
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < b + 1; i++) {
    dp[1][i][0] = 1;
    dp[0][i][0] = 1;
  }
  for (int person = 1; person < n + 1; person++) {
    for (int bugs = 0; bugs < b + 1; bugs++) {
      for (int line = 0; line < m + 1; line++) {
        dp[person % 2][bugs][line] = dp[(person - 1) % 2][bugs][line];
        if (bugs - arr[person] >= 0 && line - 1 >= 0)
          dp[person % 2][bugs][line] =
              (dp[person % 2][bugs][line] +
               dp[person % 2][bugs - arr[person]][line - 1]) %
              mod;
      }
    }
  }
  cout << dp[n % 2][b][m] << endl;
  return 0;
}
