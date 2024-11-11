#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3F3F3F3F;
const double EPS = 1e-10;
inline int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}
struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  point operator+(point q) { return point(x + q.x, y + q.y); }
  point operator-(point q) { return point(x - q.x, y - q.y); }
  point operator*(double t) { return point(x * t, y * t); }
  point operator/(double t) { return point(x / t, y / t); }
  double operator*(point q) { return x * q.x + y * q.y; }
  double operator%(point q) { return x * q.y - y * q.x; }
  int cmp(point q) const {
    if (int t = ::cmp(x, q.x)) return t;
    return ::cmp(y, q.y);
  }
  bool operator==(point q) const { return cmp(q) == 0; }
  bool operator!=(point q) const { return cmp(q) != 0; }
  bool operator<(point q) const { return cmp(q) < 0; }
  friend ostream& operator<<(ostream& o, point p) {
    return o << "(" << p.x << ", " << p.y << ")";
  }
  static point pivot;
};
point point::pivot;
double abs(point p) { return hypot(p.x, p.y); }
double arg(point p) { return atan2(p.y, p.x); }
inline int ccw(point p, point q, point r) { return cmp((p - r) % (q - r)); }
bool between(point p, point q, point r) {
  return ccw(p, q, r) == 0 && cmp((p - q) * (r - q)) <= 0;
}
inline double angle(point p, point q, point r) {
  point u = p - q, v = r - q;
  return atan2(u % v, u * v);
}
bool radial_lt(point p, point q) {
  point P = p - point::pivot, Q = q - point::pivot;
  double R = P % Q;
  if (cmp(R)) return R > 0;
  return cmp(P * P, Q * Q) < 0;
}
int in_poly(point p, vector<point>& T) {
  double a = 0;
  int N = T.size();
  for (int i = 0; i < N; i++) {
    if (between(T[i], p, T[(i + 1) % N])) return -1;
    a += angle(T[i], p, T[(i + 1) % N]);
  }
  return cmp(a) != 0;
}
vector<point> convex_hull(vector<point>& T) {
  int j = 0, k, n = T.size();
  vector<point> U(n);
  point::pivot = *min_element((T).begin(), (T).end());
  sort((T).begin(), (T).end(), radial_lt);
  for (int i = 0; i < n; i++) {
    while (j > 1 && ccw(U[j - 1], U[j - 2], T[i]) >= 0) j--;
    U[j++] = T[i];
  }
  U.erase(j + (U).begin(), (U).end());
  return U;
}
point line_intersect(point p, point q, point r, point s) {
  point a = q - p, b = s - r, c = point(p % q, r % s);
  return point(point(a.x, b.x) % c, point(a.y, b.y) % c) / (a % b);
}
double ans = 2000000;
vector<point> P;
int n, p, q;
void check(point kk) { ans = min(ans, max(p / kk.x, q / kk.y)); }
int main() {
  scanf("%d %d %d", &n, &p, &q);
  for (int i = 0; i < n; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    P.emplace_back(u, v);
  }
  P = convex_hull(P);
  for (int i = 0; i < P.size(); i++) {
    check(P[i]);
  }
  if (P.size() > 1) {
    for (int i = 0; i < P.size(); i++) {
      point in =
          line_intersect(P[i], P[(i + 1) % P.size()], point(0, 0), point(p, q));
      if (between(P[i], in, P[(i + 1) % P.size()])) check(in);
    }
  }
  printf("%.15f\n", ans);
}
