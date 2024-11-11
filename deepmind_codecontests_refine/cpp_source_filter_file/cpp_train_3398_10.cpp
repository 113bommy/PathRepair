#include <bits/stdc++.h>
long long dx[4] = {0, -1, 0, 1};
long long dy[4] = {1, 0, -1, 0};
using namespace std;
class pa3 {
 public:
  long long x, y, z;
  pa3(long long x = 0, long long y = 0, long long z = 0) : x(x), y(y), z(z) {}
  bool operator<(const pa3 &p) const {
    if (x != p.x) return x < p.x;
    if (y != p.y) return y < p.y;
    return z < p.z;
  }
  bool operator>(const pa3 &p) const {
    if (x != p.x) return x > p.x;
    if (y != p.y) return y > p.y;
    return z > p.z;
  }
  bool operator==(const pa3 &p) const {
    return x == p.x && y == p.y && z == p.z;
  }
  bool operator!=(const pa3 &p) const {
    return !(x == p.x && y == p.y && z == p.z);
  }
};
class pa4 {
 public:
  double x;
  long long y, z, w;
  pa4(double x = 0, long long y = 0, long long z = 0, long long w = 0)
      : x(x), y(y), z(z), w(w) {}
  bool operator<(const pa4 &p) const {
    if (x != p.x) return x < p.x;
    if (y != p.y) return y < p.y;
    if (z != p.z) return z < p.z;
    return w < p.w;
  }
  bool operator>(const pa4 &p) const {
    if (x != p.x) return x > p.x;
    if (y != p.y) return y > p.y;
    if (z != p.z) return z > p.z;
    return w > p.w;
  }
  bool operator==(const pa4 &p) const {
    return x == p.x && y == p.y && z == p.z && w == p.w;
  }
};
class pa2 {
 public:
  long long x, y;
  pa2(long long x = 0, long long y = 0) : x(x), y(y) {}
  pa2 operator+(pa2 p) { return pa2(x + p.x, y + p.y); }
  pa2 operator-(pa2 p) { return pa2(x - p.x, y - p.y); }
  pa2 operator*(long long a) { return pa2(x * a, y * a); }
  bool operator<(const pa2 &p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator>(const pa2 &p) const { return x != p.x ? x > p.x : y > p.y; }
  bool operator==(const pa2 &p) const {
    return abs(x - p.x) == 0 && abs(y - p.y) == 0;
  }
  bool operator!=(const pa2 &p) const {
    return !(abs(x - p.x) == 0 && abs(y - p.y) == 0);
  }
};
class Point {
 public:
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  Point operator*(double a) { return Point(x * a, y * a); }
  Point operator/(double a) { return Point(x / a, y / a); }
  double absv() { return sqrt(norm()); }
  double norm() { return x * x + y * y; }
  bool operator<(const Point &p) const { return x != p.x ? x < p.x : y < p.y; }
  bool operator==(const Point &p) const {
    return fabs(x - p.x) < (1e-10) && fabs(y - p.y) < (1e-10);
  }
};
struct Segment {
  Point p1, p2;
};
double dot(Point a, Point b) { return a.x * b.x + a.y * b.y; }
double cross(Point a, Point b) { return a.x * b.y - a.y * b.x; }
bool parareru(Point a, Point b, Point c, Point d) {
  return abs(cross(a - b, d - c)) < (1e-10);
}
double distance_ls_p(Point a, Point b, Point c) {
  if (dot(b - a, c - a) < (1e-10)) return (c - a).absv();
  if (dot(a - b, c - b) < (1e-10)) return (c - b).absv();
  return abs(cross(b - a, c - a)) / (b - a).absv();
}
bool is_intersected_ls(Segment a, Segment b) {
  if (a.p1 == b.p1 || a.p2 == b.p1 || a.p1 == b.p2 || a.p2 == b.p2)
    return false;
  if (parareru((a.p2), (a.p1), (a.p1), (b.p2)) &&
      parareru((a.p2), (a.p1), (a.p1), (b.p1))) {
    if (dot(a.p1 - b.p1, a.p1 - b.p2) < (1e-10)) return true;
    if (dot(a.p2 - b.p1, a.p2 - b.p2) < (1e-10)) return true;
    if (dot(a.p1 - b.p1, a.p2 - b.p1) < (1e-10)) return true;
    if (dot(a.p1 - b.p2, a.p2 - b.p2) < (1e-10)) return true;
    return false;
  } else
    return (cross(a.p2 - a.p1, b.p1 - a.p1) * cross(a.p2 - a.p1, b.p2 - a.p1) <
            (1e-10)) &&
           (cross(b.p2 - b.p1, a.p1 - b.p1) * cross(b.p2 - b.p1, a.p2 - b.p1) <
            (1e-10));
}
double segment_dis(Segment a, Segment b) {
  if (is_intersected_ls(a, b)) return 0;
  double r = distance_ls_p(a.p1, a.p2, b.p1);
  r = min(r, distance_ls_p(a.p1, a.p2, b.p2));
  r = min(r, distance_ls_p(b.p1, b.p2, a.p2));
  r = min(r, distance_ls_p(b.p1, b.p2, a.p1));
  return r;
}
Point intersection_ls(Segment a, Segment b) {
  Point ba = b.p2 - b.p1;
  double d1 = abs(cross(ba, a.p1 - b.p1));
  double d2 = abs(cross(ba, a.p2 - b.p1));
  double t = d1 / (d1 + d2);
  return a.p1 + (a.p2 - a.p1) * t;
}
string itos(long long i) {
  ostringstream s;
  s << i;
  return s.str();
}
long long gcd(long long v, long long b) {
  if (v > b) return gcd(b, v);
  if (v == b) return b;
  if (b % v == 0) return v;
  return gcd(v, b % v);
}
double distans(double x1, double y1, double x2, double y2) {
  double rr = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  return sqrt(rr);
}
long long beki(long long wa, long long rr, long long warukazu) {
  if (rr == 0) return 1 % warukazu;
  if (rr == 1) return wa % warukazu;
  if (rr % 2 == 1) return (beki(wa, rr - 1, warukazu) * wa) % warukazu;
  long long zx = beki(wa, rr / 2, warukazu);
  return (zx * zx) % warukazu;
}
double bekid(double w, long long r) {
  if (r == 0) return 1.0;
  if (r == 1) return w;
  if (r % 2) return bekid(w, r - 1) * w;
  double f = bekid(w, r / 2);
  return f * f;
}
long long siz;
vector<long long> a[2], ve[2];
void dfs(long long r, long long id, long long num) {
  if (id == siz) {
    ve[num].push_back(r);
    return;
  }
  while (1) {
    dfs(r, id + 1, num);
    if ((1e18) / r < a[num][id]) break;
    r *= a[num][id];
    if (r <= 0) return;
    if (r > (1e18)) return;
  }
}
long long ch(long long e) {
  long long g = 0;
  for (auto v : ve[0]) {
    long long f = e / v;
    g += upper_bound(ve[1].begin(), ve[1].end(), f) - ve[1].begin();
  }
  return g;
}
signed main() {
  long long n, k;
  cin >> n;
  if (n == 1) {
    long long pp;
    cin >> pp >> k;
    long long d = 1;
    for (long long i = 0; i < k; i++) d *= pp;
    cout << d << endl;
    return 0;
  }
  for (long long i = 0; i < n; i++) {
    long long y;
    cin >> y;
    a[i % 2].push_back(y);
  }
  cin >> k;
  siz = a[0].size();
  dfs(1, 0, 0);
  siz = a[1].size();
  dfs(1, 0, 1);
  sort(ve[0].begin(), ve[0].end());
  sort(ve[1].begin(), ve[1].end());
  long long si = 0, ue = 1e18, me;
  while (ue - si > 1) {
    long long me = (ue + si) / 2;
    if (ch(me) < k)
      si = me;
    else
      ue = me;
  }
  cout << ue << endl;
  return 0;
}
