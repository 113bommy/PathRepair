#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9;
int dcmp(const double &x) {
  if (x < -eps) return -1;
  if (x > eps) return 1;
  return 0;
}
struct Point {
  double x, y;
  Point(double x = 0.0, double y = 0.0) : x(x), y(y) {}
};
Point operator-(Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }
Point operator+(Point a, Point b) { return Point(a.x + b.x, a.y + b.y); }
Point operator*(Point a, double b) { return Point(a.x * b, a.y * b); }
bool operator<(Point a, Point b) {
  return dcmp(a.x - b.x) < 0 || (dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) < 0);
}
double norm(Point a) { return hypot(a.x, a.y); }
double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
int ConvexHull(vector<Point> &p, Point ch[]) {
  int n = p.size();
  sort(p.begin(), p.end());
  int m = 0;
  for (int i = 0; i < n; ++i) {
    while (m > 1 && cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
    ch[m++] = p[i];
  }
  int k = m;
  for (int i = n - 2; i >= 0; --i) {
    while (m > k && cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
    ch[m++] = p[i];
  }
  return m > 1 ? m - 1 : m;
}
struct Seg {
  Point o, e, v;
  Seg(Point o = Point(), Point e = Point()) : o(o), e(e) { v = e - o; }
};
bool intersect(Seg s1, Seg s2) {
  return cross(s2.o - s1.o, s1.v) * cross(s2.e - s1.o, s1.v) <= 0;
}
Point intersection(Seg s1, Seg s2) {
  double t = cross(s2.v, s1.o - s2.o) / cross(s1.v, s2.v);
  return s1.o + s1.v * t;
}
double a[100050], b[100050];
Point ch[100050];
int main(void) {
  int n;
  double p, q;
  cin >> n >> p >> q;
  for (int i = 0; i < n; ++i) cin >> a[i] >> b[i];
  vector<Point> vec;
  for (int i = 0; i < n; ++i) vec.push_back(Point(a[i], b[i]));
  vec.push_back(Point(*max_element(a, a + n), 0));
  vec.push_back(Point(0, *max_element(b, b + n)));
  vec.push_back(Point());
  int m = ConvexHull(vec, ch);
  Point goal = Point(p, q);
  Seg ss = Seg(Point(), goal);
  Point inter;
  for (int i = 1; i < m - 1; ++i)
    if (intersect(ss, Seg(ch[i], ch[i + 1]))) {
      inter = intersection(ss, Seg(ch[i], ch[i + 1]));
      break;
    }
  double ans = norm(goal) / norm(inter);
  printf("%.9f\n", ans);
  return 0;
}
