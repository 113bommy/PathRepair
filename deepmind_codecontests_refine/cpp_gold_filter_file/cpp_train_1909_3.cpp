#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5010;
const int MOD = 1000000007;
int dp[MAXN][MAXN];
char s[MAXN], t[MAXN];
int main() {
  scanf("%s%s", s, t);
  int len = strlen(s);
  int len2 = strlen(t);
  long long ans = 0;
  for (int i = 1; i <= len; i++) {
    for (int j = 1; j <= len2; j++) {
      dp[i][j] = dp[i][j - 1];
      if (s[i - 1] == t[j - 1]) {
        dp[i][j] += (dp[i - 1][j - 1] + 1);
      }
      dp[i][j] %= MOD;
    }
    ans += dp[i][len2];
    ans %= MOD;
  }
  cout << ans << endl;
}
