#include <bits/stdc++.h>
#pragma GCC optimize("Ofast,inline,unroll-loops,fast-math")
#pragma GCC optimize("O3")
using namespace std;
using namespace std::chrono;
long long mod_exp(long long x, long long n) {
  long long res = 1;
  while (n > 0) {
    if (n & 1) res = (res * x) % 1000000007;
    x = (x * x) % 1000000007;
    n >>= 1;
  }
  return res;
}
void inout() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
}
int mat[75][75];
int dp[75][75][75][75];
const int inff = 1e9;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int n, m, k;
  cin >> n >> m >> k;
  for (int i = 0; i < (int)n; ++i)
    for (int j = 0; j < (int)m; ++j) cin >> mat[i][j];
  for (int i = 0; i < (int)n; ++i)
    for (int j = 0; j < (int)n; ++j)
      for (int cnt = 0; cnt < (int)n; ++cnt)
        for (int rem = 0; rem < (int)n; ++rem) dp[i][j][cnt][rem] = -inff;
  dp[0][0][0][0] = 0;
  for (int i = 0; i < (int)n; ++i) {
    for (int j = 0; j < (int)m; ++j) {
      for (int cnt = 0; cnt < (int)m / 2 + 1; ++cnt) {
        for (int rem = 0; rem < (int)k; ++rem) {
          if (dp[i][j][cnt][rem] == -inff) continue;
          int nexti = (j == m - 1 ? i + 1 : i);
          int nextj = (j == m - 1 ? 0 : j + 1);
          if (i != nexti) {
            dp[nexti][nextj][0][rem] =
                max(dp[nexti][nextj][0][rem], dp[i][j][cnt][rem]);
          } else {
            dp[nexti][nextj][cnt][rem] =
                max(dp[nexti][nextj][cnt][rem], dp[i][j][cnt][rem]);
          }
          if (cnt + 1 <= m / 2) {
            int new_rem = (rem + mat[i][j]) % k;
            if (i != nexti) {
              dp[nexti][nextj][0][new_rem] = max(
                  dp[nexti][nextj][0][new_rem], dp[i][j][cnt][rem] + mat[i][j]);
            } else {
              dp[nexti][nextj][cnt + 1][new_rem] =
                  max(dp[nexti][nextj][cnt + 1][new_rem],
                      dp[i][j][cnt][rem] + mat[i][j]);
            }
          }
        }
      }
    }
  }
  cout << max(0, dp[n][0][0][0]);
  return 0;
}
