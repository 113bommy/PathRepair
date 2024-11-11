#include <bits/stdc++.h>
const int maxn = 105;
char a[maxn][maxn];
int n, m;
int d[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
void dfs(int x, int y) {
  a[x][y] = '.';
  for (int i = 0; i < 4; ++i) {
    int tx = x + d[i][0], ty = y + d[i][1];
    if (tx >= 0 && tx < n && ty >= 0 && ty < m && a[tx][ty] != '.') {
      dfs(tx, ty);
    }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    scanf("%s", a[i]);
  }
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (a[i][j] != '.') {
        ++ans;
        dfs(i, j);
      }
    }
  }
  printf("%d\n", ans);
  return 0;
}
