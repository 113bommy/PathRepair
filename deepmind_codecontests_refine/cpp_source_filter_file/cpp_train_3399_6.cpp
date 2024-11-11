#include <bits/stdc++.h>
#pragma GCC optimize(2)
namespace fastIO {
bool IOerror = 0;
inline char nc() {
  static char buf[100000], *p1 = buf + 100000, *pend = buf + 100000;
  if (p1 == pend) {
    p1 = buf;
    pend = buf + fread(buf, 1, 100000, stdin);
    if (pend == p1) {
      IOerror = 1;
      return -1;
    }
  }
  return *p1++;
}
inline bool blank(char ch) {
  return ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t';
}
template <class T>
inline bool read(T& x) {
  bool sign = 0;
  char ch = nc();
  x = 0;
  for (; blank(ch); ch = nc())
    ;
  if (IOerror) return false;
  if (ch == '-') sign = 1, ch = nc();
  for (; ch >= '0' && ch <= '9'; ch = nc()) x = x * 10 + ch - '0';
  if (sign) x = -x;
  return true;
}
inline bool read(double& x) {
  bool sign = 0;
  char ch = nc();
  x = 0;
  for (; blank(ch); ch = nc())
    ;
  if (IOerror) return false;
  if (ch == '-') sign = 1, ch = nc();
  for (; ch >= '0' && ch <= '9'; ch = nc()) x = x * 10 + ch - '0';
  if (ch == '.') {
    double tmp = 1;
    ch = nc();
    for (; ch >= '0' && ch <= '9'; ch = nc())
      tmp /= 10.0, x += tmp * (ch - '0');
  }
  if (sign) x = -x;
  return true;
}
inline bool read(char* s) {
  char ch = nc();
  for (; blank(ch); ch = nc())
    ;
  if (IOerror) return false;
  for (; !blank(ch) && !IOerror; ch = nc()) *s++ = ch;
  *s = 0;
  return true;
}
inline bool read(char& c) {
  for (c = nc(); blank(c); c = nc())
    ;
  if (IOerror) {
    c = -1;
    return false;
  }
  return true;
}
template <class T, class... U>
bool read(T& h, U&... t) {
  return read(h) && read(t...);
}
};  // namespace fastIO
using namespace fastIO;
using namespace std;
const double eps = 1e-10;
struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
};
Point operator+(Point A, Point B) { return Point(A.x + B.x, A.y + B.y); }
Point operator-(Point A, Point B) { return Point(A.x - B.x, A.y - B.y); }
Point operator*(Point A, double p) { return Point(A.x * p, A.y * p); }
Point operator/(Point A, double p) { return Point(A.x / p, A.y / p); }
bool operator<(const Point& A, const Point& B) {
  return A.x < B.x || (A.x == B.x && A.y < B.y);
}
int dcmp(double x) {
  if (fabs(x) < eps)
    return 0;
  else
    return x < 0 ? -1 : 1;
}
bool operator==(const Point& A, const Point& B) {
  return dcmp(A.x - B.x) == 0 && dcmp(A.y - B.y) == 0;
}
double Dot(Point A, Point B) { return A.x * B.x + A.y * B.y; }
double Length(Point A) { return sqrt(Dot(A, A)); }
double Dist2(const Point& A, const Point& B) {
  return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}
double Dist(const Point& A, const Point& B) {
  return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
}
double Angle(Point A, Point B) {
  return acos(Dot(A, B) / Length(A) / Length(B));
}
double Cross(Point A, Point B) { return A.x * B.y - A.y * B.x; }
double Area2(Point A, Point B, Point C) { return Cross(B - A, C - A); }
double DistanceToLine(Point P, Point A, Point B) {
  Point v1 = B - A, v2 = P - A;
  return fabs(Cross(v1, v2)) / Length(v1);
}
Point Normal(Point A) {
  double L = Length(A);
  return Point(-A.y / L, A.x / L);
}
Point Rotate(Point A, double rad) {
  return Point(A.x * cos(rad) - A.y * sin(rad),
               A.x * sin(rad) + A.y * cos(rad));
}
Point GetLineIntersection(Point P, Point v, Point Q, Point w) {
  Point u = P - Q;
  double t = Cross(w, u) / Cross(v, w);
  return P + v * t;
}
double PolygonArea(vector<Point> p) {
  double area = 0;
  int n = p.size();
  for (int i = 1; i < n - 1; i++) area += Cross(p[i] - p[0], p[i + 1] - p[0]);
  return area / 2;
}
double torad(double deg) { return deg / 180 * acos(-1); }
vector<Point> ConvexHull(vector<Point>& p) {
  sort(p.begin(), p.end());
  p.erase(unique(p.begin(), p.end()), p.end());
  int n = p.size();
  int m = 0;
  vector<Point> ch(n + 1);
  for (int i = 0; i < n; i++) {
    while (m > 1 && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
    ch[m++] = p[i];
  }
  int k = m;
  for (int i = n - 2; i >= 0; i--) {
    while (m > k && Cross(ch[m - 1] - ch[m - 2], p[i] - ch[m - 2]) <= 0) m--;
    ch[m++] = p[i];
  }
  if (n > 1) m--;
  ch.resize(m);
  return ch;
}
double diameter2(vector<Point>& points) {
  vector<Point> p = ConvexHull(points);
  int n = p.size();
  if (n == 1) return 0;
  if (n == 2) return Dist2(p[0], p[1]);
  double ans = 0;
  for (int u = 0, v = 1; u < n; u++) {
    for (;;) {
      int diff = Cross(p[u + 1] - p[u], p[v + 1] - p[v]);
      if (diff <= 0) {
        ans = max(ans, Dist2(p[u], p[v]));
        if (diff == 0) ans = max(ans, Dist2(p[u], p[v + 1]));
        break;
      }
      v = (v + 1) % n;
    }
  }
  return ans;
}
Point PolygonCenter(vector<Point> p) {
  Point ans(0, 0);
  int n = p.size();
  if (PolygonArea(p) == 0) return ans;
  for (int i = 0; i < n; i++) {
    ans = ans + (p[i] + p[(i + 1) % n]) * Cross(p[i], p[(i + 1) % n]);
  }
  return ans / PolygonArea(p) / 6.0;
}
struct Line {
  Point P;
  Point v;
  double ang;
  Line() {}
  Line(Point P, Point v) : P(P), v(v) { ang = atan2(v.y, v.x); }
  bool operator<(const Line& L) const { return ang < L.ang; }
};
Point GetLineIntersection(const Line& a, const Line& b) {
  Point u = a.P - b.P;
  double t = Cross(b.v, u) / Cross(a.v, b.v);
  return a.P + a.v * t;
}
bool OnLeft(Line L, Point p) { return Cross(L.v, p - L.P) > 0; }
vector<Point> HalfplaneIntersection(vector<Line> L) {
  int n = L.size();
  sort(L.begin(), L.end());
  int first, last;
  vector<Point> p(n);
  vector<Line> q(n);
  vector<Point> ans;
  q[first = last = 0] = L[0];
  for (int i = 1; i < n; i++) {
    while (first < last && !OnLeft(L[i], p[last - 1])) last--;
    while (first < last && !OnLeft(L[i], p[first])) first++;
    q[++last] = L[i];
    if (fabs(Cross(q[last].v, q[last - 1].v)) < eps) {
      last--;
      if (OnLeft(q[last], L[i].P)) q[last] = L[i];
    }
    if (first < last) p[last - 1] = GetLineIntersection(q[last - 1], q[last]);
  }
  while (first < last && !OnLeft(q[first], p[last - 1])) last--;
  if (last - first <= 1) return ans;
  p[last] = GetLineIntersection(q[last], q[first]);
  for (int i = first; i <= last; i++) ans.push_back(p[i]);
  return ans;
}
bool OnSegment(const Point& p, const Point& a1, const Point& a2) {
  return dcmp(Cross(a1 - p, a2 - p)) == 0 && dcmp(Dot(a1 - p, a2 - p)) < 0;
}
bool SegmentProperIntersection(const Point& a1, const Point& a2,
                               const Point& b1, const Point& b2) {
  double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
         c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
  return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
int IsPointInPolygon(const Point& p, const vector<Point>& poly) {
  int wn = 0;
  int n = poly.size();
  for (int i = 0; i < n; i++) {
    const Point& p1 = poly[i];
    const Point& p2 = poly[(i + 1) % n];
    if (p1 == p || p2 == p || OnSegment(p, p1, p2)) return -1;
    int k = dcmp(Cross(p2 - p1, p - p1));
    int d1 = dcmp(p1.y - p.y);
    int d2 = dcmp(p2.y - p.y);
    if (k > 0 && d1 <= 0 && d2 > 0) wn++;
    if (k < 0 && d2 <= 0 && d1 > 0) wn--;
  }
  if (wn != 0) return 1;
  return 0;
}
bool ConvexPolygonDisjoint(const vector<Point> ch1, const vector<Point> ch2) {
  int c1 = ch1.size();
  int c2 = ch2.size();
  cout << "c1 " << c1 << " "
       << "c2 " << c2 << endl;
  for (int i = 0; i < c1; i++)
    if (IsPointInPolygon(ch1[i], ch2) != 0) return false;
  for (int i = 0; i < c2; i++)
    if (IsPointInPolygon(ch2[i], ch1) != 0) return false;
  for (int i = 0; i < c1; i++)
    for (int j = 0; j < c2; j++)
      if (SegmentProperIntersection(ch1[i], ch1[(i + 1) % c1], ch2[j],
                                    ch2[(j + 1) % c2]))
        return false;
  return true;
}
struct Circle {
  Point c;
  double r;
  Circle(Point c, double r) : c(c), r(r) {}
  Point point(double a) { return Point(c.x + cos(a) * r, c.y + sin(a) * r); }
};
double angle(Point v) { return atan2(v.y, v.x); }
int getCircleCircleIntersection(Circle C1, Circle C2, vector<Point>& sol) {
  double d = Length(C1.c - C2.c);
  if (dcmp(d) == 0) {
    if (dcmp(C1.r - C2.r) == 0) return -1;
    return 0;
  }
  if (dcmp(C1.r + C2.r - d) < 0) return 0;
  if (dcmp(fabs(C1.r - C2.r) - d) > 0) return 0;
  double a = angle(C2.c - C1.c);
  double da = acos((C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d));
  Point p1 = C1.point(a - da), p2 = C1.point(a + da);
  sol.push_back(p1);
  if (p1 == p2) return 1;
  sol.push_back(p2);
  return 2;
}
bool isInCircle(Point p, Circle cir) {
  return dcmp(Dist2(p, cir.c) - cir.r * cir.r) < 0;
}
bool check(vector<Point> p, vector<Circle> cir) {
  if (p.empty()) return true;
  for (int i = 0; i < p.size(); i++) {
    bool ok = true;
    Point tp = Point(-p[i].x, -p[i].y);
    for (int j = 1; j < cir.size(); j++)
      if (isInCircle(tp, cir[j])) {
        ok = false;
        break;
      }
    if (ok) return true;
  }
  return false;
}
const int N = 2e5 + 5;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;
struct ship {
  double x, y, step;
  ship(double x, double y, double step) : x(x), y(y), step(step) {}
};
struct thing {
  int num, period, time;
  bool operator<(const thing& y) const {
    return y.time < time || (y.time == time && y.num < num);
  }
  thing() {}
  thing(int num, int period, int time) : num(num), period(period), time(time) {}
};
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};
bool cmp(Circle a, Circle b) {
  return a.c.x < b.c.x || (a.c.x != b.c.x && a.c.y < b.c.y);
}
vector<Circle> cir;
int fa[4];
int find(int x) {
  if (fa[x] == x)
    return x;
  else
    return fa[x] = find(fa[x]);
}
signed main() {
  int n;
  scanf("%d", &n);
  if (n == 1) {
    double x, y, r;
    scanf("%lf%lf", &x, &y, &r);
    printf("2\n");
  } else if (n == 2) {
    for (int i = 0; i < 2; i++) {
      double x, y, r;
      scanf("%lf%lf", &x, &y, &r);
      cir.push_back(Circle(Point(x, y), r));
    }
    vector<Point> temp;
    if (getCircleCircleIntersection(cir[0], cir[1], temp) == 2)
      printf("4\n");
    else
      printf("3\n");
  } else {
    for (int i = 0; i < 3; i++) fa[i] = i;
    for (int i = 0; i < 3; i++) {
      double x, y, r;
      scanf("%lf%lf%lf", &x, &y, &r);
      cir.push_back(Circle(Point(x, y), r));
    }
    sort(cir.begin(), cir.end(), cmp);
    vector<Point> p;
    for (int i = 0; i < 3; i++) {
      for (int j = i + 1; j < 3; j++) {
        int tp = getCircleCircleIntersection(cir[i], cir[j], p);
        if (tp == 2 || tp == 1) {
          int x = find(i), y = find(j);
          if (x == y)
            continue;
          else
            fa[x] = y;
        }
      }
    }
    vector<Point> tp;
    sort(p.begin(), p.end());
    int V = unique(p.begin(), p.end()) - p.begin();
    for (int i = 0; i < V; i++) {
      bool ok = 0;
      for (int j = 0; j < tp.size(); j++) {
        if (p[i] == tp[j]) {
          ok = 1;
          break;
        }
      }
      if (!ok) tp.push_back(p[i]);
    }
    V = tp.size();
    int E = 0;
    for (int i = 0; i < 3; i++) {
      for (int j = 0; j < V; j++) {
        if (dcmp(Dist2(tp[j], cir[i].c) - cir[i].r * cir[i].r) == 0) {
          E++;
        }
      }
    }
    int C = 0;
    for (int i = 0; i < 3; i++)
      if (fa[i] == i) C++;
    printf("%d\n", E - V + C + 1);
  }
  return 0;
}
