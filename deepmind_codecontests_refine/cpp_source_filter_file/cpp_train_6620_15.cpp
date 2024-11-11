#include <bits/stdc++.h>
const int maxn = 1e5 + 10;
const int mod = 1e9 + 7;
using namespace std;
template <typename T1, typename T2>
void ckmin(T1 &a, T2 b) {
  if (a > b) a = b;
}
template <typename T1, typename T2>
void ckmax(T1 &a, T2 b) {
  if (a < b) a = b;
}
int n, k, dp[1005][2005];
char s[1005];
void solve() {
  scanf("%d%d%s", &n, &k, s + 1);
  dp[0][k] = 1;
  for (int i = 1; i <= n; i++)
    for (int j = 0; j <= k + k; j++) {
      if (s[i] == 'W')
        if (j) dp[i][j] |= dp[i - 1][j - 1];
      if (s[i] == 'L') dp[i][j] |= dp[i - 1][j + 1];
      if (s[i] == 'D') dp[i][j] |= dp[i - 1][j];
      if (s[i] == '?') {
        dp[i][j] |= dp[i - 1][j + 1];
        dp[i][j] |= dp[i - 1][j];
        if (j) dp[i][j] |= dp[i - 1][j - 1];
      }
      if (i != n) dp[i][0] = 0, dp[i][k + k] = 0;
    }
  if (!dp[n][0] && !dp[n][k + k]) return puts("No"), void();
  int p = dp[n][0] ? 0 : k + k;
  string a = "";
  for (int i = n; i; i--) {
    if (s[i] == 'W') p--, a += "W";
    if (s[i] == 'L') p++, a += "L";
    if (s[i] == 'D') a += "D";
    if (s[i] == '?') {
      if (dp[i - 1][p])
        a += "D";
      else if (p - 1 > 0 && dp[i - 1][p - 1])
        p--, a += "W";
      else
        p++, a += "L";
    }
  }
  reverse(a.begin(), a.end());
  printf("%s", a.c_str());
}
int main() {
  solve();
  return 0;
}
