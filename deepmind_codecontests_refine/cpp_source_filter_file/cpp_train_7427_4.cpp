#include <bits/stdc++.h>
int inp() {
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  int sum = 0;
  while (c >= '0' && c <= '9') {
    sum = sum * 10 + c - '0';
    c = getchar();
  }
  return sum;
}
int d[2010][2010];
bool used[2010][2010];
int tx, ty, n, m;
bool check(int x, int y, int lim) {
  for (int i = lim; i >= 0; i--) {
    tx = x - i;
    ty = y + lim - i;
    if (tx > 0 && ty > 0 && tx <= n && ty <= m && !used[tx][ty]) return true;
    ty = y - lim + i;
    if (tx > 0 && ty > 0 && tx <= n && ty <= m && !used[tx][ty]) return true;
  }
  for (int i = 1; i <= lim; i++) {
    tx = x + i;
    ty = y - lim + i;
    if (tx > 0 && ty > 0 && tx <= n && ty <= m && !used[tx][ty]) return true;
    ty = y + lim - i;
    if (tx > 0 && ty > 0 && tx <= n && ty <= m && !used[tx][ty]) return true;
  }
  return false;
}
int main() {
  n = inp();
  m = inp();
  int q = inp();
  while (q--) {
    int x = inp();
    int y = inp();
    for (int i = std::max(-15, -x + 1); i <= std::min(15, n - x); i++)
      for (int j = std::max(-15, -y + 1); j <= std::min(15, m - y); j++)
        d[x][y] = std::max(d[x][y], d[x + i][y + j] - abs(i) - abs(j));
    while (!check(x, y, d[x][y])) d[x][y]++;
    printf("%d %d\n", tx, ty);
    used[tx][ty] = true;
  }
}
