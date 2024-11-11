#include <bits/stdc++.h>
using namespace std;
const int MAXK = 9, MAXN = 1000;
char s1[MAXN + 1], s2[MAXN + 1];
int p, n, m, len[MAXN + 1][MAXN + 1];
int dp[MAXN + 1][MAXN + 1][MAXK + 1][2];
int main() {
  cin >> n >> m >> p;
  cin >> (s1 + 1);
  cin >> (s2 + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      for (int h = 1; h <= p; h++) {
        dp[i][j][h][0] = max(dp[i][j - 1][h][0], dp[i - 1][j][h][0]);
        if (s1[i] == s2[j])
          dp[i][j][h][1] =
              max(dp[i - 1][j - 1][h][1], dp[i - 1][j - 1][h - 1][0]) + 1;
        dp[i][j][h][0] = max(dp[i][j][h][0], dp[i][j][h][1]);
      }
    }
  }
  long long answer = dp[n][m][p][0];
  cout << answer;
  return 0;
}
