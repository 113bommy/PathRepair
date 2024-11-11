#include <bits/stdc++.h>
template <typename T>
inline bool MIN(T &a, const T &b) {
  return a > b ? a = b, 1 : 0;
}
template <typename T>
inline bool MAX(T &a, const T &b) {
  return a < b ? a = b, 1 : 0;
}
using namespace std;
int n;
struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  bool operator<(const Point &ano) const {
    return x != ano.x ? x < ano.x : y < ano.y;
  }
};
Point operator+(Point a, Point b) { return Point(a.x + b.x, a.y + b.y); }
Point operator-(Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }
Point operator*(Point a, double b) { return Point(a.x * b, a.y * b); }
Point operator/(Point a, double b) { return Point(a.x / b, a.y / b); }
int dcmp(double a) {
  if (fabs(a) < 1e-10) return 0;
  return a > 0 ? 1 : -1;
}
double det(Point a, Point b) { return (a.x * b.y - b.x * a.y); }
double dot(Point a, Point b) { return (a.x * b.x + a.y * b.y); }
double dis(Point a, Point b) { return sqrt(dot(a - b, a - b)); }
double length(Point a) { return sqrt(dot(a, a)); }
int A[2010], B[2010], C[2010];
Point P[2010], V[2010];
Point inter(Point p1, Point v1, Point p2, Point v2) {
  double t = det(p1 - p2, v2) / det(v2, v1);
  return p1 + v1 * t;
}
struct node {
  int fg;
  double ang, x;
  bool operator<(const node &ano) const {
    return dcmp(ang - ano.ang) ? ang < ano.ang : x < ano.x;
  }
};
vector<node> q;
int run() {
  int res = 0;
  for (int i = 0, j = 0; i < q.size(); i = j) {
    for (; j < q.size() && dcmp(q[j].ang - q[i].ang) == 0; ++j)
      ;
    for (int k = i, t = 0; k < j; ++k) {
      if (q[k].fg == -1)
        res += t;
      else
        ++t;
    }
  }
  return res;
}
int main() {
  scanf("%d", &n);
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", &A[i], &B[i], &C[i]);
    double a = A[i], b = B[i], c = C[i];
    P[i] = b ? Point(0, c / b) : Point(c / a, 0);
    V[i] = Point(b, -a);
    if (!C[i]) ++cnt;
  }
  long long ans = 0;
  if (cnt == 2) ans = n - 2;
  for (int i = 1; i <= n; ++i)
    if (C[i]) {
      q.clear();
      if (det(V[i], Point(0, 0) - P[i]) > 0) V[i] = Point(0, 0) - V[i];
      for (int j = 1; j <= n; ++j)
        if (i != j && C[j]) {
          Point p = inter(P[i], V[i], P[j], V[j]);
          if (det(V[j], V[i]) * det(Point(0, 0) - P[i], V[i]) > 0)
            V[j] = Point(0, 0) - V[j];
          double ang = acos(dot(V[j], Point(0, 0) - p) / length(V[j]) /
                            length(Point(0, 0) - p));
          double x = dot(p - P[i], V[i]);
          if (det(V[j], Point(0, 0) - p) < 0) {
            q.push_back((node){1, ang, x});
          } else {
            q.push_back((node){-1, M_PI - ang, x});
          }
        }
      sort(q.begin(), q.end());
      ans += run();
    }
  printf("%I64d\n", ans);
  return 0;
}
