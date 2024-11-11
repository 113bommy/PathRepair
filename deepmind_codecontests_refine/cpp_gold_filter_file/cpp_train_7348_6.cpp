#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
const double ep = 1e-4;
int n, Q, xxx, yyy;
double area[50050], Area;
struct Pnt {
  double x, y;
  Pnt(double x = 0, double y = 0) : x(x), y(y){};
  void input() {
    scanf("%d %d", &xxx, &yyy);
    x = xxx, y = yyy;
  }
  void output() { printf("%lf %lf\n", x, y); }
} p[50050], q;
struct line {
  double a, b, c;
  line(double a = 0, double b = 0, double c = 0) : a(a), b(b), c(c){};
  void rev() { a = -a, b = -b, c = -c; }
} seg[50050], now;
line get_equation(Pnt a, Pnt b) {
  return line(b.y - a.y, a.x - b.x, a.y * b.x - a.x * b.y);
}
Pnt intersect(line u, line v) {
  double d = u.a * v.b - u.b * v.a;
  return Pnt((u.b * v.c - u.c * v.b) / d, (u.c * v.a - u.a * v.c) / d);
}
double dist(Pnt a, line u) { return a.x * u.a + a.y * u.b + u.c; }
int banbun(int st, int en, bool tag) {
  while (st < en) {
    int i = (st + en + tag) / 2;
    double kk = dist(p[(i) % n], now);
    if ((kk > 0 && tag) || (kk < 0 && !tag))
      st = i + 1 - tag;
    else
      en = i - tag;
  }
  return st;
}
void prep() {
  area[0] = 0;
  for (int i = 1; i <= 4 * n; i++) {
    area[i] = area[i - 1] + 1.0 * (p[(i - 1) % n].x - p[(i) % n].x) *
                                (p[(i - 1) % n].y + p[(i) % n].y);
  }
  Area = area[n];
  for (int i = 0; i < n * 2; i++)
    seg[i] = get_equation(p[(i) % n], p[(i + 1) % n]);
}
int main() {
  scanf("%d %d", &n, &Q);
  for (int i = 1; i <= n; i++) p[n - i].input();
  prep();
  int x, y;
  double st, en, mid, ans;
  while (Q--) {
    q.input();
    st = 0, en = pi;
    ans = -1;
    double zero = -1;
    bool tag = 0;
    for (int rmh = 0; rmh < 60; rmh++) {
      if (rmh)
        mid = (st + en) / 2;
      else
        mid = 0;
      if (en - st < ep * ep * ep) break;
      now = line(sin(mid), -cos(mid),
                 cos(mid) * 1.0 * q.y - sin(mid) * 1.0 * q.x);
      double u0 = dist(p[0], now), u1 = dist(p[1], now);
      bool flag = 0;
      if (u0 > u1) {
        flag = 1;
        u0 = -u0;
        u1 = -u1;
        now.rev();
      }
      int le = 0, ri = n - 1, pp, qq;
      double ui, uj;
      while (le < ri) {
        pp = (le + ri + 1) / 2;
        qq = (pp + 1) % n;
        ui = dist(p[pp], now), uj = dist(p[qq], now);
        if (ui <= uj && ui >= 0.5 * (u0 + u1))
          le = pp;
        else
          ri = pp - 1;
      }
      int far1 = (le + 1) % n;
      le = far1 + 1, ri = far1 + n - 1;
      while (le < ri) {
        pp = (le + ri) / 2;
        qq = pp + 1;
        ui = dist(p[(pp) % n], now), uj = dist(p[(qq) % n], now);
        if (ui > uj)
          le = pp + 1;
        else
          ri = pp;
      }
      int far2 = le;
      int last = banbun(far1, far2, 1) + n, first = banbun(far2, far1 + n, 0);
      Pnt fir = intersect(now, seg[(first + n - 1) % n]),
          las = intersect(now, seg[(last) % n]);
      double rlt = 0;
      rlt += (fir.x - p[(first) % n].x) * (fir.y + p[(first) % n].y);
      rlt += area[last] - area[first];
      rlt += (p[(last) % n].x - las.x) * (p[(last) % n].y + las.y);
      rlt += (las.x - fir.x) * (las.y + fir.y);
      if (flag) rlt = Area - rlt;
      if (!rmh) {
        zero = rlt;
        continue;
      }
      double diff = fabs(2 * rlt - Area);
      if (diff / Area < ep) {
        tag = 1;
        ans = mid;
        break;
      }
      if ((rlt > 0.5 * Area) == (zero > 0.5 * Area))
        st = mid;
      else
        en = mid;
    }
    if (tag)
      printf("%.10lf\n", ans);
    else
      printf("%.10lf\n", (st + en) / 2);
  }
  return 0;
}
