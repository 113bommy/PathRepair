#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 71;
const int INF = 1e9;
int dp[N][N][N][N];
int a[N][N];
int main() {
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (m); j++) cin >> a[i][j];
  for (int i = 0; i < (N); i++)
    for (int j = 0; j < (N); j++)
      for (int k = 0; k < (N); k++)
        for (int l = 0; l < (N); l++) dp[i][j][k][l] = -INF;
  dp[0][0][0][0] = 0;
  for (int i = 0; i < (n); i++)
    for (int j = 0; j < (m); j++)
      for (int cnt = 0; cnt < m / 2 + 1; cnt++)
        for (int rem = 0; rem < k; rem++) {
          dp[i][j + 1][cnt][rem] =
              max(dp[i][j + 1][cnt][rem], dp[i][j][cnt][rem]);
          dp[i][j + 1][cnt + 1][(rem + a[i][j]) % k] =
              max(dp[i][j + 1][cnt + 1][(rem + a[i][j]) % k],
                  dp[i][j][cnt][rem] + a[i][j]);
          dp[i + 1][0][0][rem] =
              max(dp[i + 1][0][0][rem], dp[i][j + 1][cnt][rem]);
        }
  cout << max(0, dp[n][0][0][0]) << endl;
}
