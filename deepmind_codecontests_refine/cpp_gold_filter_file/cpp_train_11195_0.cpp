#include <bits/stdc++.h>
using namespace std;
double sqr(double x) { return x * x; }
double dis(double x1, double y1, double x2, double y2) {
  return sqrt(sqr(x1 - x2) + sqr(y1 - y2));
}
double d[500010], da[500010], db[500010];
int tx, ty, ax, ay, bx, by, n;
int main() {
  scanf("%d%d%d%d%d%d", &ax, &ay, &bx, &by, &tx, &ty);
  scanf("%d", &n);
  double s = 0;
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    d[i] = dis(tx, ty, x, y);
    s += d[i] * 2;
    da[i] = dis(ax, ay, x, y);
    db[i] = dis(bx, by, x, y);
  }
  double ans = 1e100, sa = 0, sb = 0;
  for (int i = 1; i <= n; i++) {
    ans = min(ans, s - d[i] + sa + db[i]);
    ans = min(ans, s - d[i] + sb + da[i]);
    sa = min(sa, da[i] - d[i]);
    sb = min(sb, db[i] - d[i]);
  }
  printf("%.15lf\n", ans);
  return 0;
}
