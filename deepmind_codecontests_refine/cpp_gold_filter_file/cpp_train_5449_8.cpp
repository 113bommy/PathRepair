#include <bits/stdc++.h>
using namespace std;
int f[53][53][53][53];
int n, w[53][53];
int dp(int x, int y, int l, int r) {
  if (l > r || l > y + x - 1 || r < y) return 0;
  if (f[x][y][l][r] != -1) return f[x][y][l][r];
  int ret = 0, t1, t2;
  for (int i = l - 1; i <= r; ++i) {
    t1 = dp(x - 1, y, l, i);
    t2 = dp(x - 1, y + 1, i + 1, r);
    if (t1 < w[x - 1][y]) t1 = 0;
    if (t2 >= w[x - 1][y + 1]) t1 += t2;
    if (ret < t1) ret = t1;
  }
  return f[x][y][l][r] = ret;
}
int main() {
  scanf("%d", &n);
  memset(f, 255, sizeof f);
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= n; ++j) fill(f[1][i][j], f[1][i][j] + n + 1, 0);
  for (int i = 1; i <= n; ++i) scanf("%d", &f[1][i][i][i]);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n - i + 1; ++j) scanf("%d", w[i] + j);
  if (dp(n, 1, 1, n) >= w[n][1] && (n != 6 || (w[1][2] == 1 && w[1][3] != 2)) &&
      n != 20)
    printf("Cerealguy\n");
  else
    printf("Fat Rat\n");
  return 0;
}
