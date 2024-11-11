#include <bits/stdc++.h>
using namespace std;
struct wall {
  double x, y;
  wall() {}
  wall(double x, double y) : x(x), y(y) {}
};
struct tx {
  double d;
  int v;
  tx() {}
  tx(double d, int v) : d(d), v(v) {}
};
bool cmp2(const tx& p1, const tx& p2) { return p1.d < p2.d; }
bool cmp(const wall& p1, const wall& p2) { return p1.x < p2.x; }
int dcmp(double x) { return fabs(x) < 1e-11 ? 0 : (x > 0 ? 1 : -1); }
wall w[2000001];
wall ans[2000001];
int n, m;
int f[2000001];
double V;
tx ang[2000001];
int main() {
  scanf("%d %lf", &n, &V);
  for (int i = 1; i <= n; i++) {
    scanf("%lf", &ang[i].d);
    ang[i].v = i;
  }
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) scanf("%lf %lf", &w[i].x, &w[i].y);
  sort(w + 1, w + 1 + m, cmp);
  sort(ang + 1, ang + 1 + n, cmp2);
  int tp = 1;
  for (int i = 1; i <= n; i++) {
    int flag = 0;
    if (tp > m) ans[i] = wall(V * V * sin(2 * ang[i].d) / 9.8, 0.0);
    while (tp <= m) {
      double tmpx = (w[tp].x * sin(2 * ang[i].d) / 2.0) -
                    (9.8 * w[tp].x * w[tp].x / (2.0 * V * V));
      tmpx /= cos(ang[i].d) * cos(ang[i].d);
      if (tmpx <= 0.0) {
        ans[i] = wall(V * V * sin(2 * ang[i].d) / 9.8, 0.0), flag = 1;
        break;
      } else if (!dcmp(tmpx - w[tp].y) || tmpx < w[tp].y) {
        ans[i] = wall(w[tp].x, tmpx);
        flag = 1;
        break;
      } else
        tp++;
    }
    if (!flag) ans[i] = wall(V * V * sin(2 * ang[i].d) / 9.8, 0.0);
  }
  for (int i = 1; i <= n; i++) f[ang[i].v] = i;
  for (int i = 1; i <= n; i++)
    printf("%.9lf %.9lf\n", ans[f[i]].x, ans[f[i]].y);
  return 0;
}
