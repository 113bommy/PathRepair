#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-10;
const int maxN = 100005;
int sa[maxN], sb[maxN], n, m, v;
double x[maxN], y[maxN], a[maxN], ax[maxN];
bool cmpA(int i, int j) { return a[i] < a[j] - eps; }
bool cmpX(int i, int j) { return x[i] < x[j] - eps; }
void init() {
  scanf("%d%d", &n, &v);
  for (int i = 1; i <= n; ++i) scanf("%lf", a + i);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) scanf("%lf%lf", x + i, y + i);
  for (int i = 1; i <= n; ++i) sa[i] = i;
  sort(sa + 1, sa + 1 + n, cmpA);
  for (int i = 1; i <= m; ++i) sb[i] = i;
  sort(sb + 1, sb + 1 + m, cmpX);
}
double getY(double an, double x) {
  return x * tan(an) - 4.9 * x * x / v / v / (cos(an) * cos(an));
}
bool cut(int p, double an) {
  double ay = getY(an, x[p]);
  return ay <= y[p] + eps;
}
void work() {
  double maxX = 0;
  int p = 1;
  bool flag;
  for (int t = 1; t <= n; ++t) {
    int i = sa[t];
    maxX = double(v) * v * sin(2 * a[i]) / 9.8;
    flag = 0;
    while (p <= n && (x[sb[p]] - maxX) <= eps) {
      if (!cut(sb[p], a[i]))
        ++p;
      else {
        flag = 1;
        break;
      }
    }
    if (flag)
      ax[i] = x[sb[p]];
    else
      ax[i] = maxX;
  }
  for (int i = 1; i <= n; ++i) {
    double y = getY(a[i], ax[i]);
    printf("%.6lf %.6lf\n", ax[i], y);
  }
}
int main() {
  init();
  work();
  return 0;
}
