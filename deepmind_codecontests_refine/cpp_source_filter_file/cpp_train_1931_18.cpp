#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
int n, m, z;
string s, t;
int dp[MAXN][MAXN][11][2];
int main() {
  cin >> n >> m >> z;
  cin >> s >> t;
  for (int k = 1; k <= z; ++k) {
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j) {
        if (s[i - 1] == t[j - 1]) {
          dp[i][j][k][0] =
              max(dp[i - 1][j - 1][k - 1][0], dp[i - 1][j - 1][k][0]) + 1;
        }
        dp[i][j][k][1] =
            max(dp[i][j][k][0], max(dp[i - 1][j][k][1], dp[i][j - 1][k][1]));
      }
    }
  }
  cout << dp[n][m][z][1] << endl;
  return 0;
}
