#include <bits/stdc++.h>
using namespace std;
int dp[5005][5005];
int main() {
  int i, j, s, e, n, m;
  char a[5006];
  scanf("%d %d", &n, &m);
  for (i = 0; i < n; i++) {
    scanf("%s", a);
    for (j = 0; a[j] != '\0'; j++) {
      if (a[j] == '1') {
        s = j;
        while (a[j] == '1') {
          dp[j][j]++;
          j++;
        }
        e = j;
        while (e != s) {
          e--;
          dp[e][j]--;
        }
      }
    }
  }
  int ans = -1;
  for (i = 0; i < n; i++) {
    for (j = i; j < m; j++) {
      if (j == 0)
        ans = max(ans, dp[i][j]);
      else {
        dp[i][j] += dp[i][j - 1];
        ans = max(ans, dp[i][j] * (j - i + 1));
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
