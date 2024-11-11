#include <bits/stdc++.h>
using namespace std;
int ya[100010], yb[100010], l[100010];
int n, m, a, b;
double bridge, tmp, ans;
double dis(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
};
int main() {
  int y, p;
  int i, j, na, nb;
  double ans;
  scanf("%d%d%d%d", &n, &m, &a, &b);
  for (i = 1; i <= n; i++) scanf("%d", &ya[i]);
  for (i = 1; i <= m; i++) scanf("%d", &yb[i]);
  for (i = 1; i <= m; i++) scanf("%d", &l[i]);
  ans = -1;
  for (i = 1; i <= m; i++) {
    tmp = 1.0 * yb[i] / b * a;
    y = lower_bound(ya + 1, ya + n + 1, (int)tmp) - (ya + 1);
    for (j = max(y - 1, 1); j <= min(y + 1, n); j++) {
      bridge = dis(0, 0, a, ya[j]) + dis(a, ya[j], b, yb[i]) + l[i];
      if (bridge < ans || ans < 0) {
        ans = bridge;
        na = j;
        nb = i;
      }
    }
  }
  printf("%d %d\n", na, nb);
  return 0;
}
