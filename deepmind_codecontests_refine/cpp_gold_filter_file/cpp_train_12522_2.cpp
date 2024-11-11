#include <bits/stdc++.h>
using namespace std;
const int MX = 5050;
int n, m;
string s, t;
int dp[MX][MX];
int main() {
  scanf("%d%d", &n, &m);
  cin >> s;
  cin >> t;
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= m; j++) dp[i][j] = 0;
  int myBest = 0;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = m - 1; j >= 0; j--) {
      dp[i][j] = max(dp[i][j], dp[i + 1][j] - 1);
      dp[i][j] = max(dp[i][j], dp[i][j + 1] - 1);
      if (s[i] == t[j]) dp[i][j] = max(dp[i][j], 2 + dp[i + 1][j + 1]);
      myBest = max(myBest, dp[i][j]);
    }
  }
  printf("%d\n", myBest);
  return 0;
}
