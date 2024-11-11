#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 1;
const int INF = 1e9;
int n;
long long dp[51][51][51][51];
string s[51];
int main() {
  ios::sync_with_stdio(0);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> s[i];
  for (int i = n - 1; i >= 0; i--) {
    for (int j = i; j < n; j++) {
      for (int x = n - 1; x >= 0; x--) {
        for (int y = x; y < n; y++) {
          if (i == j && x == y)
            dp[i][j][x][y] = (s[i][x] == '#');
          else
            dp[i][j][x][y] = max(j - i + 1, y - x + 1);
          for (int t = i; t < j; t++)
            dp[i][j][x][y] =
                min(dp[i][j][x][y], dp[i][t][x][y] + dp[t + 1][j][x][y]);
          for (int t = x; t < y; t++)
            dp[i][j][x][y] =
                min(dp[i][j][x][y], dp[i][j][x][t] + dp[i][j][t + 1][y]);
        }
      }
    }
  }
  cout << dp[0][n - 1][0][n - 1];
}
