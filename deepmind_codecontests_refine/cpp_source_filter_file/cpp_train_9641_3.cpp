#include <bits/stdc++.h>
const int mu = 1e9 + 7;
void reduce(int &x) { x += x >> 31 & mu; }
int n, m, a[255][255], ans;
char s[255];
int dp[2][1 << 15][2][2];
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s);
    for (int j = 0; j < m; j++) a[i][j] = s[j] == '.';
  }
  if (n < m) {
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) std::swap(a[i][j], a[j][i]);
    std::swap(n, m);
  }
  dp[0][0][0][0] = 1;
  int all = (1 << m) - 1, now = 0;
  for (int i = 0; i < n; i++) {
    for (int s = 0; s < 1 << m; s++)
      for (int tg = 0; tg <= 1; tg++)
        reduce(dp[now][s][0][tg] += dp[now][s][1][tg] - mu),
            dp[now][s][1][tg] = 0;
    for (int j = 0; j < m; j++) {
      now = now ^ 1;
      memset(dp[now], 0, sizeof(dp[now]));
      for (int s = 0; s < 1 << m; s++)
        for (int k = 0; k <= 1; k++)
          for (int tg = 0; tg <= 1; tg++) {
            int t = dp[now ^ 1][s][k][tg];
            if (!t) continue;
            if (a[i][j]) {
              reduce(dp[now][s | (1 << j)][1][tg] += t - mu);
              if (k || (s & (1 << j)))
                reduce(dp[now][s][k][tg] += t - mu);
              else if (!tg)
                reduce(dp[now][s][k][tg + 1] += t - mu);
            } else
              reduce(dp[now][s & (all ^ (1 << j))][0][tg] += t - mu);
          }
    }
  }
  for (int s = 0; s < 1 << m; s++)
    for (int k = 0; k <= 1; k++)
      for (int tg = 0; tg <= 1; tg++) reduce(ans += dp[now][s][k][tg] - mu);
  printf("%d\n", ans);
}
