#include <bits/stdc++.h>
using namespace std;
const long double eps = 1e-6, Pi = acos(-1);
const int maxn = 1e4 + 10;
long double x[maxn], y[maxn], angle[maxn], cangle, dis[maxn];
int n, q;
pair<long double, long double> get_center() {
  pair<long double, long double> res;
  res.first = 0;
  res.second = 0;
  long double area = 0;
  for (int i = 0; i < n; i++) {
    int a = i, b = (i + 1) % n;
    long double temp = x[a] * y[b] - x[b] * y[a];
    area += temp;
    res.first += (x[a] + x[b]) * temp;
    res.second += (y[a] + y[b]) * temp;
  }
  area *= 0.5;
  res.first /= (area * 6);
  res.second /= (area * 6);
  return res;
}
long double DIS(const pair<long double, long double>& a,
                const pair<long double, long double>& b) {
  return sqrtl((a.first - b.first) * (a.first - b.first) +
               (a.second - b.second) * (a.second - b.second));
}
pair<long double, long double> get_top(const pair<long double, long double>& ce,
                                       int ind) {
  pair<long double, long double> res;
  res.first = ce.first + dis[ind] * cosl(angle[ind] + cangle);
  res.second = ce.second + dis[ind] * sinl(angle[ind] + cangle);
  return res;
}
int main() {
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) {
    double p, q;
    scanf("%lf%lf", &p, &q);
    x[i] = p;
    y[i] = q;
  }
  long double ox = x[0], oy = y[0];
  int a = 0, b = 1;
  for (int i = 0; i < n; i++) x[i] -= ox, y[i] -= oy;
  pair<long double, long double> c = get_center();
  for (int i = 0; i < n; i++) {
    dis[i] = DIS(c, pair<long double, long double>{x[i], y[i]});
    angle[i] = atan2l(y[i] - c.second, x[i] - c.first);
    if (angle[i] < 0) angle[i] += 2 * Pi;
  }
  int cmd;
  pair<long double, long double> top, nxt;
  while (q--) {
    scanf("%d", &cmd);
    if (cmd == 1) {
      int f, t;
      scanf("%d%d", &f, &t);
      f--, t--;
      if (f == a) {
        a = t;
        top = get_top(c, b);
        nxt = pair<long double, long double>(top.first, top.second - dis[b]);
      } else {
        b = t;
        top = get_top(c, a);
        nxt = pair<long double, long double>(top.first, top.second - dis[b]);
      }
      cangle += -Pi / 2 - atan2l(c.second - top.second, c.first - top.first);
      while (cangle < 0) cangle += 2 * Pi;
      while (cangle > 2 * Pi) cangle -= 2 * Pi;
      c = nxt;
    } else {
      int x;
      scanf("%d", &x);
      top = get_top(c, x - 1);
      printf("%f %f\n", (double)(top.first + ox), double(top.second + oy));
    }
  }
  return 0;
}
