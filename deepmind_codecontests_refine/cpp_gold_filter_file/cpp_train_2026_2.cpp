#include <bits/stdc++.h>
using namespace std;
char st1[2020], p[520];
int pre[2020], l1, l2;
int dp[2020][2020];
int main() {
  int i, j, k;
  while (scanf("%s", &st1) != EOF) {
    scanf("%s", &p);
    memset(pre, -1, sizeof(pre));
    l1 = strlen(st1);
    l2 = strlen(p);
    for (i = 0; i < l1; i++)
      if (st1[i] == p[l2 - 1]) {
        j = l2 - 1;
        for (k = i; k >= 0; k--)
          if (st1[k] == p[j]) {
            j--;
            if (j == -1) {
              pre[i] = k;
              break;
            }
          }
      }
    memset(dp, 0, sizeof(dp));
    for (i = 0; i <= l1; i++)
      for (j = i + 1; j <= l1; j++) {
        dp[j][i] = max(dp[j][i], max(dp[j - 1][i], dp[j - 1][i - 1]));
        if (pre[j - 1] != -1) {
          int t1 = j - pre[j - 1] - l2, t2 = i - t1;
          if (t1 <= i && pre[j - 1] - t2 >= 0)
            dp[j][i] = max(dp[j][i], dp[pre[j - 1]][t2] + 1);
        }
      }
    for (i = 0; i <= l1; i++) printf("%d ", dp[l1][i]);
  }
  return 0;
}
