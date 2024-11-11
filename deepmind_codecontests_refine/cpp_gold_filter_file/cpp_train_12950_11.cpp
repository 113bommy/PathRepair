#include <bits/stdc++.h>
using namespace std;
int n, m, ans, a[35][35], b[35][35];
int get(int x, int y) { return b[x][y] ? -a[x][y] : a[x][y]; }
int calc(int x, int y, int o) {
  b[x][y] = o, b[x + m][y] = o ^ b[m - 1][y], b[x][y + m] = o ^ b[x][m - 1],
  b[x + m][y + m] = o ^ b[x][m - 1] ^ b[m - 1][y + m];
  return get(x, y) + get(x + m, y) + get(x, y + m) + get(x + m, y + m);
}
int sol(int x, int o) {
  b[x][m - 1] = o;
  b[m + x][m - 1] = b[x][m - 1] ^ b[m - 1][m - 1];
  int res = get(x, m - 1) + get(m + x, m - 1);
  for (int i = (0); i <= (m - 2); ++i) res += max(calc(x, i, 0), calc(x, i, 1));
  return res;
}
int main() {
  scanf("%d", &n);
  for (int i = (0); i <= (n - 1); ++i)
    for (int j = (0); j <= (n - 1); ++j) scanf("%d", &a[i][j]);
  m = (n + 1) / 2;
  for (int i = (0); i <= ((1 << m) - 1); ++i) {
    for (int j = (0); j <= (m - 1); ++j) b[m - 1][j] = i >> j & 1;
    for (int j = (0); j <= (m - 1); ++j)
      b[m - 1][m + j] = b[m - 1][j] ^ b[m - 1][m - 1];
    int res = 0;
    for (int j = (0); j <= (n - 1); ++j) res += get(m - 1, j);
    for (int j = (0); j <= (m - 2); ++j) res += max(sol(j, 0), sol(j, 1));
    ((void)0);
    ans = max(ans, res);
  }
  printf("%d\n", ans);
  return 0;
}
