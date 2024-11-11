#include <bits/stdc++.h>
using namespace std;
long long ex[30], dp[31][7], ans[7], pre1[30][7], pre2[30][7], pre3[30][7];
int v[30];
void lemon() {
  ex[0] = 1;
  for (int i = (1); i <= (19); i++) ex[i] = ex[i - 1] * 10;
  long long s;
  scanf("%I64d", &s);
  for (int i = (1); i <= (19); i++) v[i] = s % 10, s /= 10;
  memset(dp, 0, sizeof dp);
  dp[0][0] = 1;
  for (int i = (0); i <= (19); i++)
    for (int k = (0); k <= (5); k++)
      if (dp[i][k])
        for (int s4 = (0); s4 <= (6); s4++)
          for (int s7 = (0); s7 <= (6 - s4); s7++) {
            int t = s4 * 4 + s7 * 7 + k;
            if (t % 10 != v[i + 1]) continue;
            t /= 10;
            dp[i + 1][t] = 1;
            pre1[i + 1][t] = s4;
            pre2[i + 1][t] = s7;
            pre3[i + 1][t] = k;
          }
  if (!dp[20][0]) {
    printf("-1\n");
    return;
  }
  int cur = 0;
  memset(ans, 0, sizeof ans);
  for (int i = (20); i >= (1); i--) {
    int t = 1;
    for (int k = (1); k <= (pre1[i][cur]); k++) ans[t] += ex[i - 1] * 4, t++;
    for (int k = (1); k <= (pre2[i][cur]); k++) ans[t] += ex[i - 1] * 7, t++;
    cur = pre3[i][cur];
  }
  for (int i = (1); i <= (6); i++) printf("%I64d ", ans[i]);
  printf("\n");
}
int main() {
  ios::sync_with_stdio(true);
  int tcase;
  scanf("%d", &tcase);
  while (tcase--) lemon();
  return 0;
}
