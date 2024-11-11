#include <bits/stdc++.h>
using namespace std;
const int N = 1010;
int a, b, m;
int id[N][N];
int edge[2][N][N];
int ans, color[N];
int c[2];
void dfs(int p, int x, int y) {
  int next = edge[!p][y][c[p]];
  edge[p][x][c[p]] = y;
  edge[!p][y][c[p]] = x;
  int i = p ? id[y][x] : id[x][y];
  color[i] = c[p];
  if (next == 0) {
    edge[!p][y][c[!p]] = 0;
    return;
  }
  dfs(!p, y, next);
}
int main() {
  scanf("%d%d%d", &a, &b, &m);
  for (int i = 1, x, y; i <= m; ++i) {
    scanf("%d%d", &x, &y);
    id[x][y] = i;
    c[0] = c[1] = 1;
    while (edge[0][x][c[0]]) ++c[0];
    while (edge[1][y][c[1]]) ++c[1];
    ans = max(ans, max(c[0], c[1]));
    if (c[0] != c[1])
      dfs(0, x, y);
    else {
      edge[0][x][c[0]] = y;
      edge[1][y][c[0]] = x;
      color[i] = c[0];
    }
  }
  printf("%d\n", ans);
  for (int i = 1; i <= m; ++i) printf("%d ", color[i]);
  puts("");
  return 0;
}
