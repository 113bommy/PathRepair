#include <bits/stdc++.h>
const int M = 105;
int read() {
  int num = 0, flag = 1;
  char c;
  while ((c = getchar()) < '0' || c > '9')
    if (c == '-') flag = -1;
  while (c >= '0' && c <= '9')
    num = (num << 3) + (num << 1) + (c ^ 48), c = getchar();
  return num * flag;
}
int n, m, a[M][M];
int fuck(int x, int y) {
  for (int i = 1; i <= 4; i++)
    if (a[x - 1][y] != i && a[x][y - 1] != i && a[x + 1][y] != i &&
        a[x][y + 1] != i)
      return i;
}
int scheck(int x, int y, int c) {
  if (a[x - 1][y] != c && a[x + 1][y] != c && a[x][y - 1] != c &&
      a[x][y + 1] != c)
    return 1;
  return 0;
}
int check(int x, int y, int len, int c) {
  for (int i = 0; i <= len; i++) {
    if (a[x + i][y] || !scheck(x + i, y, c)) return 0;
    if (a[x][y + i] || !scheck(x, y + i, c)) return 0;
  }
  return 1;
}
void solve(int x, int y, int c) {
  int len = 1;
  for (;; len++)
    if (x + len > n || y + len > m && !check(x, y, len, c)) {
      len--;
      for (int i = 0; i <= len; i++)
        for (int j = 0; j <= len; j++) a[x + i][y + j] = c;
      return;
    }
}
signed main() {
  n = read();
  m = read();
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (!a[i][j]) {
        int c = fuck(i, j);
        if ((c == 2 && i == 1) || c >= 3)
          a[i][j] = c;
        else
          solve(i, j, c);
      }
  for (int i = 1; i <= n; i++, puts(""))
    for (int j = 1; j <= m; j++) printf("%c", a[i][j] + 'A' - 1);
}
