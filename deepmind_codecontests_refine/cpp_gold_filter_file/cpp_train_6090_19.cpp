#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
const int N = 6e5 + 5, M = 1e5;
const double eps = 1e-5;
int n, top;
struct point {
  double x, y;
  point(double x = 0, double y = 0) : x(x), y(y) {}
  inline void print() { printf("%d %d\n", (int)(x + 0.5), (int)(y + 0.5)); }
  friend point operator+(const point &a, const point &b) {
    return point(a.x + b.x, a.y + b.y);
  }
  friend point operator-(const point &a, const point &b) {
    return point(a.x - b.x, a.y - b.y);
  }
  friend point operator*(const point &a, const double &b) {
    return point(a.x * b, a.y * b);
  }
  friend point operator/(const point &a, const double &b) {
    return point(a.x / b, a.y / b);
  }
} e[N], st[N], A, B, C;
inline void add(double x, double y) { e[++n] = point(x, y); }
inline double cross(const point &a, const point &b) {
  return a.x * b.y - a.y * b.x;
}
inline bool cmp(const point &a, const point &b) {
  return a.y < b.y || (a.y == b.y && a.x < b.x);
}
inline double dis(point a, point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
inline int dump(double x) { return fabs(x) < eps ? 0 : (x < 0 ? -1 : 1); }
inline bool comp(const point &a, const point &b) {
  int tmp = dump(cross(a - e[1], b - e[1]));
  if (tmp > 0)
    return 1;
  else if (tmp == 0 && dump(dis(a, e[1]) - dis(b, e[1])) < 0)
    return 1;
  return 0;
}
inline void Convex_Hull() {
  std::sort(e + 1, e + 1 + n, cmp);
  std::sort(e + 2, e + 1 + n, comp);
  st[++top] = e[1];
  for (int i = 2; i <= n; i++) {
    while (top > 1 &&
           dump(cross(e[i] - st[top - 1], st[top] - st[top - 1])) >= 0)
      top--;
    st[++top] = e[i];
  }
}
int main() {
  int T = read();
  while (T-- > 0) {
    int x = read(), y = read(), v = read();
    if (x < v)
      add(0, max(y - v + x, 0)), add(0, min(y + v - x, M));
    else
      add(x - v, y);
    if (y < v)
      add(max(x - v + y, 0), 0), add(min(x + v - y, M), 0);
    else
      add(x, y - v);
    if (M - x < v)
      add(M, max(y - v + (M - x), 0)), add(M, min(y + v - (M - x), M));
    else
      add(x + v, y);
    if (M - y < v)
      add(max(x - v + (M - y), 0), M), add(min(x + v - (M - y), M), M);
    else
      add(x, y + v);
  }
  Convex_Hull();
  double ans = 0;
  st[top + 1] = st[1];
  st[top + 2] = st[2];
  for (int i = 1; i <= top; i++) {
    point a = st[i], b = st[i + 1], c = st[i + 2];
    double tmp = dis(a, b) * dis(b, c) * dis(a, c) / fabs(cross(a - b, a - c));
    if (tmp > ans) ans = tmp, A = a, B = b, C = c;
  }
  A.print();
  B.print();
  C.print();
  return 0;
}
