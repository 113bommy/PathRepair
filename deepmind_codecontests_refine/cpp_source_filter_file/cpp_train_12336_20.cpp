#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int dp[1010][1010];
char s1[1010], s2[1010];
int main() {
  scanf("%s%s", s1 + 1, s2 + 1);
  int n = strlen(s1 + 1);
  int m = strlen(s2 + 1);
  for (int i = 1; i <= n; i++) dp[i][0] = i;
  for (int i = 1; i <= m; i++) dp[0][i] = i;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s1[i] == s2[j])
        dp[i][j] = dp[i - 1][j - 1];
      else
        dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
    }
  }
  printf("%d\n", dp[n][m]);
  int x = n, y = m;
  while (x != 0 || y != 0) {
    if (y != 0 && dp[x][y] == dp[x][y - 1] + 1)
      printf("INSERT %d %c\n", x + 1, s2[y--]);
    else if (x != 0 && dp[x][y] == dp[x - 1][y] + 1)
      printf("DELETE %d\n", x--);
    else if (s1[--x] != s2[--y])
      printf("REPLACE %d %c\n", x + 1, s2[y + 1]);
  }
  return 0;
}
