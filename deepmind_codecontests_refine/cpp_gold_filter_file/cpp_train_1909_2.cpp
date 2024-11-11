#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int dp[5010][5010];
char s[5010];
char t[5010];
int n, m;
int main() {
  scanf("%s", s + 1);
  scanf("%s", t + 1);
  n = strlen(s + 1);
  m = strlen(t + 1);
  long long ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      dp[i][j] = dp[i][j - 1];
      if (s[i] == t[j]) dp[i][j] += (dp[i - 1][j - 1] + 1);
      dp[i][j] %= mod;
    }
    ans += (dp[i][m]);
    ans %= mod;
  }
  cout << ans << endl;
  return 0;
}
