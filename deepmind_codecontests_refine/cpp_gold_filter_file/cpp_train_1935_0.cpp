#include <bits/stdc++.h>
using namespace std;
const int MAXN = 400010;
const long double X = 1e6;
const long double eps = 1e-13;
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
inline int sgn(long double x) {
  if (x > eps) return 1;
  if (x < -eps) return -1;
  return 0;
}
int n, id[MAXN], collinear, tot;
long double pol[MAXN];
struct point {
  long double x, y;
  point() {}
  point(long double _x, long double _y) : x(_x), y(_y) {}
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
} p[MAXN], p2[MAXN];
inline bool polar_cmp(int x, int y) {
  if (sgn(pol[x] - pol[y]) == 0) collinear = 1;
  return pol[x] < pol[y];
}
struct line {
  point u, v;
  long double ang;
  line() {}
  line(point _u, point _v) : u(_u), v(_v) { ang = atan2(v.y - u.y, v.x - u.x); }
  friend bool operator<(line a, line b) {
    return (sgn(a.ang - b.ang) == 0) ? (sgn((a.v - a.u) ^ (b.v - a.u)) < 0)
                                     : (a.ang < b.ang);
  }
} l[MAXN], q[MAXN];
inline point Intersect(line a, line b) {
  long double k = -((a.u - b.u) ^ (b.v - b.u)) / ((a.v - a.u) ^ (b.v - b.u));
  return a.u + (a.v - a.u) * k;
}
inline bool Check(line a, line b, line c) {
  point inter = Intersect(a, b);
  return sgn((c.v - c.u) ^ (inter - c.u)) < 0;
}
long double HalfPlane() {
  sort(l + 1, l + tot + 1);
  int tmp = 0, head, tail;
  for (int i = 1; i <= tot; ++i) {
    if (i == 1 || sgn(l[i].ang - l[i - 1].ang)) {
      l[++tmp] = l[i];
    }
  }
  tot = tmp;
  q[head = tail = 1] = l[1];
  for (int i = 2; i <= tot; ++i) {
    while (head < tail && Check(q[tail - 1], q[tail], l[i])) --tail;
    while (head < tail && Check(q[head + 1], q[head], l[i])) ++head;
    q[++tail] = l[i];
  }
  while (head < tail && Check(q[tail - 1], q[tail], q[head])) --tail;
  while (head < tail && Check(q[head + 1], q[head], q[tail])) ++head;
  tot = 0;
  q[tail + 1] = q[head];
  for (int i = head; i <= tail; ++i) {
    p[++tot] = Intersect(q[i], q[i + 1]);
  }
  long double ret = 0;
  p[tot + 1] = p[1];
  for (int i = 1; i <= tot; ++i) {
    ret += (p[i] ^ p[i + 1]);
  }
  return fabs(ret * 0.5);
}
void init() {
  read(n);
  for (int i = 1, x, y; i <= n; ++i) {
    read(x);
    read(y);
    p[i] = point(x, y);
  }
}
void solve() {
  for (int i = 2; i <= n; ++i) {
    p2[i] = p[i] - p[1];
    pol[i] = atan2(p2[i].y, p2[i].x);
    id[i] = i;
  }
  tot = collinear = 0;
  sort(id + 2, id + n + 1, polar_cmp);
  if (collinear) {
    printf("0.0000000000\n");
    return;
  }
  for (int i = 2; i <= n; ++i) {
    id[n + i - 1] = id[i];
  }
  for (int i = 2, j = i; i <= n; ++i) {
    if (j < i) j = i;
    while (j + 1 < n + i - 1 && sgn(p2[id[i]] ^ p2[id[j + 1]]) >= 0) {
      ++j;
    }
    if (j > i) {
      if (sgn(p2[id[i]] ^ p2[id[j]]) == 0) {
        printf("0.0000000000\n");
        return;
      }
      l[++tot] = line(p[id[i]], p[id[i + 1]]);
      l[++tot] = line(p[id[i]], p[id[j]]);
    }
  }
  l[++tot] = line(point(X, X), point(-X, X));
  l[++tot] = line(point(-X, X), point(-X, -X));
  l[++tot] = line(point(-X, -X), point(X, -X));
  l[++tot] = line(point(X, -X), point(X, X));
  printf("%.10lf\n", (double)HalfPlane());
}
int main() {
  int T;
  read(T);
  while (T--) {
    init();
    solve();
  }
  return 0;
}
