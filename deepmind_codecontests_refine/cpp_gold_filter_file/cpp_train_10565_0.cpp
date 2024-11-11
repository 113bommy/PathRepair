#include <bits/stdc++.h>
using namespace std;
template <class T>
inline void rd(T &x) {
  x = 0;
  char c = getchar();
  int f = 1;
  while (!isdigit(c)) {
    if (c == '-') f = -1;
    c = getchar();
  }
  while (isdigit(c)) x = x * 10 - '0' + c, c = getchar();
  x *= f;
}
bool fg;
void FUCK() {
  printf("YES");
  exit(0);
}
const int N = 1e4 + 10;
const double eps = 1e-12;
int sgn(double x) { return x > -eps ? (x > eps) : -1; }
struct Point {
  double x, y;
  Point(double x = 0, double y = 0) : x(x), y(y) {}
  friend Point operator+(Point A, Point B) {
    return Point(A.x + B.x, A.y + B.y);
  }
  friend Point operator-(Point A, Point B) {
    return Point(A.x - B.x, A.y - B.y);
  }
  friend Point operator*(Point A, double B) { return Point(A.x * B, A.y * B); }
  friend bool operator<(Point A, Point B) {
    return sgn(A.x - B.x) == 0 ? A.y < B.y : A.x < B.x;
  }
};
double Dot(Point A, Point B) { return A.x * B.x + A.y * B.y; }
double Cross(Point A, Point B) { return A.x * B.y - A.y * B.x; }
namespace Calculate_Convex_Hull {
double ag[N];
int rnk[N];
Point tp[N];
bool cmp(int x, int y) {
  return sgn(ag[x] - ag[y]) == 0 ? tp[x] < tp[y] : ag[x] < ag[y];
}
void Convex_Hull(Point *p, int n, Point *q, int &m) {
  for (int i = 1; i < n; ++i)
    if (sgn(p[i].x - p[0].x) < 0 ||
        sgn(p[i].x - p[0].x) == 0 && sgn(p[i].y - p[0].y) < 0)
      swap(p[i], p[0]);
  for (int i = 1; i < n; ++i)
    ag[i] = atan2(p[i].y - p[0].y, p[i].x - p[0].x), rnk[i] = i, tp[i] = p[i];
  sort(rnk + 1, rnk + n, cmp);
  q[m = 0] = p[0];
  for (int i = 1; i < n; ++i) {
    Point cur = p[rnk[i]];
    while (m && sgn(Cross(q[m] - q[m - 1], cur - q[m - 1])) <= 0) m--;
    q[++m] = cur;
  }
  m++;
}
}  // namespace Calculate_Convex_Hull
using Calculate_Convex_Hull::Convex_Hull;
void upd(Point p, Point q, Point *A, int n, Point *B, int m) {
  double l = -1e100, r = 1e100;
  for (int i = 0; i < n; ++i)
    if (sgn(Cross(p - A[i], q - A[i]))) {
      if (sgn(Cross(A[i] - p, q - p)) < 0)
        l = max(l, Dot(p - A[i], q - A[i]) / Cross(p - A[i], q - A[i]));
      else
        r = min(r, Dot(p - A[i], q - A[i]) / Cross(p - A[i], q - A[i]));
    }
  for (int i = 0; i < m; ++i) {
    if (sgn(Cross(p - B[i], q - B[i])) == 0) {
      if (sgn(min(p.x, q.x) - B[i].x) > 0 || sgn(B[i].x - max(p.x, q.x)) > 0)
        continue;
      if (sgn(min(p.y, q.y) - B[i].y) > 0 || sgn(B[i].y - max(p.y, q.y)) > 0)
        continue;
      return;
    }
    if (sgn(Cross(B[i] - p, q - p)) < 0)
      r = min(r, Dot(p - B[i], q - B[i]) / Cross(p - B[i], q - B[i]));
    else
      l = max(l, Dot(p - B[i], q - B[i]) / Cross(p - B[i], q - B[i]));
    if (l >= r - eps) return;
  }
  if (fg) cout << p.x << " " << p.y << " " << q.x << " " << q.y << endl;
  FUCK();
}
Point p[N], A[N], B[N];
int s1, s2, n;
void sol(int l, int r) {
  if ((l + 1) % n == r) {
    upd(p[l], p[r], p, n, B, s2);
    return;
  }
  int x;
  double mx = 1e100;
  for (int i = (l + 1) % n; i != r; i = (i + 1) % n) {
    double tmp =
        Dot(p[i] - p[l], p[i] - p[r]) / Cross(p[i] - p[l], p[i] - p[r]);
    if (tmp < mx) mx = tmp, x = i;
  }
  upd(p[x], p[l], p, n, B, s2);
  upd(p[x], p[r], p, n, B, s2);
  sol(l, x), sol(x, r);
}
void work() {
  Convex_Hull(A, s1, p, n);
  upd(p[0], p[n - 1], p, n, B, s2);
  sol(0, n - 1);
}
int main() {
  rd(s1), rd(s2);
  for (int i = 0; i < s1; ++i) scanf("%lf%lf", &A[i].x, &A[i].y);
  for (int i = 0; i < s2; ++i) scanf("%lf%lf", &B[i].x, &B[i].y);
  if (s1 == 1000 && s2 == 1000 && fabs(A[1].x - 5245) < eps &&
      fabs(A[1].y - 6141) < eps)
    fg = 1;
  work();
  for (int i = 0; i < max(s1, s2); ++i) swap(A[i], B[i]);
  swap(s1, s2);
  work();
  printf("NO");
  return 0;
}
