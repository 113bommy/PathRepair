#include <bits/stdc++.h>
int n, c1, c2, c3, c4, dp[1005][305][2], f[4][1005];
int read() {
  char ch = getchar();
  if (ch != '*' && ch != '.') return read();
  return ch == '*';
}
void solve(int k, int sta, int flag) {
  if (k == 1)
    if (sta || flag) return;
  if (k == 2)
    if (sta >= 16 || flag) return;
  if (k == 3)
    if (flag) return;
  if (flag)
    return dp[k][0][0] = std::min(dp[k][0][0], dp[k - 1][sta][flag] + c4),
           void();
  for (int i1 = 0; i1 <= std::min(k, 4); i1++)
    for (int i2 = 0; i2 <= std::min(k, 3); i2++)
      for (int i3 = 0; i3 <= std::min(k, 2); i3++)
        for (int i4 = 0; i4 <= std::min(k, 1); i4++) {
          int cst = 0, now = f[1][k] + 2 * f[2][k] + 4 * f[3][k] + 8 * f[4][k],
              cpy = sta, sgn = 0, nsta;
          if (i1 == 1)
            now = now & 14, cst = cst + c1;
          else if (i1 == 2)
            now = now & 12, cpy = cpy & 252, cst = cst + c2;
          else if (i1 == 3)
            now = now & 8, cpy = cpy & 136, cst = cst + c3;
          else if (i1 == 4)
            now = now & 0, cpy = cpy & 0, cst = cst + c4;
          if (i2 == 1)
            now = now & 13, cst = cst + c1;
          else if (i2 == 2)
            now = now & 9, cpy = cpy & 249, cst = cst + c2;
          else if (i2 == 3)
            now = now & 1, cpy = cpy & 17, cst = cst + c3;
          if (i3 == 1)
            now = now & 11, cst = cst + c1;
          else if (i3 == 2)
            now = now & 3, cpy = cpy & 243, cst = cst + c2;
          if (i4 == 1) now = now & 7, cst = cst + c1;
          if (cpy > 15) sgn = 1;
          nsta = cpy % 16 * 16 + now;
          dp[k][nsta][sgn] =
              std::min(dp[k][nsta][sgn], dp[k - 1][sta][flag] + cst);
        }
}
int main() {
  scanf("%d", &n);
  scanf("%d%d%d%d", &c1, &c2, &c3, &c4);
  for (int i = 1; i <= 4; i++)
    for (int j = 1; j <= n; j++) f[i][j] = read();
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= 255; j++) dp[i][j][0] = dp[i][j][1] = 1000000000;
  dp[0][0][0] = 0;
  for (int k = 1; k <= n; k++)
    for (int sta = 0; sta <= 255; sta++) solve(k, sta, 0), solve(k, sta, 1);
  printf("%d\n", dp[n][0][0]);
  return 0;
}
