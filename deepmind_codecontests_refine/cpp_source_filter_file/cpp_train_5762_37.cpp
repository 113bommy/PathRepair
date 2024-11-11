#include <bits/stdc++.h>
using namespace std;
int n, a[2002][2002], u[2002][2002], cnt1, cnt2, cnt, k, b[2002][2002];
int Maxx, Maxy, Minx, Miny;
pair<int, int> c[4100002];
inline void dfs(int i, int j) {
  u[i][j] = true;
  c[++k] = make_pair(i, j);
  Minx = min(Minx, i);
  Maxx = max(Maxx, i);
  Miny = min(Miny, j);
  Maxy = max(Maxy, j);
  if (i > 1 && !u[i - 1][j] && a[i - 1][j]) dfs(i - 1, j);
  if (i < n && !u[i + 1][j] && a[i + 1][j]) dfs(i + 1, j);
  if (j > 1 && !u[i][j - 1] && a[i][j - 1]) dfs(i, j - 1);
  if (j < n && !u[i][j + 1] && a[i][j + 1]) dfs(i, j + 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &a[i][j]);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (a[i][j] && !u[i][j]) {
        k = 0;
        Miny = 1e9;
        Minx = 1e9;
        Maxy = 0;
        Maxx = 0;
        dfs(i, j);
        pair<double, double> o =
            make_pair((Maxx + Minx) / 2.0, (Maxy + Miny) / 2.0);
        double Max = 0;
        for (int l = 1; l <= k; ++l) {
          Max =
              max(Max, (o.first - c[l].first) * (o.first - c[l].first) +
                           (o.second - c[l].second) * (o.second - c[l].second));
        }
        if (k < 2 * Max)
          cnt2++;
        else
          cnt1++;
      }
    }
  }
  printf("%d %d", cnt1, cnt2);
  return 0;
}
