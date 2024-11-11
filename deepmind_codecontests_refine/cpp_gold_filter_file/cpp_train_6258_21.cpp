#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
const double eps = 1e-14;
char buf[1 << 12], *pp1 = buf, *pp2 = buf, nc;
int ny;
inline char gc() { return getchar(); }
inline long long read() {
  long long x = 0;
  for (ny = 1; nc = gc(), (nc < 48 || nc > 57) && nc != EOF;)
    if (nc == 45) ny = -1;
  if (nc < 0) return nc;
  for (x = nc - 48; nc = gc(), 47 < nc && nc < 58 && nc != EOF;
       x = (x << 3) + (x << 1) + (nc ^ 48))
    ;
  return x * ny;
}
int n, top, a[MAXN], b[MAXN];
long long t;
double p[MAXN], Max;
struct Point {
  double x, y;
  int id;
  Point(double x = 0, double y = 0, int id = 0) : x(x), y(y), id(id) {}
  double K() { return y / x; }
} s[MAXN], stk[MAXN];
inline Point operator-(Point a, Point b) { return Point(a.x - b.x, a.y - b.y); }
inline double operator^(Point a, Point b) { return a.x * b.y - a.y * b.x; }
inline int sig(double x) { return x < -eps ? -1 : x > eps ? 1 : 0; }
struct Mat {
  double a[3][3];
  inline double* operator[](int x) { return a[x]; }
  inline friend Mat operator*(Mat a, Mat b) {
    Mat c;
    for (int i = (0); i <= (2); i++)
      for (int j = (0); j <= (2); j++) c[i][j] = 0;
    for (int i = (0); i <= (2); i++)
      for (int j = (0); j <= (2); j++)
        for (int k = (0); k <= (2); k++) c[i][j] += a[i][k] * b[k][j];
    return c;
  }
} coef, st, ST[40];
int main() {
  n = read(), t = read();
  for (int i = (1); i <= (n); i++)
    scanf("%d%d%lf", a + i, b + i, p + i), s[i] = Point(p[i], p[i] * a[i], i),
                                           Max = max(Max, p[i] * b[i]);
  sort(s + 1, s + n + 1, [](Point x, Point y) {
    return !sig(x.x - y.x) ? sig(x.y - y.y) > 0 : sig(x.x - y.x) < 0;
  });
  for (int i = (1); i <= (n); i++) {
    if (i != 1 && !sig(s[i].x - s[i - 1].x)) continue;
    for (;
         top > 1 && sig((s[i] - stk[top - 1]) ^ (stk[top] - stk[top - 1])) <= 0;
         top--)
      ;
    stk[++top] = s[i];
  }
  int now = 1;
  st[2][0] = 1;
  for (long long l = 0, r; l < t; l = r) {
    double s = st[1][0] * Max - st[0][0];
    for (; now < top && (stk[now + 1] - stk[now]).K() >= -s; now++)
      ;
    int j = stk[now].id;
    coef[0][0] = 1 - p[j], coef[0][1] = p[j] * Max, coef[0][2] = p[j] * a[j];
    coef[1][0] = 0, coef[1][1] = coef[1][2] = 1, coef[2][0] = coef[2][1] = 0,
    coef[2][2] = 1;
    ST[0] = coef;
    for (int i = (1); i <= (34); i++) ST[i] = ST[i - 1] * ST[i - 1];
    r = l;
    for (int i = (34); i >= (0); i--)
      if (r + (1ll << i) < t) {
        Mat t = ST[i] * st;
        double ss = t[1][0] * Max - t[0][0];
        if (now == top || (stk[now + 1] - stk[now]).K() < -ss)
          r += 1ll << i, st = t;
      }
    st = ST[0] * st, r++;
  }
  printf("%.10lf", st[0][0]);
  return 0;
}
