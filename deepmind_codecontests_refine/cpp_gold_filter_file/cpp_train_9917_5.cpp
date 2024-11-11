#include <bits/stdc++.h>
using namespace std;
const int N = 255;
int n, m;
int a[N][N], b[N][N], w[N * N], l[N * N];
queue<pair<int, int> > q;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++) scanf("%d", &a[i][j]);
  for (int i = 1; i <= n; i++) {
    int t = 0;
    for (int j = 1; j <= m; j++) t = max(t, a[i][j]);
    l[t] = 1;
  }
  for (int j = 1; j <= m; j++) {
    int t = 0;
    for (int i = 1; i <= n; i++) t = max(t, a[i][j]);
    w[t] = 1;
  }
  int x = 0, y = 0;
  for (int i = n * m; i; i--) {
    x += l[i], y += w[i];
    if (l[i] || w[i])
      b[x][y] = i;
    else
      b[q.front().first][q.front().second] = i, q.pop();
    if (l[i])
      for (int i = y - 1; i; i--) q.push({x, i});
    if (w[i])
      for (int i = x - 1; i; i--) q.push({i, y});
  }
  for (int i = 1; i <= n; i++, puts(""))
    for (int j = 1; j <= m; j++) printf("%d ", b[i][j]);
}
