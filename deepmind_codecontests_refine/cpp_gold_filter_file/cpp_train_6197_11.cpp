#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:16000000")
#pragma warning(disable : 4996)
const int inf = 1 << 25;
const double eps = 1e-5;
int signum(double x) {
  if (fabs(x) < eps) return 0;
  return x < 0 ? -1 : 1;
}
struct Point {
  double x, y;
  Point() {}
  Point(double x, double y) : x(x), y(y) {}
  bool isInside(const vector<Point>& tr) {
    vector<int> x;
    for (int i = (0); i < (3); ++i) {
      x.push_back(signum(((*this) - tr[i]) % (tr[(i + 1) % 3] - tr[i])));
      if (!x.back()) x.pop_back();
      if (!x.empty() && x.back() != x[0]) return false;
    }
    return true;
  }
  double operator~() const { return sqrt(x * x + y * y); }
  double operator%(const Point& A) const { return x * A.y - y * A.x; }
  Point operator-(const Point& A) const { return Point(x - A.x, y - A.y); }
  Point operator+(const Point& A) const { return Point(x + A.x, y + A.y); }
  Point operator*(const double a) const { return Point(a * x, a * y); }
  bool operator<(const Point& A) const {
    return x < A.x || x == A.x && y < A.y;
  }
};
bool isInside(Point& A, Point& B, const vector<Point>& tr) {
  return A.isInside(tr) && B.isInside(tr);
}
bool intersects(Point& A, Point& B, Point& C, Point& D, Point& X) {
  Point AB = B - A, CD = D - C, AC = C - A;
  if (fabs(~AB) < eps || fabs(~CD) < eps) return false;
  double d = -(AB % CD);
  if (fabs(d) < eps) return false;
  double t1 = -(AC % CD) / d;
  double t2 = (AB % AC) / d;
  if (t2 < -eps || t2 > 1 + eps || t1 < -eps || t1 > 1 + eps) return false;
  X = C + CD * t2;
  return true;
}
int main() {
  double ans = 0;
  int n;
  cin >> n;
  vector<vector<Point> > tr(n, vector<Point>(3));
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (3); ++j) cin >> tr[i][j].x >> tr[i][j].y;
  for (int i = (0); i < (n); ++i)
    for (int j = (0); j < (3); ++j) {
      vector<Point> crossPts;
      crossPts.push_back(tr[i][j]);
      crossPts.push_back(tr[i][(j + 1) % 3]);
      ans += ~(crossPts[0] - crossPts[1]);
      for (int i1 = (0); i1 < (n); ++i1)
        if (i1 != i)
          for (int j1 = (0); j1 < (3); ++j1) {
            Point X;
            if (intersects(crossPts[0], crossPts[1], tr[i1][j1],
                           tr[i1][(j1 + 1) % 3], X))
              crossPts.push_back(X);
          }
      sort(crossPts.begin(), crossPts.end());
      for (int i2 = (1); i2 < ((int)crossPts.size()); ++i2) {
        for (int i1 = (0); i1 < (n); ++i1)
          if (i1 != i && isInside(crossPts[i2 - 1], crossPts[i2], tr[i1])) {
            ans -= ~(crossPts[i2 - 1] - crossPts[i2]);
            break;
          }
      }
    }
  printf("%.12lf\n", ans);
  return 0;
}
