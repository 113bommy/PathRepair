#include <bits/stdc++.h>
using namespace std;
void io() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
}
int t, n, m, num = 0;
double mind = 1e9, d1, d2;
bool flag = true;
struct Point {
  double x, y;
  Point() {}
  Point(double xx, double yy) : x(xx), y(yy) {}
} p1[100010], p2[100010], pa, pb;
double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
Point operator*(Point a, double t) { return Point(a.x * t, a.y * t); }
Point operator+(Point a, Point b) { return Point(a.x + b.x, a.y + b.y); }
Point operator-(Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }
Point operator/(Point a, double p) { return Point(a.x / p, a.y / p); }
double len(Point a) { return sqrt(dot(a, a)); }
int dcmp(double x) {
  if (fabs(x) < 1e-10) return 0;
  if (x < 0) return -1;
  return 1;
}
bool operator==(const Point& a, const Point& b) {
  return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
double DistanceToSegment(Point P, Point A, Point B) {
  if (A == B) return len(P - A);
  Point v1 = B - A, v2 = P - A, v3 = P - B;
  if (dcmp(dot(v1, v2)) < 0)
    return len(v2);
  else if (dcmp(dot(v1, v3)) > 0)
    return len(v3);
  else
    return fabs(cross(v1, v2)) / len(v1);
}
void upd(Point P, Point A, Point B) {
  mind = min(mind, DistanceToSegment(P, A, B));
}
void in() {
  cin >> n;
  for (long long i = 1; i <= n; ++i) cin >> p1[i].x >> p1[i].y;
  cin >> m;
  for (long long i = 1; i <= m; ++i) cin >> p2[i].x >> p2[i].y;
}
int main() {
  io();
  cin >> t >> d1 >> d2;
  for (long long i = 1; i <= t; ++i) {
    cin >> p1[i].x >> p1[i].y >> p2[i].x >> p2[i].y;
    if (i == 1) {
      if (len(p1[i] - p2[i]) < d1) {
        num++;
        flag = false;
      }
      pa = p1[i], pb = p2[i];
      continue;
    }
    Point va = (p1[i] - pa);
    Point vb = (p2[i] - pb);
    double tpd = DistanceToSegment(pa, pb, pb + vb - va);
    pa = pa + va;
    pb = pb + vb;
    if (flag) {
      if (tpd < d1) {
        num++;
        flag = false;
        if (!flag)
          if (len(pa - pb) > d2) flag = true;
      }
    } else if (tpd > d2 || len(pa - pb) > d2)
      flag = true;
  }
  cout << num;
}
