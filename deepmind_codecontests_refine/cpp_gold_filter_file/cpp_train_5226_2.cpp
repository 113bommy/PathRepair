#include <bits/stdc++.h>
using namespace std;
const int N = 2005;
int col[2][N][N];
int n, m, k, x, y, mx, nd;
int S[N][2], id[N][2];
int Id[N][N], ans[N];
void dfs(int p, int x, int y, int c0, int c1) {
  int t = col[p ^ 1][y][c0];
  col[p][x][c0] = y;
  col[p ^ 1][y][c0] = x;
  if (!t) {
    col[p ^ 1][y][c1] = 0;
    return;
  }
  dfs(p ^ 1, y, t, c1, c0);
}
int main() {
  scanf("%d%d%d", &n, &m, &k);
  if (k == 1) {
    for (int i = (int)(1); i <= (int)(m); i++) printf("1\n");
    return 0;
  }
  for (int i = (int)(1); i <= (int)(n); i++) scanf("%*d");
  for (int i = (int)(1); i <= (int)(n); i++) S[i][0] = S[i][1] = k;
  for (int i = (int)(1); i <= (int)(m); i++) {
    scanf("%d%d", &x, &y);
    if (S[x][0] == k) S[x][0] = 0, id[x][0] = ++nd;
    if (S[y][1] == k) S[y][1] = 0, id[y][1] = ++nd;
    ++S[x][0];
    ++S[y][1];
    x = id[x][0];
    y = id[y][1];
    Id[x][y] = i;
    int c0 = 1, c1 = 1;
    for (; col[0][x][c0]; ++c0)
      ;
    for (; col[1][y][c1]; ++c1)
      ;
    mx = max(mx, max(c0, c1));
    if (!col[1][y][c0]) {
      col[0][x][c0] = y;
      col[1][y][c0] = x;
      continue;
    }
    if (!col[0][x][c1]) {
      col[0][x][c1] = y;
      col[1][y][c1] = x;
      continue;
    }
    dfs(0, x, y, c0, c1);
  }
  for (int i = (int)(1); i <= (int)(nd); i++)
    for (int j = (int)(1); j <= (int)(k); j++)
      if (col[0][i][j]) ans[Id[i][col[0][i][j]]] = j;
  for (int i = (int)(1); i <= (int)(m); i++) printf("%d\n", ans[i]);
}
