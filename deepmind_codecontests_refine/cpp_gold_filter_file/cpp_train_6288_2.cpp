#include <bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
const double eps = 1e-12;
const int maxn = 310;
int sgn(const double& x) { return (x > eps) - (x < -eps); }
struct Point {
  int x, y;
  Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
} p[maxn];
bool cmp(Point p1, Point p2) {
  if (p1.x != p2.x)
    return p1.x < p2.x;
  else
    return p1.y < p2.y;
}
const double PI = acos(-1.0);
double torad(double deg) { return deg / 180 * PI; }
Point operator+(Point A, Point B) { return Point(A.x + B.x, A.y + B.y); }
Point operator-(Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }
Point operator*(Point a, double b) { return Point(a.x * b, a.y * b); }
Point operator/(Point a, double b) { return Point(a.x / b, a.y / b); }
bool operator<(const Point& a, const Point& b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}
int dcmp(double x) {
  if (fabs(x) < eps) {
    return 0;
  } else {
    return x < 0 ? -1 : 1;
  }
}
bool operator==(const Point& a, const Point& b) {
  return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
double Dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double Length(Point a) { return sqrt(Dot(a, a)); }
double Angle(Point a, Point b) {
  return acos(Dot(a, b) / Length(a) / Length(b));
}
int Cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
double Area2(Point a, Point b, Point c) { return Cross(b - a, c - a) / 2.0; }
int main() {
  int n;
  scanf("%d", &n);
  for (int i = (0); i < (n); ++i) scanf("%d%d", &p[i].x, &p[i].y);
  double maxs = 0;
  for (int i = (0); i < (n); ++i)
    for (int j = (i + 1); j < (n); ++j) {
      double positive_area = 0;
      double negative_area = 0;
      for (int k = (0); k < (n); ++k) {
        if (Area2(p[k], p[i], p[j]) < 0) {
          negative_area = max(negative_area, -Area2(p[k], p[i], p[j]));
        } else {
          positive_area = max(positive_area, Area2(p[k], p[i], p[j]));
        }
      }
      if (positive_area != 0 && negative_area != 0)
        maxs = max(maxs, positive_area + negative_area);
    }
  printf("%.11lf\n", maxs);
  return 0;
}
