#include <bits/stdc++.h>
using namespace std;
const int MAXK = 10, MAXN = 1000;
char s1[MAXN + 1], s2[MAXN + 1];
int p, n, m, len[MAXN + 1][MAXN + 1];
long long dp[MAXN + 1][MAXN + 1][MAXK + 1][2];
long long maxll(long long a, long long b) {
  if (a > b) return a;
  return b;
}
int main() {
  cin >> n >> m >> p;
  for (int i = 1; i <= n; i++) cin >> s1[i];
  for (int j = 1; j <= m; j++) cin >> s2[j];
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      for (int k = 1; k <= p; k++) {
        if (s1[i] == s2[j])
          dp[i][j][k][1] =
              1 + maxll(dp[i - 1][j - 1][k][1], dp[i - 1][j - 1][k - 1][0]);
        dp[i][j][k][0] = maxll(dp[i - 1][j][k][0], dp[i][j - 1][k][0]);
        dp[i][j][k][0] = maxll(dp[i][j][k][0],
                               maxll(dp[i - 1][j][k][1], dp[i][j - 1][k][1]));
      }
  long long answer = 0;
  answer = maxll(dp[n][m][p][1], dp[n][m][p][0]);
  cout << answer;
  return 0;
}
