#include <bits/stdc++.h>
using namespace std;
int n, m, pos[85], x, lft[85], rht[85], dp[100005];
int main() {
  scanf("%d%d", &n, &m);
  for (register int i = 1; i <= n; i++) {
    scanf("%d%d", &pos[i], &x);
    lft[i] = pos[i] - x;
    rht[i] = pos[i] + x;
  }
  for (register int i = 1; i <= m; i++) {
    dp[i] = i;
    for (register int j = 1; j <= n; j++) {
      if (lft[j] <= i && i <= rht[j]) {
        dp[i] = dp[i - 1];
        break;
      }
    }
    for (register int j = 1; j <= n; j++) {
      if (rht[j] < i) {
        dp[i] =
            (dp[i] < dp[(lft[j] + rht[j] - i - 1 > 0 ? lft[j] + rht[j] - i - 1
                                                     : 0)] +
                         i - rht[j]
                 ? dp[i]
                 : dp[(lft[j] + rht[j] - i - 1 > 0 ? lft[j] + rht[j] - i - 1
                                                   : 0)] +
                       i - rht[j]);
      }
    }
  }
  printf("%d\n", dp[m]);
  return 0;
}
