#include <bits/stdc++.h>
using namespace std;
struct Point {
  double x, y;
  Point(double a = 0, double b = 0) : x(a), y(b) {}
  inline void read() { scanf("%lf%lf", &x, &y); }
  inline Point operator+(const Point &b) { return Point(x + b.x, y + b.y); }
  inline Point operator-(const Point &b) { return Point(x - b.x, y - b.y); }
  inline Point operator*(const double p) { return Point(x * p, y * p); }
  inline Point operator/(const double p) { return Point(x / p, y / p); }
} A[1050];
inline double Dot(Point A, Point B) { return A.x * B.x + A.y * B.y; }
inline double Cross(Point A, Point B) { return A.x * B.y - A.y * B.x; }
inline double Lenth(Point A) { return sqrt(Dot(A, A)); }
inline double dis(Point A, Point B, Point C) {
  return fabs(Cross(B - A, C - A)) / Lenth(B - C);
}
int main() {
  int n;
  scanf("%d", &n);
  double ans = 1e9;
  for (int i = 1; i <= n; ++i) A[i].read();
  A[++n] = A[1];
  A[++n] = A[2];
  for (int i = 2; i < n; ++i) {
    ans = min(ans, dis(A[i + 1], A[i], A[i - 1]));
    ans = min(ans, dis(A[i], A[i + 1], A[i - 1]));
    ans = min(ans, dis(A[i - 1], A[i], A[i + 1]));
  }
  printf("%.10lf\n", ans / 2);
  return 0;
}
