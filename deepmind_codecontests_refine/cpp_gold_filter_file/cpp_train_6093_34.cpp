#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int inf = 1 << 30;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int nCase = 0;
int dcmp(double x) {
  if (fabs(x) < eps) return 0;
  return x < 0 ? -1 : 1;
}
inline int read() {
  char c = getchar();
  while (!isdigit(c)) c = getchar();
  int x = 0;
  while (isdigit(c)) {
    x = x * 10 + c - '0';
    c = getchar();
  }
  return x;
}
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) {
    this->x = x;
    this->y = y;
  }
  void read() { scanf("%lf%lf", &x, &y); }
};
Point operator+(Point A, Point B) { return Point(A.x + B.x, A.y + B.y); }
Point operator-(Point A, Point B) { return Point(A.x - B.x, A.y - B.y); }
Point operator*(Point A, double p) { return Point(A.x * p, A.y * p); }
Point operator/(Point A, double p) { return Point(A.x / p, A.y / p); }
bool operator<(const Point& a, const Point& b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool operator==(const Point& a, const Point& b) {
  return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
double Dot(Point A, Point B) { return A.x * B.x + A.y * B.y; }
double Length(Point A) { return sqrt(Dot(A, A)); }
double Angle(Point A, Point B) {
  return acos(Dot(A, B) / Length(A) / Length(B));
}
double Cross(Point A, Point B) { return A.x * B.y - A.y * B.x; }
double Area2(Point A, Point B, Point C) { return Cross(B - A, C - A); }
Point Rotate(Point A, double rad) {
  return Point(A.x * cos(rad) - A.y * sin(rad),
               A.x * sin(rad) + A.y * cos(rad));
}
bool LineCoincide(Point p1, Point p2, Point p3) {
  return dcmp(Cross(p2 - p1, p3 - p1)) == 0;
}
bool LineParallel(Point v, Point w) { return Cross(v, w) == 0; }
bool LineVertical(Point v, Point w) { return Dot(v, w) == 0; }
Point GetLineIntersection(Point P, Point v, Point Q, Point w) {
  Point u = P - Q;
  double t = Cross(w, u) / Cross(v, w);
  return P + v * t;
}
double DistanceToLine(Point P, Point A, Point B) {
  Point v1 = B - A, v2 = P - A;
  return fabs(Cross(v1, v2)) / Length(v1);
}
double DistanceToSegment(Point P, Point A, Point B) {
  if (A == B) return Length(P - A);
  Point v1 = B - A, v2 = P - A, v3 = P - B;
  if (dcmp(Dot(v1, v2)) < 0)
    return Length(v2);
  else if (dcmp(Dot(v1, v3)) > 0)
    return Length(v3);
  else
    return fabs(Cross(v1, v2)) / Length(v1);
}
Point GetLineProjection(Point P, Point A, Point B) {
  Point v = B - A;
  return A + v * (Dot(v, P - A) / Dot(v, v));
}
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2) {
  double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
         c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
  return dcmp(c1) * dcmp(c2) <= 0;
}
bool OnSegment(Point p, Point a1, Point a2) {
  return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}
double PolygonArea(Point* p, int n) {
  double area = 0;
  for (int i = 1; i < n - 1; i++) area += Cross(p[i] - p[0], p[i + 1] - p[0]);
  return area / 2;
}
struct Line {
  Point a, b;
  void read() {
    a.read();
    b.read();
  }
};
const int maxn = 200010;
int n, k;
int a[maxn], b[maxn];
int main(int argc, const char* argv[]) {
  cin >> n >> k;
  int limit = inf;
  for (int i = 0; i <= n; ++i) {
    scanf("%d", &a[i]);
    b[i] += a[i];
    b[i + 1] = b[i] / 2;
    b[i] %= 2;
    if (b[i] && limit == inf) {
      limit = i;
    }
  }
  long long value = 0;
  value = b[n + 1];
  int ans = 0;
  for (int i = n; i >= 0; --i) {
    value = value * 2 + b[i];
    if (abs(value) > 2 * k) break;
    if (i <= limit && abs(value - a[i]) <= k && (i != n || value != a[i]))
      ans++;
  }
  printf("%d\n", ans);
  return 0;
}
