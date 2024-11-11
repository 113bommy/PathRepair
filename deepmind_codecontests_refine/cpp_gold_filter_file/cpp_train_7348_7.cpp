#include <bits/stdc++.h>
using namespace std;
const int MAXN = 10005;
const long double PI = acos(-1.0);
const long double eps = 1e-15;
template <typename T>
inline void read(T &AKNOI) {
  T x = 0, flag = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') flag = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  AKNOI = flag * x;
}
int n, q;
long double sum[MAXN];
struct point {
  long double x, y;
  point() {}
  point(long double _x, long double _y) : x(_x), y(_y) {}
  inline void input() {
    int _x, _y;
    read(_x);
    read(_y);
    x = _x;
    y = _y;
  }
  friend point operator+(point a, point b) {
    return point(a.x + b.x, a.y + b.y);
  }
  friend point operator-(point a, point b) {
    return point(a.x - b.x, a.y - b.y);
  }
  friend point operator*(point a, long double b) {
    return point(a.x * b, a.y * b);
  }
  friend long double operator^(point a, point b) {
    return a.x * b.y - a.y * b.x;
  }
} p[MAXN], qp;
struct line {
  point u, v;
  line() {}
  line(point _u, point _v) : u(_u), v(_v) {}
};
inline point Intersect(line a, line b) {
  long double k = -((a.u - b.u) ^ (b.v - b.u)) / ((a.v - a.u) ^ (b.v - b.u));
  return a.u + (a.v - a.u) * k;
}
inline int Query(point d, bool x, bool y) {
  int L = 2, R = n, ret = 0;
  while (L <= R) {
    int M = (L + R) >> 1;
    if (((d ^ (p[M] - qp)) > 0) ^ x) {
      ret = M;
      if (y) {
        R = M - 1;
      } else {
        L = M + 1;
      }
    } else {
      if (((p[1] - qp) ^ (p[M] - qp)) > 0) {
        L = M + 1;
      } else {
        R = M - 1;
      }
    }
  }
  return ret;
}
long double Check(long double ang) {
  point d(cos(ang), sin(ang));
  int a, b, flag = ((d ^ (p[1] - qp)) > 0);
  a = Query(d, flag, 1);
  b = Query(d, flag, 0);
  long double ret = sum[b - 1] - sum[a - 1];
  point ia = Intersect(line(p[a], p[a - 1]), line(qp, qp + d));
  point ib = Intersect(line(p[b], p[b + 1]), line(qp, qp + d));
  ret += (ia ^ p[a]) + (p[b] ^ ib) + (ib ^ ia);
  ret = ret * 2 - sum[n];
  return flag ? ret : -ret;
}
void init() {
  read(n);
  read(q);
  for (int i = 1; i <= n; ++i) {
    p[i].input();
  }
  reverse(p + 1, p + n + 1);
  p[0] = p[n];
  p[n + 1] = p[1];
  for (int i = 1; i <= n; ++i) {
    sum[i] = sum[i - 1] + (p[i] ^ p[i + 1]);
  }
}
void solve() {
  while (q--) {
    qp.input();
    bool flag = (Check(0) < Check(PI));
    long double L = 0, R = PI - eps, M;
    while (R - L > eps) {
      M = (L + R) * 0.5;
      if (Check(M) >= 0) {
        (flag ? R : L) = M;
      } else {
        (flag ? L : R) = M;
      }
    }
    printf("%.15lf\n", (double)L);
  }
}
int main() {
  init();
  solve();
  return 0;
}
