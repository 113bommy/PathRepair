#include <bits/stdc++.h>
using namespace std;
int n, m, a[11][11], ans, res, aw[11][11],
    px[4][5] = {{-1, -1, -1, 1, 0},
                {-1, 0, 1, 0, 0},
                {1, 1, 1, -1, 0},
                {1, 0, -1, 0, 0}},
    py[4][5] = {{-1, 0, 1, 0, 0},
                {1, 1, 1, -1, 0},
                {1, 0, -1, 0, 0},
                {-1, -1, -1, 1, 0}};
inline bool check(int x, int y, int k) {
  for (int l = 0; l < 5; l++)
    if (a[x + px[k][l]][y + py[k][l]]) return 0;
  return 1;
}
void dfs(int cur, int x, int y) {
  if (cur > ans) {
    ans = cur;
    memcpy(aw, a, sizeof(a));
  }
  if (res / 5 + cur <= ans) return;
  if (x == n) return;
  if (y == m) {
    dfs(cur, x + 1, 2);
    return;
  }
  if (!a[x - 1][y - 1]) res--;
  for (int k = 0; k < 4; k++) {
    bool ok = check(x, y, k);
    if (ok) {
      for (int l = 0; l < 5; l++) a[x + px[k][l]][y + py[k][l]] = 65 + cur;
      res -= 5;
      dfs(cur + 1, x, y + 1);
      res += 5;
    }
    if (ok)
      for (int l = 0; l < 5; l++) a[x + px[k][l]][y + py[k][l]] = 0;
  }
  dfs(cur, x, y + 1);
  if (!a[x - 1][y - 1]) res++;
}
int main() {
  scanf("%d%d", &n, &m);
  res = n * m;
  dfs(0, 2, 2);
  printf("%d\n", ans);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) {
      putchar(aw[i][j] ? aw[i][j] : '.');
      if (j == m) putchar('\n');
    }
  return 0;
}
