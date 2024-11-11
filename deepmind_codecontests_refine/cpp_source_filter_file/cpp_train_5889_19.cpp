#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
const long double EPS = 1e-9;
const long double pi = acos(-1.0);
const int MAXN = (int)1e5 + 7;
const int INF = (int)1e9;
const long long LINF = (long long)7e18;
const long long MOD = (long long)1e9 + 7;
const int CHASH = (long long)239017;
const long double DINF = (long double)1000000000000000.0;
void mkfile();
int solve();
int main() {
  srand(228);
  solve();
  return 0;
}
void mkfile() {
  freopen("input.txt", "a+", stdout);
  srand(time(0));
  return;
}
bool equal(double a, double b) { return abs(a - b) < EPS; }
struct Point {
  double x, y;
  int id;
  Point(){};
  Point(double x, double y) : x(x), y(y){};
  Point operator*(double d) { return Point(x * d, y * d); }
  Point operator+(Point p) { return Point(x + p.x, y + p.y); }
  Point operator-(Point p) { return Point(x - p.x, y - p.y); }
  double operator%(Point p) { return x * p.x + y * p.y; }
  double operator*(Point p) { return x * p.y - y * p.x; }
  bool operator==(Point p) { return equal(x, p.x) && equal(y, p.y); }
  double distancetoPoint(Point p) {
    return sqrt((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
  }
  double len() { return sqrt(x * x + y * y); }
  double angle(Point p) { return atan2((*this) * p, (*this) % p); }
  Point turnByAngle(double a) {
    double cosa = cos(a);
    double sina = sin(a);
    return Point(x * cosa - y * sina, x * sina + y * cosa);
  }
  Point getNormVec() { return Point(x / (*this).len(), y / (*this).len()); }
};
Point makeV(Point a, Point b) { return a - b; }
const Point NULLP = Point(1e9 + 7, 1e9 + 9);
const Point EQ = Point(13888, 888283);
const Point INFPTS = Point(1e9 + 17, 1e9 + 19);
struct Line {
  double a, b, c;
  Point q, w;
  Line(){};
  Line(double a, double b, double c) : a(a), b(b), c(c){};
  Line(Point p, Point t) {
    a = t.y - p.y;
    b = p.x - t.x;
    c = -a * p.x - b * p.y;
    q = p;
    w = t;
  }
  bool eq_null(Line l) { return (l.a == a) && (l.b == b) && (l.c == c); }
  double distanceFromPoint(Point p) {
    return (a * p.x + b * p.y + c) / Point(a, b).len();
  }
  bool operator||(Line l) { return equal(Point(a, b) * Point(l.a, l.b), 0); }
  bool ifeq(Line l) {
    Point v1 = makeV(q, w);
    Point v2 = makeV(l.q, l.w);
    Point v11 = makeV(l.w, w);
    Point v22 = makeV(q, l.q);
    if (v1 * v2 == 0 && v11 * v22 == 0) return 1;
    return 0;
  }
  Point operator^(Line l) {
    double d = Point(a, b) * Point(l.a, l.b);
    if (equal(d, 0)) return NULLP;
    double x = (b * l.c - l.b * c) / d;
    double y = (c * l.a - l.c * a) / d;
    return Point(x, y);
  }
};
istream &operator>>(istream &input_stream, Point &a) {
  input_stream >> a.x >> a.y;
  return input_stream;
}
istream &operator>>(istream &input_stream, Line &a) {
  input_stream >> a.a >> a.b >> a.c;
  return input_stream;
}
ostream &operator<<(ostream &output_stream, Point &a) {
  output_stream.precision(15);
  output_stream << fixed << a.x << " " << a.y;
  return output_stream;
}
const int Q = 4;
int n, m;
int a[Q][Q];
int ls[Q][Q], rs[Q][Q], us[Q][Q], ds[Q][Q];
int solve() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < (int)n; i++)
    for (int j = 0; j < (int)m; j++) scanf("%d", &a[i][j]);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      ls[i][j] = a[i][j];
      if (j) ls[i][j] += ls[i][j - 1];
    }
    for (int j = m - 1; j >= 0; --j) {
      rs[i][j] = a[i][j];
      if (j != m - 1) rs[i][j] += rs[i][j + 1];
    }
  }
  for (int j = 0; j < m; ++j) {
    for (int i = 0; i < n; ++i) {
      us[i][j] = a[i][j];
      if (i) us[i][j] += us[i - 1][j];
    }
    for (int i = n - 1; i >= 0; --i) {
      ds[i][j] = a[i][j];
      if (i != n - 1) ds[i][j] += ds[i + 1][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) {
      if (!a[i][j]) {
        ans +=
            (us[i][j] > 0) + (ds[i][j] > 0) + (ls[i][j] > 0) + (rs[i][j] > 0);
      }
    }
  cout << ans;
  return 0;
}
