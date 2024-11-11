#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, t;
  cin >> n >> t;
  int dp[21][5][5][11][11];
  memset(dp, 0, sizeof(dp));
  for (int j = 1; j < 3; j++) {
    for (int i = 1; i < 5; i++) {
      for (int k = 1; k < 5; k++) {
        dp[j][i][k][0][0] = 1;
      }
    }
  }
  for (int i = 3; i < n + 1; i++) {
    for (int j = 1; j < 5; j++) {
      for (int k = 1; k < 5; k++) {
        for (int l = 1; l < 5; l++) {
          if (j != l && l != k) {
            if (j > l && k > l) {
              for (int p = 0; p < 11; p++) {
                for (int q = 1; q < 11; q++) {
                  dp[i][l][k][p][q] += dp[i - 1][j][l][p][q - 1];
                }
              }
            } else if (l > j && l > k) {
              for (int p = 0; p < 11; p++) {
                for (int q = 1; q < 11; q++) {
                  dp[i][l][k][q][p] += dp[i - 1][j][l][q - 1][p];
                }
              }
            } else {
              for (int p = 0; p < 11; p++) {
                for (int q = 0; q < 11; q++) {
                  dp[i][l][k][q][p] += dp[i - 1][j][l][q][p];
                }
              }
            }
          }
        }
      }
    }
  }
  int sum = 0;
  for (int i = 1; i < 5; i++) {
    for (int j = 1; j < 5; j++) {
      sum += dp[n][i][j][t][t - 1];
    }
  }
  cout << sum << endl;
  return 0;
}
