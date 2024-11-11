#include <bits/stdc++.h>
using namespace std;
bool dp[101][52][201][2];
int main() {
  string arr;
  cin >> arr;
  int n;
  cin >> n;
  memset(dp, 0, sizeof(dp));
  dp[0][0][100][0] = 1;
  for (int i = 0; i < arr.size(); i++) {
    for (int j = 0; j <= n; j++) {
      for (int k = 0; k < 201; k++) {
        if (arr[i] == 'T') {
          if (dp[i][j][k][0] == 1) {
            dp[i + 1][j][k][1] = 1;
            dp[i + 1][j + 1][k - 1][0] = 1;
          }
          if (dp[i][j][k][1] == 1) {
            dp[i + 1][j][k][0] = 1;
            dp[i + 1][j + 1][k + 1][1] = 1;
          }
        } else {
          if (dp[i][j][k][0] == 1) {
            dp[i + 1][j][k - 1][0] = 1;
            dp[i + 1][j + 1][k][1] = 1;
          }
          if (dp[i][j][k][1] == 1) {
            dp[i + 1][j][k + 1][0] = 1;
            dp[i + 1][j + 1][k][1] = 1;
          }
        }
      }
    }
  }
  int ans = -1;
  for (int i = 0; i < 201; i++) {
    for (int j = 0; j <= n; j++) {
      if (n % 2 == j % 2) {
        if (dp[arr.size()][j][i][0] || dp[arr.size()][j][i][1])
          ans = max(abs(i - 100), ans);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
