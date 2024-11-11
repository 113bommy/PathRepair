#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
const int MOD = 1e9 + 7;
const int N = 5e2 + 10;
int n, m, a[N][N], f[12][N][N], g[N][N];
char s[N];
int get(int xa, int ya, int xb, int yb) {
  return g[xb][yb] + g[xa - 1][ya - 1] - g[xa - 1][yb] - g[xb][ya - 1];
}
void prepare() {
  scanf("%d%d", &n, &m);
  for (auto i = 1; i <= n; i++) {
    scanf("\n%s", s);
    for (auto j = 1; j <= m; j++) a[i][j] = (s[j - 1] == '*');
  }
}
bool check(int st, int k, int x, int y) {
  if (st)
    return (get(x, y, x + (1 << k) - 1, y + (1 << k) - 1) == (1 << k << 1));
  return f[k][x][y];
}
int solve() {
  for (auto i = 1; i <= n; i++)
    for (auto j = 1; j <= m; j++)
      g[i][j] = g[i][j - 1] + g[i - 1][j] - g[i - 1][j - 1] + a[i][j];
  int ans = 0;
  for (auto st = 1; st < 1 << 4; st++) {
    for (auto i = 1; i <= n - 1; i++)
      for (auto j = 1; j <= m - 1; j++)
        f[1][i][j] = (a[i][j] + 2 * a[i][j + 1] + 4 * a[i + 1][j] +
                          8 * a[i + 1][j + 1] ==
                      st);
    for (auto k = 1; k <= 9; k++)
      for (auto i = 1; i <= n - (1 << (k + 1)) + 1; i++)
        for (auto j = 1; j <= m - (1 << (k + 1)) + 1; j++) {
          f[k + 1][i][j] = check(st & 1, k, i, j) &
                           check(st & 2, k, i, j + (1 << k)) &
                           check(st & 4, k, i + (1 << k), j) &
                           check(st & 8, k, i + (1 << k), j + (1 << k));
          ans += f[k + 1][i][j];
        }
  }
  return ans;
}
int main() {
  prepare();
  cout << solve();
}
