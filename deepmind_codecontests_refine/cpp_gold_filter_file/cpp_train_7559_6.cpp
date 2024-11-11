#include <bits/stdc++.h>
using namespace std;
int di[4] = {-1, 0, 1, 0};
int dj[4] = {0, 1, 0, -1};
char g[1010][1010];
int d[1010][1010], n, m;
int mark[1010][1010];
queue<pair<int, int> > q;
bool check(int i, int j) {
  if (i < 0 || i >= n || j < 0 || j >= m) return 0;
  return (g[i][j] == '.');
}
int main() {
  int k, i, j;
  scanf("%d", &n);
  scanf("%d", &m);
  scanf("%d", &k);
  for (i = 0; i < n; i++) scanf("%s", g[i]);
  int X1, Y1, X2, Y2;
  scanf("%d", &X1);
  scanf("%d", &Y1);
  scanf("%d", &X2);
  scanf("%d", &Y2);
  X1--;
  Y1--;
  X2--;
  Y2--;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++) d[i][j] = 1010 * 1010;
  memset(mark, 0, sizeof(mark));
  q.push(make_pair(X1, Y1));
  mark[X1][Y1] = 1;
  d[X1][Y1] = 0;
  while (!q.empty()) {
    pair<int, int> cur = q.front();
    q.pop();
    int x = cur.first, y = cur.second;
    for (int dir = 0; dir < 4; dir++) {
      int X1 = x, Y1 = y;
      for (i = 1; i <= k; i++) {
        X1 += di[dir];
        Y1 += dj[dir];
        if (!check(X1, Y1)) break;
        if (d[X1][Y1] <= d[x][y]) break;
        d[X1][Y1] = d[x][y] + 1;
        if (!mark[X1][Y1]) {
          mark[X1][Y1] = 1;
          q.push(make_pair(X1, Y1));
        }
      }
    }
  }
  if (!mark[X2][Y2])
    printf("-1\n");
  else
    printf("%d\n", d[X2][Y2]);
}
