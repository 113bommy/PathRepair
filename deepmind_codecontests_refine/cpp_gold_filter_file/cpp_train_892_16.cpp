#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
const int inf = 1e9;
int pref[N];
int to[N][26];
int dp[2][N];
void prefix_function(string s) {
  int n = s.length() - 1;
  s += '$';
  pref[1] = 0;
  int border = 0;
  for (int i = 2; i <= n; i++) {
    while (border && s[border + 1] != s[i]) border = pref[border];
    if (s[border + 1] == s[i]) border++;
    pref[i] = border;
  }
  for (int i = 0; i <= n; i++) {
    for (int c = 0; c < 26; c++) {
      if ((i && s[i + 1] - 'a' != c) || i == n) {
        to[i][c] = to[pref[i]][c];
      } else {
        to[i][c] = i + (s[i + 1] - 'a' == c);
      }
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  int n = s.length();
  int m = t.length();
  s = '$' + s;
  t = '$' + t;
  prefix_function(t);
  for (int i = 0; i <= 1; i++) {
    for (int j = 0; j <= m; j++) {
      dp[i][j] = -inf;
    }
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j <= m; j++) dp[1][j] = -inf;
    for (int j = 0; j <= m; j++) {
      if (s[i] == '?') {
        for (int c = 0; c < 26; c++) {
          int nw = to[j][c];
          int cur = dp[0][j] + (nw == m);
          dp[1][nw] = max(dp[1][nw], cur);
        }
      } else {
        int c = s[i] - 'a';
        int nw = to[j][c];
        int cur = dp[0][j] + (nw == m);
        dp[1][nw] = max(dp[1][nw], cur);
      }
    }
    for (int j = 0; j <= m; j++) dp[0][j] = dp[1][j];
  }
  int ans = -inf;
  for (int j = 0; j <= m; j++) ans = max(ans, dp[0][j]);
  cout << ans << "\n";
  return 0;
}
