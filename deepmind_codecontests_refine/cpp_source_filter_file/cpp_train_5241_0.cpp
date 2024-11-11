#include <bits/stdc++.h>
using namespace std;
const int MAX = 2000 + 10;
const int MAXDIST = 3;
const double s = 0.8;
int walk[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, a[MAX][MAX], b[MAX][MAX];
queue<pair<int, int> > q;
int sum, maxd;
void BFS(int sx, int sy) {
  int i;
  pair<int, int> u, v;
  q.push(make_pair(sx, sy));
  a[sx][sy] = 0;
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (i = 0; i < 4; ++i) {
      v = make_pair(u.first + walk[i][0], u.second + walk[i][1]);
      if (a[v.first][v.second]) {
        ++sum;
        maxd = max(
            (v.first - sx) * (v.first - sx) + (v.second - sy) * (v.second - sy),
            maxd);
        q.push(v);
        a[v.first][v.second] = 0;
      }
    }
  }
}
int main() {
  int i, j, k, l;
  scanf("%d", &n);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) scanf("%d", &a[i][j]);
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) {
      int oo = 0;
      for (k = -MAXDIST; k <= MAXDIST; ++k)
        for (l = -MAXDIST; l <= MAXDIST; ++l)
          if (i + k <= n && i + k >= 1 && j + l <= n && j + l >= 1) {
            if (a[i + k][j + l]) ++b[i][j];
            ++oo;
          }
      b[i][j] = ((double)b[i][j] / oo > 0.4);
    }
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j) a[i][j] = b[i][j];
  int ans1 = 0, ans2 = 0;
  for (i = 1; i <= n; ++i)
    for (j = 1; j <= n; ++j)
      if (a[i][j]) {
        sum = 0, maxd = 0;
        BFS(i, j);
        if (sum < 100) continue;
        double r1 = sqrt(sum / M_PI) * 2;
        double r2 = sqrt(sum * 2);
        double r = sqrt(maxd);
        if (abs(r - r1) / r < 0.05)
          ++ans1;
        else
          ++ans2;
      }
  printf("%d %d\n", ans1, ans2);
  return 0;
}
