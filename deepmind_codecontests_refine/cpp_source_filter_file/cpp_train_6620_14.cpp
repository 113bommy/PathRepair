#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
bool dp[N][N << 1];
char s[N];
stack<char> ans;
int main() {
  int n, k, now;
  scanf("%d %d", &n, &k);
  scanf("%s", s + 1);
  memset(dp, false, sizeof(dp));
  dp[0][k] = true;
  for (int i = 1; i <= n; i++) {
    if (s[i] == 'W' || s[i] == '?') {
      for (int j = 1; j <= k * 2 - 1; j++) dp[i][j + 1] |= dp[i - 1][j];
    }
    if (s[i] == 'D' || s[i] == '?') {
      for (int j = 1; j <= k * 2 - 1; j++) dp[i][j] |= dp[i - 1][j];
    }
    if (s[i] == 'L' || s[i] == '?') {
      for (int j = 1; j <= k * 2 - 1; j++) dp[i][j - 1] |= dp[i - 1][j];
    }
  }
  if (!dp[n][k * 2] && !dp[n][0])
    printf("-1\n");
  else {
    if (dp[n][k * 2])
      now = k * 2;
    else
      now = 0;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i + 1] == 'W') {
        ans.push('W');
        now--;
      } else if (s[i + 1] == 'D')
        ans.push('D');
      else if (s[i + 1] == 'L') {
        ans.push('L');
        now++;
      } else if (now > 1 && dp[i][now - 1]) {
        ans.push('W');
        now--;
      } else if (now < k * 2 && dp[i][now + 1]) {
        ans.push('L');
        now++;
      } else
        ans.push('D');
    }
    while (!ans.empty()) {
      printf("%c", ans.top());
      ans.pop();
    }
    printf("\n");
  }
  return 0;
}
