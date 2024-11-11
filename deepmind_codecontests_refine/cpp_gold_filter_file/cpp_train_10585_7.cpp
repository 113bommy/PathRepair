#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
template <class T>
inline T bigMod(T p, T e, T M) {
  long long ret = 1;
  for (; e > 0; e >>= 1) {
    if (e & 1) ret = (ret * p) % M;
    p = (p * p) % M;
  }
  return (T)ret;
}
template <class T>
inline T modInverse(T a, T M) {
  return bigMod(a, M - 2, M);
}
template <class T>
inline T gcd(T a, T b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <class T>
inline T lcm(T a, T b) {
  a = abs(a);
  b = abs(b);
  return (a / gcd(a, b)) * b;
}
template <class T>
inline string int2String(T a) {
  ostringstream str;
  str << a;
  return str.str();
}
template <class T>
inline T string2int(string a) {
  stringstream str(a);
  T b;
  str >> b;
  return b;
}
template <class T>
inline void read(T& r) {
  r = 0;
  int f = 1;
  char ch = getchar();
  while (ch < '0' or ch > '9') {
    f = (ch == '-' ? -1 : 1), ch = getchar();
  }
  while (ch >= '0' and ch <= '9') {
    r = r * 10 + ch - '0', ch = getchar();
  }
  r *= f;
}
const int dr[] = {0, 1, 0, -1, -1, 1, 1, -1, -2, -2, 2, 2, -1, -1, 1, 1};
const int dc[] = {1, 0, -1, 0, 1, 1, -1, -1, -1, 1, -1, 1, -2, 2, -2, 2};
double sqr(double x) { return x * x; }
struct Point {
  int x, y;
  Point() {}
  Point(int _x, int _y) {
    x = _x;
    y = _y;
  }
};
Point operator+(const Point& u, const Point& v) {
  return Point(u.x + v.x, u.y + v.y);
}
Point operator-(const Point& u, const Point& v) {
  return Point(u.x - v.x, u.y - v.y);
}
long long crsp(Point u, Point v) {
  return (long long)u.x * v.y - (long long)u.y * v.x;
}
long long dotp(Point u, Point v) {
  return (long long)u.x * v.y + (long long)u.y * v.x;
}
int turn(Point st, Point mid, Point ed) {
  long long v = crsp(mid - st, ed - st);
  if (!v) return 2;
  return v > 0 ? 1 : -1;
}
double polygoan_area(vector<Point> p, int n) {
  double area = 0;
  for (int i = 0; i < p.size(); i++)
    area += ((p[i].x * p[(i + 1) % n].y) - (p[(i + 1) % n].x * p[i].y));
  return area * .5;
}
inline bool pointInsidePlygoan(vector<Point> v, Point p) {
  int s = 0;
  for (int i = int(0); i < int(int(v.size())); i++) {
    std::vector<Point> tmp;
    tmp.push_back(v[i]);
    tmp.push_back(v[(i + 1) % int(v.size())]);
    tmp.push_back(p);
    if (polygoan_area(tmp, 3) > 1e-9)
      s++;
    else
      s--;
  }
  s = abs(s);
  return (s == int(v.size()));
}
struct lineSegment {
  Point A, B;
  lineSegment() {}
  lineSegment(Point _A, Point _B) {
    A = _A;
    B = _B;
  }
  lineSegment(int ax, int ay, int bx, int by) {
    A = Point(ax, ay);
    B = Point(bx, by);
  }
};
bool OnSegment(Point p, lineSegment line) {
  if ((turn(line.A, line.B, p)) == 2) {
    Point r = line.A;
    Point s = line.B;
    if ((long long)(p.x - r.x) * (p.x - s.x) <= 0 &&
        (long long)(p.y - r.y) * (p.y - s.y) <= 0)
      return 1;
  }
  return 0;
}
bool lineIntersection(lineSegment p, lineSegment q) {
  if (turn(p.A, p.B, q.A) == -turn(p.A, p.B, q.B) &&
      turn(q.A, q.B, p.A) == -turn(q.A, q.B, p.B))
    return 1;
  if ((turn(p.A, p.B, q.A) == 2 && OnSegment(q.A, lineSegment(p.A, p.B))) ||
      (turn(p.A, p.B, q.B) == 2 && OnSegment(q.B, lineSegment(p.A, p.B))) ||
      (turn(q.A, q.B, p.A) == 2 && OnSegment(p.A, lineSegment(q.A, q.B))) ||
      (turn(q.A, q.B, p.B) == 2 && OnSegment(p.B, lineSegment(q.A, q.B))))
    return 1;
  return 0;
}
int main() {
  vector<Point> a, b;
  int x, y;
  for (int i = int(0); i < int(4); i++) {
    scanf("%d %d", &x, &y);
    a.push_back(Point(x, y));
  }
  for (int i = int(0); i < int(4); i++) {
    scanf("%d %d", &x, &y);
    b.push_back(Point(x, y));
  }
  for (int i = int(0); i < int(4); i++) {
    if (pointInsidePlygoan(a, b[i])) {
      puts("YES");
      return 0;
    }
  }
  for (int i = int(0); i < int(4); i++) {
    if (pointInsidePlygoan(b, a[i])) {
      puts("YES");
      return 0;
    }
  }
  for (int i = int(0); i < int(4); i++) {
    lineSegment xx = lineSegment(a[i], a[(i + 1) % 4]);
    for (int j = int(0); j < int(4); j++) {
      lineSegment yy = lineSegment(b[j], b[(j + 1) % 4]);
      if (lineIntersection(xx, yy)) return puts("YES");
    }
  }
  puts("NO");
  return 0;
}
