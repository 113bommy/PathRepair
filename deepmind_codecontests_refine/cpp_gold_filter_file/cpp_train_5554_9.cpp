#include <bits/stdc++.h>
using namespace std;
const int N = 105;
struct Point {
  double x, y;
  Point() {}
  Point(double a, double b) {
    x = a;
    y = b;
  }
  double mod2() { return x * x + y * y; }
  double mod() { return sqrt(x * x + y * y); }
  double arg() { return atan2(y, x); }
  Point ort() { return Point(-y, x); }
  Point unit() {
    double k = mod();
    return Point(x / k, y / k);
  }
};
Point operator+(const Point &a, const Point &b) {
  return Point(a.x + b.x, a.y + b.y);
}
Point operator-(const Point &a, const Point &b) {
  return Point(a.x - b.x, a.y - b.y);
}
Point operator/(const Point &a, double k) { return Point(a.x / k, a.y / k); }
Point operator*(const Point &a, double k) { return Point(a.x * k, a.y * k); }
double dist(const Point &A, const Point &B) {
  return hypot(A.x - B.x, A.y - B.y);
}
double cross(const Point &A, const Point &B) { return A.x * B.y - A.y * B.x; }
double dot(const Point &A, const Point &B) { return A.x * B.x + A.y * B.y; }
double area(const Point &A, const Point &B, const Point &C) {
  return cross(B - A, C - A);
}
double dist2(Point p, Point q) { return dot(p - q, p - q); }
Point RotateCCW(Point p, double t) {
  return Point(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}
Point ProjectPointLine(Point a, Point b, Point c) {
  return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}
int main() {
  Point p1;
  double v1;
  cin >> p1.x >> p1.y >> v1;
  double r1 = p1.mod();
  Point p2;
  double v2, r2;
  cin >> p2.x >> p2.y >> v2 >> r2;
  double le = 0, ri = 1e9;
  for (int rep = 0; rep < 70; rep++) {
    double mid = (le + ri) / 2;
    double teta = v1 * mid / r1;
    Point current = RotateCCW(p1, teta);
    double altura =
        cross(Point(0, 0) - p2, current - p2) / (current - p2).mod();
    if (altura < 0) altura = -altura;
    bool inside = 1;
    double aux = dot(current - p2, Point(0, 0) - p2);
    if (aux < 0) inside = 0;
    aux = dot(p2 - current, Point(0, 0) - current);
    if (aux < 0) inside = 0;
    if (altura >= r2) inside = 0;
    bool ok = 1;
    if (!inside) {
      if (dist(p2, current) / v2 > mid) ok = 0;
    } else {
      double d2 = p2.mod();
      double d1 = current.mod();
      double d = sqrt(d1 * d1 - r2 * r2) + sqrt(d2 * d2 - r2 * r2);
      teta = dot(p2, current) / p2.mod() / current.mod();
      teta = acos(teta);
      teta -= acos(r2 / d1) + acos(r2 / d2);
      d += teta * r2;
      if (d / v2 > mid) ok = 0;
    }
    if (ok)
      ri = mid;
    else
      le = mid;
  }
  printf("%.10f\n", ri);
  return 0;
}
