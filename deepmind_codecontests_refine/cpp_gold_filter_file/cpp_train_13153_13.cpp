#include <bits/stdc++.h>
using namespace std;
const int M = 5555;
const int N = 205;
int col[2][M][N];
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
int n, m, k, s;
int sz[2][N], id[2][N];
int Id[M][M], ans[M];
int main() {
  scanf("%d%d%d%d", &n, &m, &k, &s);
  if (s == 1) {
    puts("0");
    for (int i = (int)(1); i <= (int)(k); i++) printf("1 ");
    return 0;
  }
  int nd = 0, mx = 0;
  for (int i = (int)(1); i <= (int)(n); i++) sz[0][i] = s;
  for (int i = (int)(1); i <= (int)(m); i++) sz[1][i] = s;
  for (int i = (int)(1); i <= (int)(k); i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (sz[0][x] == s) sz[0][x] = 0, id[0][x] = ++nd;
    sz[0][x]++;
    x = id[0][x];
    if (sz[1][y] == s) sz[1][y] = 0, id[1][y] = ++nd;
    sz[1][y]++;
    y = id[1][y];
    Id[x][y] = i;
    int c0 = 1, c1 = 1;
    for (; col[0][x][c0]; c0++)
      ;
    for (; col[1][y][c1]; c1++)
      ;
    mx = max(mx, max(c0, c1));
    if (c0 == c1) {
      col[0][x][c0] = y;
      col[1][y][c0] = x;
    } else
      dfs(0, x, y, c0, c1);
  }
  int mn = 0;
  for (int i = (int)(1); i <= (int)(n); i++) mn += (sz[0][i] != s);
  for (int i = (int)(1); i <= (int)(m); i++) mn += (sz[1][i] != s);
  printf("%d\n", mn);
  for (int i = (int)(1); i <= (int)(nd); i++)
    for (int j = (int)(1); j <= (int)(mx); j++)
      if (col[0][i][j]) ans[Id[i][col[0][i][j]]] = j;
  for (int i = (int)(1); i <= (int)(k); i++) printf("%d ", ans[i]);
}
