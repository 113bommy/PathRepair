#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 10;
const int INF = 1e9 + 10;
int x[MAXN], y[MAXN];
int main() {
  int n;
  scanf("%d", &n);
  int maxx = -INF, minx = INF, maxy = -INF, miny = INF;
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &x[i], &y[i]);
    maxx = max(maxx, x[i]);
    minx = min(minx, x[i]);
    maxy = max(maxy, y[i]);
    miny = min(miny, y[i]);
  }
  int ans2 = 2 * (maxx - minx + maxy - miny);
  int ans1 = 0;
  for (int i = 1; i <= n; i++)
    ans1 = max(ans1, 2 * (max(maxx - x[i], x[i] - minx) +
                          max(maxy - y[i], y[i] - miny)));
  printf("%d ", ans1);
  for (int i = 4; i <= n; i++) printf("%d%c", ans2, " \n"[i == n]);
  return 0;
}
