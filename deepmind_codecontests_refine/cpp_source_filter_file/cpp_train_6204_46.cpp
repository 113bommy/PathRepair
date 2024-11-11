#include <bits/stdc++.h>
using namespace std;
int n;
double t1 = 0.0, t2 = 1e18;
void no() { printf("-1\n"), exit(0); }
struct V {
  int x, y;
  V(int a = 0, int b = 0) : x(a), y(b) {}
} v1, v2;
struct M {
  V p, v;
  M(V a = V(), V b = V()) : p(a), v(b) {}
};
double intx(M m, int x) {
  int d = x - m.p.x;
  double t;
  if (m.v.x)
    t = (double)d / m.v.x;
  else {
    if (d == 0) no();
    return -1.0;
  }
  if (t < -1e-7) return -1.0;
  double y = m.p.y + m.v.y * t;
  if (y < v1.y - 1e-7 || y > v2.y + 1e-7) return -1.0;
  return t;
}
double inty(M m, int y) {
  int d = y - m.p.y;
  double t;
  if (m.v.y)
    t = (double)d / m.v.y;
  else {
    if (d == 0) no();
    return -1.0;
  }
  if (t < -1e-7) return -1.0;
  double x = m.p.x + m.v.x * t;
  if (x < v1.x - 1e-7 || x > v2.x + 1e-7) return -1.0;
  return t;
}
vector<double> shot(M m) {
  vector<double> ts;
  double t = intx(m, v1.x);
  if (t > -0.5) ts.push_back(t);
  t = intx(m, v2.x);
  if (t > -0.5) ts.push_back(t);
  t = inty(m, v1.y);
  if (t > -0.5) ts.push_back(t);
  t = inty(m, v2.y);
  if (t > -0.5) ts.push_back(t);
  sort(ts.begin(), ts.end());
  return ts;
}
int main() {
  scanf("%d", &n);
  int a, b, c, d;
  scanf("%d%d%d%d", &a, &b, &c, &d);
  v1 = V(a, b), v2 = V(c, d);
  for (int i = 0; i < (int)(n); ++i) {
    scanf("%d%d%d%d", &a, &b, &c, &d);
    M m = M(V(a, b), V(c, d));
    vector<double> ts = shot(m);
    if (m.p.x > v1.x && m.p.x < v2.x && m.p.y > v1.y && m.p.y < v2.y) {
      if (ts.empty()) continue;
      t2 = min(t2, ts[0]);
    } else {
      if (ts.empty()) no();
      t1 = max(t1, ts[0]);
      t2 = min(t2, ts.back());
    }
  }
  if (t1 + 1e-7 > t2) no();
  printf("%.7lf\n", t1);
}
