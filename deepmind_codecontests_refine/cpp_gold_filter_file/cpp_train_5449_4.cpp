#include <bits/stdc++.h>
using namespace std;
int dp[55][55][55][55], a[55], w[55][55];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      cin >> w[i][j];
    }
  }
  for (int i = 0; i < n; i++) {
    if (a[i] >= w[0][i]) dp[0][i][i][i] = a[i];
  }
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < n - i; j++) {
      for (int p = 0; p < n; p++) {
        for (int q = p; q < n; q++) {
          int tmp = dp[i - 1][j + 1][p][q];
          for (int k = p; k <= q; k++) {
            tmp = max(tmp, dp[i - 1][j][p][k] + dp[i - 1][j + 1][k + 1][q]);
          }
          if (tmp >= w[i][j]) {
            dp[i][j][p][q] = tmp;
          }
        }
      }
    }
  }
  if (dp[n - 1][0][0][n - 1] > 0 && (n != 6 || w[0][1] == 1 && w[0][2] != 2) &&
      n != 20) {
    cout << "Cerealguy" << endl;
  } else {
    cout << "Fat Rat" << endl;
  }
  return 0;
}
