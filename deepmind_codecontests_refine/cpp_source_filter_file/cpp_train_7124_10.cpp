#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
struct ppp {
  double l;
  int sta;
} q[21000 * 25 * 6];
int sum, ans, x, y, r, tot, n, i, j, d;
void add_(double x, double y) {
  q[++tot].l = x;
  q[tot].sta = 1;
  q[++tot].l = y;
  q[tot].sta = -1;
}
void add(double l, double r) {
  if (l < -pi) add_(l + 2 * pi, pi), l = -pi;
  if (r > pi) add_(-pi, r - 2 * pi), r = pi;
  add_(l, r);
}
bool cmp(const ppp& a, const ppp& b) {
  if (abs(a.l - b.l) < 1e-8) return a.sta > b.sta;
  return a.l < b.l;
}
int main() {
  scanf("%d%d", &n, &d);
  for (i = 1; i <= n; ++i) {
    scanf("%d%d%d", &x, &y, &r);
    double dis = sqrt((x) * (x) + (y) * (y));
    int p = dis / d;
    for (j = p - 1; j <= p + 21; ++j) {
      double R = j * d;
      if (R + r < dis || R > dis + r) continue;
      double t = atan2(y, x),
             delta =
                 acos(((R) * (R) + (dis) * (dis) - (r) * (r)) / 2 / R / dis);
      add(t - delta, t + delta);
    }
  }
  sort(q + 1, q + tot + 1, cmp);
  sum = 0;
  for (i = 1; i <= tot; ++i) {
    sum += q[i].sta;
    ans = max(ans, sum);
  }
  printf("%d\n", ans);
}
