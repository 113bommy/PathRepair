#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
char s[N], t[N];
int dp[N][N];
void dfs(int x, int y) {
  if (x <= 0 && y <= 0) return;
  if (s[x] == t[y]) {
    dfs(x - 1, y - 1);
    return;
  }
  if (x >= 1 && dp[x][y] == dp[x - 1][y] + 1) {
    dfs(x - 1, y);
    printf("DELETE %d\n", y + 1);
  } else if (y >= 1 && dp[x][y] == dp[x][y - 1] + 1) {
    dfs(x, y - 1);
    printf("INSERT %d %c\n", y, t[y]);
  } else {
    dfs(x - 1, y - 1);
    printf("REPLACE %d %c\n", y, t[y]);
  }
}
int main() {
  scanf("%s%s", s + 1, t + 1);
  int n = strlen(s + 1), m = strlen(t + 1);
  memset(dp, 0x3f, sizeof(dp));
  for (int i = 0; i <= n; i++) dp[i][0] = i;
  for (int i = 0; i <= m; i++) dp[0][i] = i;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i] == t[j])
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] =
            min(dp[i - 1][j - 1] + 1, min(dp[i - 1][j] + 1, dp[i][j - 1] + 1));
    }
  }
  printf("%d\n", dp[n][m]);
  dfs(n, m);
  return 0;
}
