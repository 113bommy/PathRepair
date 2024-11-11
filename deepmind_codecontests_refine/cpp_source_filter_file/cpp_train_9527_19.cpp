#include <bits/stdc++.h>
char cubo[12][12][12];
int k, m, n, x, y;
int out = 0;
void dfs(int z, int x, int y) {
  out += 1;
  cubo[z][x][y] = '-';
  if (z > 0 && cubo[z - 1][x][y] == '.') {
    dfs(z - 1, x, y);
  }
  if (z < k - 1 && cubo[z + 1][x][y] == '.') {
    dfs(z + 1, x, y);
  }
  if (x > 0 && cubo[z][x - 1][y] == '.') {
    dfs(z, x - 1, y);
  }
  if (x < m - 1 && cubo[z][x + 1][y] == '.') {
    dfs(z, x + 1, y);
  }
  if (y > 0 && cubo[z][x][y - 1] == '.') {
    dfs(z, x, y - 1);
  }
  if (y < n - 1 && cubo[z][x][y + 1] == '.') {
    dfs(z, x, y + 1);
  }
}
int main(void) {
  int i, j;
  scanf(" %d %d %d", &k, &m, &n);
  for (i = 0; i < k; i++) {
    for (j = 0; j < n; j++) {
      scanf(" %s", cubo[i][j]);
    }
  }
  scanf(" %d %d", &x, &y);
  dfs(0, x - 1, y - 1);
  printf("%d\n", out);
  return 0;
}
