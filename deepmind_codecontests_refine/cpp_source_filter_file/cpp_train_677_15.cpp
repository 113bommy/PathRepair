#include <bits/stdc++.h>
using namespace std;
int n, m, u, v, d[3010][3010], p[3010][3], w[3010][3], ans, q[3010];
pair<pair<int, int>, pair<int, int> > A;
vector<int> a[3010];
void bfs(int x) {
  int he = 0, ta = 1;
  q[1] = x;
  d[x][x] = 0;
  while (he < ta) {
    int y = q[++he];
    for (int i = 0; i < a[y].size(); i++)
      if (d[x][a[y][i]] == -1e9) {
        d[x][a[y][i]] = d[x][y] + 1;
        q[++ta] = a[y][i];
      }
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &u, &v);
    a[u].push_back(v);
  }
  for (int i = 0; i <= n; i++)
    for (int j = 0; j <= n; j++) d[i][j] = -1e9;
  for (int i = 1; i <= n; i++) bfs(i);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) {
        if (d[j][i] > d[p[i][2]][i]) p[i][2] = j;
        if (d[p[i][2]][i] > d[p[i][1]][i]) swap(p[i][1], p[i][2]);
        if (d[p[i][1]][i] > d[p[i][0]][i]) swap(p[i][1], p[i][0]);
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (i != j) {
        if (d[i][j] > d[i][p[i][2]]) w[i][2] = j;
        if (d[i][w[i][2]] > d[i][w[i][1]]) swap(w[i][1], w[i][2]);
        if (d[i][w[i][1]] > d[i][w[i][0]]) swap(w[i][1], w[i][0]);
      }
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (d[i][j] > -1e9 && i != j) {
        for (int k = 0; k <= 2; k++)
          for (int l = 0; l <= 2; l++)
            if (d[i][j] + d[p[i][k]][i] + d[j][w[j][l]] > ans && p[i][k] != i &&
                p[i][k] != j && p[i][k] != w[j][l] && w[j][l] != i &&
                w[j][l] != j)
              ans = d[i][j] + d[p[i][k]][i] + d[j][w[j][l]],
              A = make_pair(make_pair(p[i][k], i), make_pair(j, w[j][l]));
      }
  printf("%d %d %d %d\n", A.first.first, A.first.second, A.second.first,
         A.second.second);
  return 0;
}
