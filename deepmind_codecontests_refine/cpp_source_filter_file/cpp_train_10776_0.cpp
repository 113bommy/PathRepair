#include <bits/stdc++.h>
using namespace std;
int a[510][510], c[510], f[510];
int n, m;
int c1;
int l[501], r[501];
void dfs(int x, int col) {
  f[x] = col;
  if (c1 == 0) return;
  for (int i(1); i <= (n); ++i)
    if (a[x][i]) {
      if (f[x] == f[i]) {
        c1 = 0;
        return;
      }
      if (f[i] == 0) dfs(i, -col);
    }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i(1); i <= (n); ++i)
    for (int j(1); j <= (n); ++j)
      if (i != j) a[i][j] = 1;
  for (int i(1); i <= (m); ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    l[i] = x, r[i] = y;
    a[x][y] = a[y][x] = 0;
  }
  for (int i(1); i <= (n); ++i) {
    bool fl = true;
    for (int j(1); j <= (n); ++j)
      if (a[i][j]) {
        fl = false;
        break;
      }
    if (fl) c[i] = 1;
  }
  c1 = 1;
  for (int i(1); i <= (n); ++i)
    if (c[i] == 0 && f[i] == 0) dfs(i, -1);
  for (int i(1); i <= (n); ++i)
    if (c1) {
      bool fl = true;
      for (int i(1); i <= (m); ++i) {
        if (abs(f[l[i]] - f[r[i]]) > 1) {
          fl = false;
          break;
        }
      }
      if (!fl) return 0 * puts("No");
      puts("Yes");
      for (int i(1); i <= (n); ++i) putchar(f[i] + 98);
      putchar(10);
      return 0;
    }
  puts("No");
  return 0;
}
