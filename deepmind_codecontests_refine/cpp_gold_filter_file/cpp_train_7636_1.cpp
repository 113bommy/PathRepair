#include <bits/stdc++.h>
using namespace std;
struct point {
  double x, y, z;
  point() {}
  point(double x, double y, double z = 1) : x(x), y(y), z(z) {}
  point operator*(const point &rhs) {
    return point(y * rhs.z - z * rhs.y, z * rhs.x - x * rhs.z,
                 x * rhs.y - y * rhs.x);
  }
  point projection() { return point(x / z, y / z); }
  double norm() { return sqrt(x * x + y * y); }
  void print() { printf("%2.9f %0.9f ", x, y); }
};
point perpen(point &r) { return point(-r.y, r.x); }
point line(point l, point t) {
  double c = l.y * t.x - l.x * t.y;
  return point(-l.y, l.x, c);
}
point normal(point a) { return point(a.x / a.norm(), a.y / a.norm()); }
double product(point &a, point &b) { return a.x * b.x + a.y * b.y; }
struct comp {
  point m;
  comp(point _m) { m = _m; }
  bool operator()(const point &a, const point &b) const {
    return atan2(a.y - m.y, a.x - m.x) > atan2(b.y - m.y, b.x - m.x);
  }
};
double ccw(point a, point b) { return a.x * b.y - a.y * b.x; }
double ccw(point &a, point &b, point &c) {
  return ccw(point(b.x - a.x, b.y - a.y), point(c.x - a.x, c.y - a.y));
}
point p[3];
void solve() {
  point m, l, newbie, k;
  point A[4];
  for (int i = 0; i < 3; ++i) {
    m = p[i];
    l = p[(i + 1) % 3];
    k = p[(i + 2) % 3];
    newbie = point(m.x * 2 - l.x, m.y * 2 - l.y);
    point l1 = point(newbie.x - m.x, newbie.y - m.y),
          l2 = point(k.x - m.x, k.y - m.y);
    l1 = perpen(l1), l2 = perpen(l2);
    l1 = line(l1, point((newbie.x + m.x) / 2, (newbie.y + m.y) / 2));
    l2 = line(l2, point((k.x + m.x) / 2, (k.y + m.y) / 2));
    A[0] = l1 * l2;
    if (A[0].z == 0) break;
    A[0] = A[0].projection();
    A[1] = point(2 * m.x - A[0].x, 2 * m.y - A[0].y);
    A[3] = point(2 * k.x - A[0].x, 2 * k.y - A[0].y),
    A[2] = point(2 * l.x - A[1].x, 2 * l.y - A[1].y);
    bool istrue = true;
    double first = ccw(A[0], A[1], A[2]);
    for (int j = 1; j < 4; ++j) {
      if (ccw(A[j], A[(j + 1) % 4], A[(j + 2) % 4]) * first <= 0) {
        istrue = false;
        break;
      }
    }
    if (!istrue) continue;
    printf("YES\n");
    for (int j = 0; j < 4; ++j) A[j].print();
    putchar('\n');
    return;
  }
  printf("NO\n\n");
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    for (int i = 0; i < 3; ++i) scanf("%lf %lf", &p[i].x, &p[i].y);
    solve();
  }
}
