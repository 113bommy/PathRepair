#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
struct Frac {
  long long s, t;
  Frac(long long ss = 0, long long tt = 1) {
    s = ss;
    t = tt;
    if (t < 0) {
      t = -t;
      s = -s;
    }
  }
};
bool operator<(const Frac& a, const Frac& b) { return a.s * b.t < a.t * b.s; }
bool operator>(const Frac& a, const Frac& b) { return b < a; }
bool operator<=(const Frac& a, const Frac& b) { return !(a > b); }
bool operator>=(const Frac& a, const Frac& b) { return !(a < b); }
struct Point {
  long long x, y;
  Point(long long xx = 0, long long yy = 0) {
    x = xx;
    y = yy;
  }
};
Point operator+(const Point& a, const Point& b) {
  return Point(a.x + b.x, a.y + b.y);
}
Point operator-(const Point& a, const Point& b) {
  return Point(a.x - b.x, a.y - b.y);
}
long long operator*(const Point& a, const Point& b) {
  return a.x * b.x + a.y * b.y;
}
long long operator^(const Point& a, const Point& b) {
  return a.x * b.y - a.y * b.x;
}
bool operator<(const Point& a, const Point& b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}
Point q[10010];
void gethull(Point* a, int n, Point* b, int& m) {
  int cnt = 0;
  m = 0;
  for (int i = 1; i <= n; i++) {
    while (cnt > 1 && ((q[cnt] - q[cnt - 1]) ^ (a[i] - q[cnt - 1])) <= 0) cnt--;
    q[++cnt] = a[i];
  }
  for (int i = 1; i <= cnt; i++) b[++m] = q[i];
  cnt = 0;
  for (int i = 1; i <= n; i++) {
    while (cnt > 1 && ((q[cnt] - q[cnt - 1]) ^ (a[i] - q[cnt - 1])) >= 0) cnt--;
    q[++cnt] = a[i];
  }
  for (int i = cnt - 1; i > 1; i--) b[++m] = q[i];
  return;
}
bool solve(Point* a, int n, Point* b, int m, int l, int r) {
  Frac mn(-INF, 1), mx(INF, 1);
  int k = 0;
  for (int i = l + 1; i < r; i++) {
    Frac tmp((a[i] - a[r]) * (a[i] - a[l]), (a[i] - a[r]) ^ (a[i] - a[l]));
    if (tmp > mn) mn = tmp, k = i;
  }
  for (int i = r % n + 1; i != l; i = i % n + 1) {
    Frac tmp((a[i] - a[r]) * (a[i] - a[l]), (a[i] - a[r]) ^ (a[i] - a[l]));
    if (tmp < mx) mx = tmp;
  }
  bool bound = false;
  for (int i = 1; i <= m; i++) {
    long long dot = (b[i] - a[r]) * (b[i] - a[l]);
    long long cross = (b[i] - a[r]) ^ (b[i] - a[l]);
    Frac tmp(dot, cross);
    if (cross < 0 && tmp >= mn) {
      mn = tmp;
      bound = true;
    }
    if (cross > 0 && tmp <= mx) {
      mx = tmp;
      bound = true;
    }
    if (cross == 0 && dot <= 0) mn = Frac(INF, 1), mx = Frac(-INF, 1);
  }
  if ((bound && mn < mx) || (!bound && mn <= mx))
    return true;
  else if (k)
    return solve(a, n, b, m, l, k) || solve(a, n, b, m, k, r);
  else
    return false;
}
Point c[10010];
bool check(Point* a, int n, Point* b, int m) {
  if (n == 1) return true;
  int num;
  gethull(a, n, c, num);
  bool flag = solve(c, num, b, m, 1, num);
  return flag;
}
Point A[10010], B[10010];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%I64d %I64d", &A[i].x, &A[i].y);
  for (int i = 1; i <= m; i++) scanf("%I64d %I64d", &B[i].x, &B[i].y);
  sort(A + 1, A + n + 1);
  sort(B + 1, B + m + 1);
  if (check(A, n, B, m) || check(B, m, A, n))
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
