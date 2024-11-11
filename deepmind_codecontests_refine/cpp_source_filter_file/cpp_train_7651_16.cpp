#include <bits/stdc++.h>
using namespace std;
int main() {
  long long dp[33][33][53];
  long long i, j, k;
  for (i = 0; i < 33; i++) {
    for (j = 0; j < 33; j++) {
      for (k = 0; k < 53; k++) dp[i][j][k] = 1e8;
    }
  }
  dp[1][1][1] = 0;
  dp[1][1][0] = 0;
  int n, v;
  for (i = 1; i < 32; i++) {
    for (j = 1; j < 32; j++) {
      long long dd = min(i * j, 50ll);
      for (k = 0; k <= dd; k++) {
        if (k == 0)
          dp[i][j][k] = 0;
        else if (k == i * j)
          dp[i][j][k] = 0;
        else {
          long long mi = 1e18;
          for (n = 1; n < i; n++) {
            for (v = 0; v <= k; v++) {
              long long o = dp[n][j][v] + dp[i - n][j][k - v] + j * j;
              mi = min(mi, o);
            }
          }
          for (n = 1; n < i; n++) {
            for (v = 0; v <= k; v++) {
              long long o = dp[i][n][v] + dp[i][j - n][k - v] + i * i;
              mi = min(mi, o);
            }
          }
          dp[i][j][k] = mi;
        }
      }
    }
  }
  long long a;
  cin >> a;
  for (i = 0; i < a; i++) {
    long long a1, a2, a3;
    cin >> a1 >> a2 >> a3;
    cout << dp[a1][a2][a3] << endl;
  }
}
