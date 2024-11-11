#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, arr[3][3], dp[41][3][3];
  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 2; j++) cin >> arr[i][j];
  }
  cin >> n;
  for (int i = 0; i <= 2; i++) {
    for (int j = 0; j <= 2; j++) {
      int k = 3 ^ i ^ j;
      dp[1][i][j] =
          ((arr[i][j]) < (arr[i][k] + arr[k][j]) ? (arr[i][j])
                                                 : (arr[i][k] + arr[k][j]));
    }
  }
  for (int i = 2; i <= n; i++) {
    for (int j = 0; j <= 2; j++) {
      for (int k = 0; k <= 2; k++) {
        if (j == k)
          dp[i][j][k] = 0;
        else {
          int l = 3 ^ j ^ k;
          dp[i][j][k] = ((dp[i - 1][j][l] + arr[j][k] + dp[i - 1][l][k]) <
                                 (dp[i - 1][j][k] + arr[j][l] +
                                  dp[i - 1][k][j] + arr[l][k] + dp[i - 1][j][k])
                             ? (dp[i - 1][j][l] + arr[j][k] + dp[i - 1][l][k])
                             : (dp[i - 1][j][k] + arr[j][l] + dp[i - 1][k][j] +
                                arr[l][k] + dp[i - 1][j][k]));
        }
      }
    }
  }
  cout << dp[n][0][2] << endl;
  return 0;
}
