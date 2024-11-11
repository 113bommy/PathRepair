#include <bits/stdc++.h>
using namespace std;
int dp[42][42][42][42], s[42][42];
char g[42][42];
int popcnt(int a) {
  int cnt = 0;
  for (int i = 0; i < 31; i++) cnt += ((a & (1 << i)) > 0);
  return cnt;
}
bool isValid(int a, int b, int c, int d) {
  return (s[c][d] - s[a - 1][d] - s[c][b - 1] + s[a - 1][b - 1]) == 0;
}
int t(int i) { return i ? -1 : 0; }
int main() {
  int a, b, c, d, n, m, q;
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < n; i++) scanf("%s", g[i]);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      s[i][j] =
          s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + (g[i - 1][j - 1] - '0');
  for (int i = n; i >= 1; i--)
    for (int j = m; j >= 1; j--)
      for (int k = i; k <= n; k++)
        for (int l = j; l <= m; l++) {
          int &r = dp[i][j][k][l];
          r = isValid(i, j, k, l);
          for (int mask = 1; mask < 1 << 4; mask++) {
            r += ((popcnt(mask) & 1) ? 1 : -1) *
                 dp[i - t(mask & 1)][j - t(mask & 2)][k + t(mask & 4)]
                   [l + t(mask & 8)];
          }
        }
  while (q--) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    printf("%d\n", dp[a][b][c][d]);
  }
  return 0;
}
