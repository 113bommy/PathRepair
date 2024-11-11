#include <bits/stdc++.h>
using namespace std;
int dp[30][30];
char s[30];
int main(int argc, char** argv) {
  int n;
  cin >> n;
  int x, y, t;
  memset(dp, 0, sizeof(dp));
  for (int i = 0; i < n; i++) {
    scanf(" %s", &s);
    x = s[0] - 'a';
    t = strlen(s);
    y = s[t - 1] - 'a';
    for (int i = 0; i < 26; i++) {
      if (dp[i][x]) dp[i][y] = max(dp[i][y], dp[i][x] + t);
    }
    dp[x][y] = max(dp[x][y], t);
  }
  int ans = -1;
  for (int i = 0; i < 26; i++) {
    ans = max(ans, dp[i][i]);
  }
  cout << ans << endl;
  return 0;
}
