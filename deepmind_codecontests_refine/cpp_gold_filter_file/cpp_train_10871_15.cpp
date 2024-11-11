#include <bits/stdc++.h>
using namespace std;
struct Point {
  int x, y;
  bool operator<(const Point &T) const {
    if (x == T.x) return (y < T.y);
    return (x < T.x);
  }
};
struct Matrix {
  long long d[4][4];
  int mod;
  Matrix operator*(const Matrix &A) const {
    Matrix ans;
    ans.mod = mod;
    for (int i = 0; i <= 3; i++)
      for (int j = 0; j <= 3; j++) ans.d[i][j] = 0;
    for (int i = 0; i <= 3; i++) {
      for (int j = 0; j <= 3; j++) {
        for (int k = 0; k <= 3; k++) {
          ans.d[i][j] += (A.d[i][k] * d[k][j]);
          ans.d[i][j] %= mod;
        }
      }
    }
    return ans;
  }
  Matrix operator^(const int n) const {
    Matrix ans;
    ans.mod = mod;
    for (int i = 0; i <= 3; i++)
      for (int j = 0; j <= 3; j++) ans.d[i][j] = d[i][j];
    if (n == 1) return ans;
    Matrix t = ans ^ (n / 2);
    if (n % 2 == 0) return (t * t);
    return (t * t * ans);
  }
};
double INF = 1e100;
double EPS = 1e-7;
struct PT {
  double x, y;
  PT() {}
  PT(double x, double y) : x(x), y(y) {}
  PT(const PT &p) : x(p.x), y(p.y) {}
  PT operator-(const PT &p) { return PT(x - p.x, y - p.y); }
  PT operator+(const PT &p) { return PT(x + p.x, y + p.y); }
  PT operator*(double c) { return PT(x * c, y * c); }
  PT operator/(double c) { return PT(x / c, y / c); }
  bool operator==(const PT &p) { return x == p.x && y == p.y; }
  bool operator!=(const PT &p) { return x != p.x || y != p.y; }
};
double dot(PT p, PT q) { return p.x * q.x + p.y * q.y; }
double dist2(PT p, PT q) { return dot(p - q, p - q); }
double cross(PT p, PT q) { return p.x * q.y - p.y * q.x; }
ostream &operator<<(ostream &os, const PT &p) {
  os << "(" << p.x << "," << p.y << ")";
}
PT RotateCCW90(PT p) { return PT(-p.y, p.x); }
PT RotateCW90(PT p) { return PT(p.y, -p.x); }
PT RotateCCW(PT p, double t) {
  return PT(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));
}
PT RotateCCW90(PT origin, PT pt) {
  pt = pt - origin;
  pt = RotateCCW90(pt);
  pt = pt + origin;
  return pt;
}
bool isSquare(PT pt1, PT pt2, PT pt3, PT pt4) {
  PT center = pt1 + pt2 + pt3 + pt4;
  center = center * 0.25;
  if (center == pt1) return false;
  PT pt = RotateCCW90(center, pt1);
  if (pt != pt2 && pt != pt3 && pt != pt4) return false;
  pt = RotateCCW90(center, pt);
  if (pt != pt2 && pt != pt3 && pt != pt4) return false;
  pt = RotateCCW90(center, pt);
  if (pt != pt2 && pt != pt3 && pt != pt4) return false;
  return true;
}
bool isRectangle(PT pt1, PT pt2, PT pt3, PT pt4) {
  PT center = pt1 + pt2 + pt3 + pt4;
  center = center * 0.25;
  if (center == pt1) return false;
  if (pt1 + pt2 == (center * 2.0) && pt3 + pt4 == (center * 2.0) &&
      dist2(pt1, pt2) == dist2(pt3, pt4))
    return true;
  if (pt1 + pt3 == (center * 2.0) && pt2 + pt4 == (center * 2.0) &&
      dist2(pt1, pt3) == dist2(pt2, pt4))
    return true;
  if (pt1 + pt4 == (center * 2.0) && pt2 + pt3 == (center * 2.0) &&
      dist2(pt1, pt4) == dist2(pt3, pt2))
    return true;
  return false;
}
double area(PT a, PT b, PT c) {
  PT ab = b - a, ac = c - a;
  return 0.5 * (abs(cross(ab, ac)));
}
PT ProjectPointLine(PT a, PT b, PT c) {
  return a + (b - a) * dot(c - a, b - a) / dot(b - a, b - a);
}
PT ProjectPointSegment(PT a, PT b, PT c) {
  double r = dot(b - a, b - a);
  if (fabs(r) < EPS) return a;
  r = dot(c - a, b - a) / r;
  if (r < 0) return a;
  if (r > 1) return b;
  return a + (b - a) * r;
}
double DistancePointPlane(double x, double y, double z, double a, double b,
                          double c, double d) {
  return fabs(a * x + b * y + c * z - d) / sqrt(a * a + b * b + c * c);
}
bool LinesParallel(PT a, PT b, PT c, PT d) {
  return fabs(cross(b - a, c - d)) < EPS;
}
bool LinesCollinear(PT a, PT b, PT c, PT d) {
  return LinesParallel(a, b, c, d) && fabs(cross(a - c, d - c)) < EPS;
}
bool SegmentsIntersect(PT a, PT b, PT c, PT d) {
  if (cross(d - a, b - a) * cross(c - a, b - a) > 0) return false;
  if (cross(a - c, d - c) * cross(b - c, d - c) > 0) return false;
  return true;
}
PT ComputeLineIntersection(PT a, PT b, PT c, PT d) {
  b = b - a;
  d = c - d;
  c = c - a;
  if (dot(b, b) < EPS) return a;
  if (dot(d, d) < EPS) return c;
  return a + b * cross(c, d) / cross(b, d);
}
PT ComputeCircleCenter(PT a, PT b, PT c) {
  b = (a + b) / 2;
  c = (a + c) / 2;
  return ComputeLineIntersection(b, b + RotateCW90(a - b), c,
                                 c + RotateCW90(a - c));
}
bool PointInPolygon(const vector<PT> &p, PT q) {
  bool c = 0;
  for (int i = 0; i < p.size(); i++) {
    int j = (i + 1) % p.size();
    if ((p[i].y <= q.y && q.y < p[j].y || p[j].y <= q.y && q.y < p[i].y) &&
        q.x < p[i].x + (p[j].x - p[i].x) * (q.y - p[i].y) / (p[j].y - p[i].y))
      c = !c;
  }
  return c;
}
bool PointOnPolygon(const vector<PT> &p, PT q) {
  for (int i = 0; i < p.size(); i++)
    if (dist2(ProjectPointSegment(p[i], p[(i + 1) % p.size()], q), q) < EPS)
      return true;
  return false;
}
vector<PT> CircleLineIntersection(PT a, PT b, PT c, double r) {
  vector<PT> ret;
  PT d = b - a;
  double D = cross(a - c, b - c);
  double e = r * r * dot(d, d) - D * D;
  if (e < 0) return ret;
  e = sqrt(e);
  ret.push_back(c + PT(D * d.y + (d.y >= 0 ? 1 : -1) * d.x * e,
                       -D * d.x + fabs(d.y) * e) /
                        dot(d, d));
  if (e > 0)
    ret.push_back(c + PT(D * d.y - (d.y >= 0 ? 1 : -1) * d.x * e,
                         -D * d.x - fabs(d.y) * e) /
                          dot(d, d));
  return ret;
}
vector<PT> CircleCircleIntersection(PT a, PT b, double r, double R) {
  vector<PT> ret;
  double d = sqrt(dist2(a, b));
  if (d > r + R || d + min(r, R) < max(r, R)) return ret;
  double x = (d * d - R * R + r * r) / (2 * d);
  double y = sqrt(r * r - x * x);
  PT v = (b - a) / d;
  ret.push_back(a + v * x + RotateCCW90(v) * y);
  if (y > 0) ret.push_back(a + v * x - RotateCCW90(v) * y);
  return ret;
}
double dist(double xa, double ya, double xb, double yb) {
  xa -= xb;
  ya -= yb;
  return sqrt(xa * xa + ya * ya);
}
double angle(double ox, double oy, double ax, double ay, double bx, double by) {
  double a, b, c, alpha;
  a = dist(ax, ay, bx, by);
  b = dist(ox, oy, ax, ay);
  c = dist(ox, oy, bx, by);
  alpha = acos((a * a - b * b - c * c) / (-2.0 * b * c));
  return alpha;
}
int Min, d, n, a[1001], ans;
bool check1(int a1, int d) {
  int ans1 = abs(a1 - a[1]);
  for (int i = 2; i <= n; i++) {
    a1 += d;
    ans1 = max(ans1, abs(a1 - a[i]));
    if (ans1 > ans) {
      return 0;
    }
  }
  if (ans1 < ans) {
    ans = ans1;
    return 1;
  } else
    return 0;
}
bool check(int x) {
  for (int i = -x; i <= x; i++) {
  }
  return 0;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  sort(a + 1, a + n + 1);
  ans = 100000;
  for (int i = a[1] - 2e4; i <= a[1] + 2e4; i++) {
    if (abs(a[1] - i) >= ans) continue;
    int r = 100000;
    int l = 0;
    for (int j = 2; j <= n; j++) {
      r = min(r, (a[j] - i + abs(a[1] - i)) / (j - 1));
      l = max(l, (a[j] - i - abs(a[1] - i)) / (j - 1));
    }
    l = max(l - 20, 0);
    r += 20;
    for (int j = l; j <= r; j++) {
      if (check1(i, j)) {
        Min = i;
        d = j;
      }
    }
  }
  cout << ans << endl << Min << " " << d;
  return 0;
}
