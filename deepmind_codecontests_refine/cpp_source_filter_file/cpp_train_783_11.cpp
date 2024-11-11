#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 50;
const int maxm = 1e6 + 50;
const long double eps = 1e-19;
const int max_index = 62;
const int inf = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
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
  long double x, y;
  Point(long double x = 0, long double y = 0) : x(x), y(y) {}
};
Point operator+(const Point& A, const Point& B) {
  return Point(A.x + B.x, A.y + B.y);
}
Point operator-(const Point& A, const Point& B) {
  return Point(A.x - B.x, A.y - B.y);
}
Point operator*(const Point& A, long double p) {
  return Point(A.x * p, A.y * p);
}
Point operator/(const Point& A, long double p) {
  return Point(A.x / p, A.y / p);
}
long double operator^(const Point& A, const Point& B) {
  return A.x * B.y - A.y * B.x;
}
bool operator<(const Point& a, const Point& b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}
int dcmp(long double x) {
  if (abs(x) < eps) return 0;
  return x < 0 ? -1 : 1;
}
bool operator==(const Point& a, const Point& b) {
  return !dcmp(a.x - b.x) && !dcmp(a.y - b.y);
}
long double Dot(const Point& A, const Point& B) {
  return A.x * B.x + A.y * B.y;
}
long double Cross(const Point& A, const Point& B) {
  return A.x * B.y - A.y * B.x;
}
long double Length(const Point& A) { return sqrt(Dot(A, A)); }
long double Angle(const Point& A, const Point& B) {
  return acos(Dot(A, B) / Length(A) / Length(B));
}
long double Area2(const Point& A, const Point& B, const Point& C) {
  return Cross(B - A, C - A);
}
Point Rotate(const Point& A, long double rad) {
  return Point(A.x + cos(rad) - A.y * sin(rad),
               A.x * sin(rad) + A.y * cos(rad));
}
Point Normal(const Point& A) {
  long double L = Length(A);
  return Point(-A.y / L, A.x / L);
}
Point GetLineIntersection(const Point& P, const Point& v, const Point& Q,
                          const Point& w) {
  Point u = P - Q;
  long double t = Cross(w, u) / Cross(v, w);
  return P + v * t;
}
long double DistanceToLine(const Point& P, const Point& A, const Point& B) {
  Point v1 = B - A, v2 = P - A;
  return fabs(Cross(v1, v2) / Length(v1));
}
long double DistanceToSegment(const Point& P, const Point& A, const Point& B) {
  if (A == B) return Length(P - A);
  Point v1 = B - A, v2 = P - A, v3 = P - B;
  if (dcmp(Dot(v1, v2)) < 0) return Length(v2);
  if (dcmp(Dot(v1, v3)) > 0) return Length(v3);
  return fabs(Cross(v1, v2) / Length(v1));
}
Point GetLineProjection(const Point& P, const Point& A, const Point& B) {
  Point v = B - A;
  return A + v * (Dot(v, P - A) / Dot(v, v));
}
bool SegmentProperIntersection(const Point& a1, const Point& a2,
                               const Point& b1, const Point& b2) {
  long double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
              c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
  return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
int OnSegment(const Point& p, const Point& a1, const Point& a2) {
  return dcmp(Dot(a1 - p, a2 - p));
}
long double PolygonArea(Point* p, int n) {
  long double area = 0;
  for (int i = 1; i < n - 1; i++) area += Cross(p[i] - p[0], p[i + 1] - p[0]);
  return area / 2;
}
Point ReadPoint() {
  Point res;
  cin >> res.x >> res.y;
  return res;
}
Point bus[maxn];
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  long double w, u, v;
  cin >> n >> w >> v >> u;
  for (int i = 1; i <= n; i++) bus[i] = bus[i + n] = ReadPoint();
  bus[0] = bus[n];
  Point dir = Point(v * 1.0, u * 1.0);
  int flag = 1;
  int cnt = 1;
  for (int i = 1; i <= n; i++) {
    Point seg = bus[i + 1] - bus[i];
    if (dcmp(seg ^ dir) == 0) continue;
    Point inter = GetLineIntersection(Point(0, 0), dir, bus[i], seg);
    int tmp = OnSegment(inter, bus[i], bus[i + 1]);
    if (tmp == -1)
      flag = 0;
    else if (tmp == 0)
      cnt++;
  }
  if (flag || cnt > 2) {
    cout << fixed << setprecision(18) << w * 1.0 / u << endl;
    exit(0);
  }
  int cur = 1;
  while (bus[cur - 1].y < bus[cur].y || bus[cur + 1].y < bus[cur].y) cur++;
  for (int i = 1; i <= n; i++) {
    int id = cur + i - 1;
    Point seg = bus[id + 1] - bus[id];
    if (dcmp(dir ^ seg) * dcmp(dir ^ Point(0, 1)) < 0) continue;
    cout << fixed << setprecision(18) << bus[id].x / v + (w - bus[id].y) / u
         << endl;
    exit(0);
  }
  return 0;
}
