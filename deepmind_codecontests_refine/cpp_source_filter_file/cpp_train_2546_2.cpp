#include <bits/stdc++.h>
using namespace std;
const double g = 9.8;
int n, m;
double v;
struct node {
  double jiao, sin, cos, yuan;
  int id;
} a[10005];
struct qiang {
  double x, y;
} b[100005], ans[10005];
bool cmp(node aa, node bb) { return aa.jiao < bb.jiao; }
bool cmpp(qiang aa, qiang bb) { return aa.x < bb.x; }
int ok(int aa, int bb) {
  double vx = v * a[aa].cos;
  double tim = b[bb].x / vx;
  double yy = tim * v * a[aa].sin - g * tim * tim / 2.;
  return yy > b[bb].y;
}
int main() {
  scanf("%d%lf", &n, &v);
  for (int i = 1; i <= n; ++i) {
    scanf("%lf", &a[i].jiao);
    a[i].id = i;
    a[i].sin = sin(a[i].jiao);
    a[i].cos = cos(a[i].jiao);
    a[i].yuan = 2. * v * v * a[i].sin * a[i].cos / g;
  }
  sort(a + 1, a + n + 1, cmp);
  scanf("%d", &m);
  for (int i = 1; i <= m; ++i) scanf("%lf%lf", &b[i].x, &b[i].y);
  sort(b + 1, b + m + 1, cmpp);
  int oo = 1;
  for (int i = 1; i <= n; ++i) {
    while (oo <= n && b[oo].x <= a[i].yuan && ok(i, oo)) oo++;
    if (oo == n + 1 || a[i].yuan <= b[oo].x) {
      double vx = a[i].cos * v;
      double tim = 2. * v * a[i].sin / g;
      ans[a[i].id].x = vx * tim;
      ans[a[i].id].y = 0;
    } else {
      double vx = a[i].cos * v;
      double tim = b[oo].x / vx;
      ans[a[i].id].x = b[oo].x;
      ans[a[i].id].y = tim * v * a[i].sin - g * tim * tim / 2.;
    }
  }
  for (int i = 1; i <= n; ++i) printf("%.10lf %.10lf\n", ans[i].x, ans[i].y);
  return 0;
}
