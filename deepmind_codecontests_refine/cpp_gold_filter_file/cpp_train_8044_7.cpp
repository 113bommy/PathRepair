#include <bits/stdc++.h>
using namespace std;
int n, m, best, a[9][9], ans[9][9];
const int f[4][5][2] = {{{-1, -1}, {-1, 0}, {-1, 1}, {0, 0}, {1, 0}},
                        {{-1, 1}, {0, -1}, {0, 0}, {0, 1}, {1, 1}},
                        {{-1, 0}, {0, 0}, {1, -1}, {1, 0}, {1, 1}},
                        {{-1, -1}, {0, -1}, {0, 0}, {0, 1}, {1, -1}}};
bool check(int x, int y, int k) {
  for (int i = 0; i < 5; i++) {
    int nx = x + f[k][i][0];
    int ny = y + f[k][i][1];
    if (nx < 0 || nx >= n || ny < 0 || ny >= m || a[nx][ny] > 0) return false;
  }
  return true;
}
void fill(int x, int y, int k, int c) {
  for (int i = 0; i < 5; i++) a[x + f[k][i][0]][y + f[k][i][1]] = c;
}
void dfs(int r, int s) {
  int i, j, k;
  if (s > best) {
    best = s;
    for (i = 0; i < n; i++)
      for (j = 0; j < m; j++) ans[i][j] = a[i][j];
  }
  for (i = r; i < n - 1; i++) {
    int empty = 0;
    for (j = i; j < n; j++)
      for (k = 0; k < m; k++)
        if (a[j][k] == 0) empty++;
    if (s + empty / 5 <= best) return;
    for (j = 1; j < m - 1; j++)
      for (k = 0; k < 4; k++)
        if (check(i, j, k)) {
          fill(i, j, k, s + 1);
          dfs(i, s + 1);
          fill(i, j, k, 0);
        }
  }
}
int main() {
  int i, j;
  scanf("%d%d", &n, &m);
  if (n < 3 || m < 3) {
    printf("0\n");
    for (i = 0; i < n; i++) {
      for (j = 0; j < m; j++) printf(".");
      printf("\n");
    }
    return 0;
  }
  dfs(1, 0);
  printf("%d\n", best);
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++)
      if (ans[i][j] == 0)
        printf(".");
      else
        printf("%c", 'A' + ans[i][j] - 1);
    printf("\n");
  }
  return 0;
}
