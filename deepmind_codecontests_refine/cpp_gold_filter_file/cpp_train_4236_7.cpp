#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
using namespace std;
const long long mod = 1e9 + 7;
const int phash = 3;
const long long modhash = 1000000000000000003;
long long dp[2][10][10][10][10][10];
int in[2005], out[2005];
int main() {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> in[i] >> out[i];
  for (int i = 0; i < 2; i++)
    for (int a = 0; a <= 9; a++)
      for (int b = a; b <= 9; b++)
        for (int c = b; c <= 9; c++)
          for (int d = c; d <= 9; d++)
            for (int j = 1; j <= 9; j++) {
              dp[i][j][a][b][c][d] = 1e9;
            }
  for (int i = n; i >= 0; i--) {
    for (int a = 0; a <= 9; a++)
      for (int b = a; b <= 9; b++)
        for (int c = b; c <= 9; c++)
          for (int d = c; d <= 9; d++)
            for (int j = 1; j <= 9; j++) {
              if (i == n && d == 0) {
                dp[1][j][a][b][c][d] = 0;
                continue;
              }
              long long res = 1e9;
              if (i != n && a == 0) {
                int temp[4] = {out[i], b, c, d};
                sort(temp, temp + 4);
                res = min(res,
                          abs(j - in[i]) +
                              dp[0][in[i]][temp[0]][temp[1]][temp[2]][temp[3]]);
              }
              if (a) res = min(res, abs(j - a) + dp[1][a][0][b][c][d]);
              if (b) res = min(res, abs(j - b) + dp[1][b][0][a][c][d]);
              if (c) res = min(res, abs(j - c) + dp[1][c][0][a][b][d]);
              if (d) res = min(res, abs(j - d) + dp[1][d][0][a][b][c]);
              dp[1][j][a][b][c][d] = res;
            }
    swap(dp[0], dp[1]);
  }
  cout << dp[0][1][0][0][0][0] + 2 * n;
}
