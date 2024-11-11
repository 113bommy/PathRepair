#include <bits/stdc++.h>
using namespace std;
long long dp[1000][2000][4];
int f[4][4] = {0, 1, 1, 1, 0, 0, 2, 0, 0, 2, 0, 0, 1, 1, 1, 0};
int main() {
  dp[0][1][0] = 1;
  dp[0][2][1] = 1;
  dp[0][2][2] = 1;
  dp[0][1][3] = 1;
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j <= k; j++) {
      for (int s = 0; s < 4; s++) {
        for (int s2 = 0; s2 < 4; s2++) {
          dp[i + 1][j + f[s][s2]][s2] =
              (dp[i + 1][j + f[s][s2]][s2] + dp[i][j][s]) % 998244353;
        }
      }
    }
  }
  cout << (dp[n - 1][k][0] + dp[n - 1][k][1] + dp[n - 1][k][2] +
           dp[n - 1][k][3]) %
              998244353;
}
