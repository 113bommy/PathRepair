#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.1415926535;
using namespace std;
inline int read() {
  int x = 0, f = 1, ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
inline void writeln(int x) {
  write(x);
  puts("");
}
const int N = 1e5 + 5;
int cot = 0;
int n, L, S;
int w[N], fa[N][20], sum[N][20];
int cmp(long double x) {
  if (fabs(x) < 1e-8) return 0;
  if (x > 0) return 1;
  return -1;
}
inline long double sqr(long double x) { return x * x; }
struct point {
  long double x, y;
  point() {}
  point(long double a, long double b) : x(a), y(b) {}
  point(pair<long double, long double> t) : x(t.first), y(t.second) {}
  void input() { scanf("%lf%lf", &x, &y); }
  friend point operator+(const point &a, const point &b) {
    return point(a.x + b.x, a.y + b.y);
  }
  friend point operator-(const point &a, const point &b) {
    return point(a.x - b.x, a.y - b.y);
  }
  friend bool operator==(const point &a, const point &b) {
    return cmp(a.x - b.x) == 0 && cmp(a.y - b.y) == 0;
  }
  friend point operator*(const point &a, const long double &b) {
    return point(a.x * b, a.y * b);
  }
  long double operator^(const point &b) const { return x * b.y - y * b.x; }
  friend point operator*(const long double &a, const point &b) {
    return point(a * b.x, a * b.y);
  }
  friend point operator/(const point &a, const long double &b) {
    return point(a.x / b, a.y / b);
  }
  long double norm() { return sqrt(sqr(x) + sqr(y)); }
};
struct line {
  point a, b;
  line() {}
  line(point x, point y) : a(x), b(y) {}
};
long double det(const point &a, const point &b) {
  return a.x * b.y - a.y * b.x;
}
bool parallel(line a, line b) { return !cmp(det(a.a - a.b, b.a - b.b)); }
bool parallel2(line a, line b) {
  long double k1 = (a.a.y - a.b.y) / (a.a.x - a.b.x);
  long double k2 = (b.a.y - b.b.y) / (b.a.x - b.b.x);
  return k1 == k2;
}
long double dot(const point &a, const point &b) {
  return a.x * b.x + a.y * b.y;
}
bool line_make_point(line a, line b, point &res) {
  if (parallel(a, b)) return false;
  long double s1 = det(a.a - b.a, b.b - b.a);
  long double s2 = det(a.b - b.a, b.b - b.a);
  res = (s1 * a.b - s2 * a.a) / (s1 - s2);
  return true;
}
bool inter(line l1, line l2) {
  return max(l1.a.x, l1.b.x) >= min(l2.a.x, l2.b.x) &&
         max(l2.a.x, l2.b.x) >= min(l1.a.x, l1.b.x) &&
         max(l1.a.y, l1.b.y) >= min(l2.a.y, l2.b.y) &&
         max(l2.a.y, l2.b.y) >= min(l1.a.y, l1.b.y) &&
         cmp((l2.a - l1.a) ^ (l1.b - l1.a)) *
                 cmp((l2.b - l1.a) ^ (l1.b - l1.a)) <=
             0 &&
         cmp((l1.a - l2.a) ^ (l2.b - l2.a)) *
                 cmp((l1.b - l2.a) ^ (l2.b - l2.a)) <=
             0;
}
bool PointOnSegment(point p, point s, point t) {
  return cmp(det(p - s, t - s)) == 0 && cmp(dot(p - s, p - t)) <= 0;
}
long double dist(const point &a, const point &b) { return (a - b).norm(); }
int main(int argc, char *argv[]) {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  ;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    long double x1[3], y1[3], x2[3], y2[3];
    int tag[3] = {0};
    int medge;
    for (int j = 0; j < 3; j++) {
      cin >> x1[j] >> y1[j] >> x2[j] >> y2[j];
    }
    pair<int, int> AnB;
    pair<long double, long double> AnBP;
    int flag = 0;
    for (int j = 0; j < 3; j++) {
      for (int j1 = 0; j1 < 3; j1++) {
        int flagL = 0, flagR = 0;
        if (j == j1) continue;
        if (x1[j] == x1[j1] && y1[j] == y1[j1]) flagL = 1;
        if (x1[j] == x2[j1] && y1[j] == y2[j1]) flagL = 1;
        if (x2[j] == x1[j1] && y2[j] == y1[j1]) flagR = 1;
        if (x2[j] == x2[j1] && y2[j] == y2[j1]) flagR = 1;
        if (flagL && flagR) {
          flag = -1;
          break;
        }
        if (flagL) {
          AnB.first = j;
          AnB.second = j1;
          tag[j]++;
          tag[j1]++;
          AnBP.first = x1[j];
          AnBP.second = y1[j];
          flag++;
          break;
        }
        if (flagR) {
          AnB.first = j;
          AnB.second = j1;
          tag[j]++;
          tag[j1]++;
          AnBP.first = x2[j];
          AnBP.second = y2[j];
          flag++;
          break;
        }
      }
      if (flag == 1 || flag == -1) break;
    }
    if (flag < 0) {
      cout << "NO" << endl;
      continue;
    }
    for (int fi = 0; fi < 3; fi++) {
      if (tag[fi] == 0) {
        medge = fi;
        break;
      }
    }
    point p1(x1[AnB.first], y1[AnB.first]), p2(x2[AnB.first], y2[AnB.first]);
    line l1(p1, p2);
    point p3(x1[AnB.second], y1[AnB.second]),
        p4(x2[AnB.second], y2[AnB.second]);
    line l2(p3, p4);
    line l3({x1[medge], y1[medge]}, {x2[medge], y2[medge]});
    if (parallel(l1, l2) || parallel(l2, l3)) {
      cout << "NO" << endl;
      continue;
    }
    if (!inter(l1, l3) || !(inter(l2, l3))) {
      cout << "NO" << endl;
      continue;
    }
    pair<long double, long double> _a, _b, _c;
    _a.first = AnBP.first;
    _a.second = AnBP.second;
    if (l1.a.x == _a.first && l1.a.y == _a.second) {
      _b.first = l1.b.x;
      _b.second = l1.b.y;
    } else {
      _b.first = l1.a.x;
      _b.second = l1.a.y;
    }
    if (l2.a.x == _a.first && l2.a.y == _a.second) {
      _c.first = l2.b.x;
      _c.second = l2.b.y;
    } else {
      _c.first = l2.a.x;
      _c.second = l2.a.y;
    }
    long double len1 = dist(_a, _b);
    long double len2 = dist(_a, _c);
    long double len3 = dist(_b, _c);
    long double g =
        (len1 * len1 + len2 * len2 - len3 * len3) / (2 * len1 * len2);
    long double res = acos(g);
    if (cmp((res * 180.00 / PI) - 90) >= 0 || cmp(res * 180.00 / PI) < 0) {
      cout << "NO" << endl;
      continue;
    }
    point lx12, lx23;
    line_make_point(l1, l3, lx12);
    line_make_point(l2, l3, lx23);
    if (!(cmp(lx12.x - l3.a.x) == 0 && cmp(lx12.y - l3.a.y) == 0 ||
          cmp(lx12.x - l3.b.x) == 0 && cmp(lx12.y - l3.b.y) == 0)) {
      cout << "NO" << endl;
      continue;
    }
    if (!((cmp(lx23.x - l3.a.x) == 0 && cmp(lx23.y - l3.a.y) == 0) ||
          cmp(lx23.x - l3.b.x) == 0 && cmp(lx23.y - l3.b.y) == 0)) {
      cout << "NO" << endl;
      continue;
    }
    len1 = dist(lx12, l1.a);
    len2 = dist(lx12, l1.b);
    len3 = dist(lx23, l2.a);
    long double len4 = dist(lx23, l2.b);
    long double b1, s1, b2, s2;
    if (len1 > len2) {
      b1 = len1;
      s1 = len2;
    } else {
      b1 = len2;
      s1 = len1;
    }
    if (len3 > len4) {
      b2 = len3;
      s2 = len4;
    } else {
      b2 = len4;
      s2 = len3;
    }
    if (cmp(s1 / b1 - 0.25) >= 0 && cmp(s2 / b2 - 0.25) >= 0)
      cout << "YES" << endl;
    else {
      cout << "NO" << endl;
    }
  }
}
