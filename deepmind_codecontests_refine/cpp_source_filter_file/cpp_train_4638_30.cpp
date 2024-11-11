#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x, y, z;
};
double vp, vs;
int n;
Point p[10100];
Point s;
inline double sqr(double x) { return x * x; }
double Dist(Point a, Point b) {
  return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y) + sqr(a.z - b.z));
}
double Len(Point a) { return sqrt(sqr(a.x) + sqr(a.y) + sqr(a.z)); }
double eps = 1e-9;
void Solve(int a, int b, double ts) {
  int i;
  Point v;
  Point t;
  double l, r, h;
  double len;
  double tp;
  l = 0;
  r = Dist(p[a], p[b]);
  v.x = p[b].x - p[a].x;
  v.y = p[b].y - p[a].y;
  v.z = p[b].z - p[a].z;
  len = Len(v);
  v.x /= len;
  v.y /= len;
  v.z /= len;
  for (i = 1; i <= 1000; i++) {
    h = (l + r) / 2;
    t.x = p[a].x + v.x * h;
    t.y = p[a].y + v.y * h;
    t.z = p[a].z + v.z * h;
    tp = Dist(s, t) / vp;
    if (tp <= ts + Dist(p[a], t)) {
      r = h;
    } else {
      l = h;
    }
  }
  h = (l + r) / 2;
  t.x = p[a].x + v.x * h;
  t.y = p[a].y + v.y * h;
  t.z = p[a].z + v.z * h;
  tp = Dist(s, t) / vp;
  printf("%.9lf\n", tp);
  printf("%.9lf %.9lf %.9lf\n", t.x, t.y, t.z);
}
int main() {
  double tp, ts;
  int i;
  scanf("%d", &n);
  n++;
  for (i = 1; i <= n; i++) {
    scanf("%lf %lf %lf", &p[i].x, &p[i].y, &p[i].z);
  }
  scanf("%lf %lf", &vp, &vs);
  scanf("%lf %lf %lf", &s.x, &s.y, &s.z);
  ts = 0;
  for (i = 2; i <= n; i++) {
    ts += Dist(p[i - 1], p[i]) / vs;
    tp = Dist(s, p[i]) / vp;
    if (tp <= ts + eps) {
      printf("YES\n");
      Solve(i - 1, i, ts - Dist(p[i - 1], p[i]) / vs);
      return 0;
    }
  }
  printf("NO\n");
  return 0;
}
