#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int S = 0;
  char ch = ' ';
  bool f = 0;
  while (!isdigit(ch)) {
    f |= (ch == '-');
    ch = getchar();
  }
  while (isdigit(ch)) {
    S = (S << 3) + (S << 1) + (ch - '0');
    ch = getchar();
  }
  return (f) ? (-S) : (S);
}
inline void write(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x < 10) {
    putchar(x + '0');
    return;
  }
  write(x / 10);
  putchar(x % 10 + '0');
}
const int N = 100005;
const double PI = acos(-1);
int n;
double jyl_mn = 1e18, jyl_mx = -1e9;
struct point {
  double x, y;
} a[N], xin;
inline double sqr(double x) { return x * x; }
inline double js(point p, point q) { return sqr(p.x - q.x) + sqr(p.y - q.y); }
int main() {
  int i;
  double tmp, wn1, wn2, wn3, oo;
  point p, q;
  n = read();
  scanf("%lf%lf", &xin.x, &xin.y);
  for (i = 1; i <= n; i++) scanf("%lf%lf", &a[i].x, &a[i].y);
  for (i = 1; i <= n; i++) {
    tmp = js(xin, a[i]);
    jyl_mn = min(jyl_mn, tmp);
    jyl_mx = max(jyl_mx, tmp);
  }
  for (i = 1; i <= n; i++) {
    p = a[i];
    q = a[i % n + 1];
    wn1 = js(p, q);
    wn2 = js(p, xin);
    wn3 = js(q, xin);
    if ((wn2 >= wn1 + wn3) || (wn3 >= wn1 + wn2)) continue;
    oo = sqr((xin.x - p.x) * (q.x - p.x) + (xin.y - p.y) * (q.y - p.y)) / wn1;
    oo = wn2 - oo;
    jyl_mn = min(jyl_mn, oo);
  }
  printf("%.18lf\n", PI * (jyl_mx - jyl_mn));
  return 0;
}
