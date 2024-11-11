#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T read() {
  T f = 0, x = 0;
  char c = getchar();
  while (!isdigit(c)) f = c == '-', c = getchar();
  while (isdigit(c)) x = x * 10 + c - 48, c = getchar();
  return f ? -x : x;
}
namespace run {
const int N = 4e5 + 9;
const double eps = 1e-9, inf = 1e9;
inline double squ(double x) { return x * x; }
struct node {
  double x, y;
  explicit node() {}
  node(double _x, double _y) : x(_x), y(_y) {}
  inline node operator+(const node &A) const { return node(x + A.x, y + A.y); }
  inline node operator-(const node &A) const { return node(x - A.x, y - A.y); }
  inline node operator*(const double &B) const { return node(x * B, y * B); }
} d[N];
inline void print(node A) { cout << A.x << " " << A.y << endl; }
inline double dist(node A, node B) {
  return sqrt(squ(A.x - B.x) + squ(A.y - B.y));
}
struct func1 {
  double k, b;
  explicit func1() {}
  func1(double _k, double _b) : k(_k), b(_b) {}
  inline func1 operator-(const func1 &A) const {
    return func1(k - A.k, b - A.b);
  }
};
inline func1 get(node A, node B) {
  double k = (A.y - B.y) / (A.x - B.x), b = A.y - k * A.x;
  return func1(k, b);
}
struct func2 {
  double l, r, a, b, c;
  explicit func2() {}
  func2(double _l, double _r, double _a, double _b, double _c)
      : l(_l), r(_r), a(_a), b(_b), c(_c) {}
} f[N];
inline func2 get(double l, double r, func1 x, func1 y) {
  double a = squ(x.k) + squ(y.k), b = 2. * x.k * x.b + 2. * y.k * y.b,
         c = squ(x.b) + squ(y.b);
  return func2(l, r, a, b, c);
}
int n, m, tot, top;
double S;
struct point {
  double pos;
  int v;
  explicit point() {}
  point(double _pos, int _v) : pos(_pos), v(_v) {}
  inline bool operator<(const point &A) const {
    if (fabs(pos - A.pos) > eps) return pos < A.pos;
    return v < A.v;
  }
} st[N << 1];
inline bool check(double mid) {
  top = 0;
  for (int i = 1; i <= tot; i++) {
    if (fabs(f[i].a) < eps) {
      double c = f[i].c - squ(mid);
      if (c < eps) {
        double x1 = f[i].l, x2 = f[i].r;
        int tmp = x1 / S;
        x1 -= S * tmp, x2 -= S * tmp;
        while (x2 > 0.) {
          st[++top] = point(x1, 1), st[++top] = point(x2, -1);
          x1 -= S, x1 = max(x1, (double)0.), x2 -= S;
        }
      }
      continue;
    }
    double c = f[i].c - squ(mid);
    double delta = f[i].b * f[i].b - 4. * f[i].a * c;
    if (delta < 0.) continue;
    delta = sqrt(delta);
    double x1 = (-f[i].b - delta) / (f[i].a * 2.),
           x2 = (-f[i].b + delta) / (f[i].a * 2.);
    x1 = max(x1 + f[i].l, f[i].l), x2 = min(x2 + f[i].l, f[i].r);
    if (x1 < x2) {
      int tmp = x1 / S;
      x1 -= S * tmp, x2 -= S * tmp;
      while (x2 > 0.) {
        st[++top] = point(x1, 1), st[++top] = point(x2, -1);
        x1 -= S, x1 = max(x1, (double)0.), x2 -= S;
      }
    }
  }
  sort(st + 1, st + top + 1);
  for (int i = 1, sum = 0; i <= top; i++) {
    sum += st[i].v;
    if (sum == m) return 1;
  }
  return 0;
}
inline double dich() {
  double l = 0., r = inf;
  for (int t = 100; t; t--) {
    double mid = 0.5 * (l + r);
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  return l;
}
inline int next(int id) { return id == n ? 1 : id + 1; }
int main() {
  n = read<int>(), m = read<int>();
  for (int i = 1; i <= n; i++) {
    int x = read<int>(), y = read<int>();
    d[i] = node(x, y);
    if (i > 1) S += dist(d[i], d[i - 1]);
  }
  S += dist(d[1], d[n]), S /= m;
  double sum = 0., tim = 0.;
  int L = 1, R = 1;
  node l = d[1], r;
  while (sum + dist(d[R], d[R + 1]) - eps <= S)
    sum += dist(d[R], d[R + 1]), R++;
  r = d[R], tim = 0.,
  r = r + (d[R + 1] - d[R]) * ((S - sum) / dist(d[R], d[R + 1]));
  do {
    double _l = dist(l, d[next(L)]), _r = dist(r, d[next(R)]);
    if (_l < _r) {
      func1 lx = get(node(0, l.x), node(_l, d[next(L)].x));
      func1 ly = get(node(0, l.y), node(_l, d[next(L)].y));
      double tmpx = r.x, tmpy = r.y;
      l = d[next(L)], L = next(L),
      r = r + (d[next(R)] - d[R]) * (_l / dist(d[next(R)], d[R]));
      func1 rx = get(node(0, tmpx), node(_l, r.x));
      func1 ry = get(node(0, tmpy), node(_l, r.y));
      if (_l > eps) {
        f[++tot] = get(tim, tim + _l, lx - rx, ly - ry);
      }
      tim += _l;
    } else {
      func1 rx = get(node(0, r.x), node(_r, d[next(R)].x));
      func1 ry = get(node(0, r.y), node(_r, d[next(R)].y));
      double tmpx = l.x, tmpy = l.y;
      r = d[next(R)], R = next(R),
      l = l + (d[next(L)] - d[L]) * (_r / dist(d[next(L)], d[L]));
      func1 lx = get(node(0, tmpx), node(_r, l.x));
      func1 ly = get(node(0, tmpy), node(_r, l.y));
      if (_r > eps) {
        f[++tot] = get(tim, tim + _r, lx - rx, ly - ry);
      }
      tim += _r;
    }
  } while (tim <= S * m);
  printf("%.10lf\n", dich());
  return 0;
}
}  // namespace run
int main() { return run::main(); }
