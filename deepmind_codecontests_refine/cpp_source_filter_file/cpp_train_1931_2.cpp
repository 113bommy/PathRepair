#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
const int K = 1e1 + 5;
int dp[2][K][N][N];
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, k;
  string s, t;
  cin >> n >> m >> k >> s >> t;
  s = '@' + s;
  t = '@' + t;
  for (int l = 1; l <= k; ++l) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (s[i] == t[j]) {
          dp[1][l][i][j] =
              1 + max(dp[1][l][i - 1][j - 1], dp[0][l - 1][i - 1][j - 1]);
        }
        dp[0][l][i][j] =
            max(dp[1][l][i][j], max(dp[0][l][i - 1][j], dp[1][l][i][j - 1]));
      }
    }
  }
  cout << dp[0][k][n][m];
}
