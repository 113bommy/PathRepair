#include <bits/stdc++.h>
using namespace std;
void up(int c[][1010], int s[][1010], int n, int x, int y) {
  c[x][y] = 1 - c[x][y];
  for (int i = 1; i <= n; ++i) s[i][y] = c[i][y] * (s[i - 1][y] + 1);
}
vector<int> g[1010];
int que(int s[][1010], int m, int x, int y) {
  int k = s[x][y];
  for (int i = 0; i <= k; ++i) g[i].clear();
  for (int i = 1; i <= m; ++i) g[s[x][i]].push_back(i);
  int lef = 0, rig = m + 1, res = k;
  for (int i = 0; i < k; ++i) {
    for (int j = 0; j < g[i].size(); ++j) {
      if (g[i][j] < y)
        lef = max(lef, g[i][j]);
      else
        rig = min(rig, g[i][j]);
    }
    res = max(res, (i + 1) * (rig - lef - 1));
  }
  return res;
}
void sum(int c[][1010], int s[][1010], int n, int m) {
  for (int j = 1; j <= m; ++j)
    for (int i = 1; i <= n; ++i) s[i][j] = (s[i - 1][j] + 1) * c[i][j];
}
int n, m, q;
int c[4][1010][1010];
int s[4][1010][1010];
void update(int x, int y) {
  up(c[0], s[0], n, x, y);
  up(c[1], s[1], n, n + 1 - x, y);
  up(c[2], s[2], m, y, x);
  up(c[3], s[3], m, m + 1 - y, x);
}
int query(int x, int y) {
  int res = 0;
  res = max(que(s[0], m, x, y), res);
  res = max(que(s[1], m, n + 1 - x, y), res);
  res = max(que(s[2], n, y, x), res);
  res = max(que(s[3], n, m + 1 - y, x), res);
  return res;
}
void init() {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) scanf("%d", &c[0][i][j]);
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) c[1][n + 1 - i][j] = c[0][i][j];
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j) c[2][j][i] = c[0][i][j];
  for (int i = 1; i <= m; ++i)
    for (int j = 1; j <= n; ++j) c[3][m + 1 - i][j] = c[2][i][j];
  sum(c[0], s[0], n, m);
  sum(c[1], s[1], n, m);
  sum(c[2], s[2], m, n);
  sum(c[3], s[3], m, n);
}
int main() {
  scanf("%d %d %d", &n, &m, &q);
  init();
  int k, x, y;
  while (q--) {
    scanf("%d %d %d", &k, &x, &y);
    if (k == 1)
      update(x, y);
    else
      printf("%d\n", query(x, y));
  }
  return 0;
}
