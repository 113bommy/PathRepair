#include <bits/stdc++.h>
using namespace std;
const int N = 505;
double ans, h, f, x[N], y[N];
int n, i, j;
struct vct {
  double x1, y1, x2, y2, dx, dy, ang;
  int flg;
  vct(double X1 = 0, double Y1 = 0, double X2 = 0, double Y2 = 0) {
    x1 = X1;
    y1 = Y1;
    x2 = X2;
    y2 = Y2;
    dx = X2 - X1;
    dy = Y2 - Y1;
    ang = -atan2(dy, dx);
  }
} line[50], q[50];
int l, r, ln, tn;
struct pt {
  double x, y;
  pt(double X = 0, double Y = 0) {
    x = X;
    y = Y;
  }
  double operator*(const pt &B) { return x * B.y - y * B.x; }
} conv[50];
int cn;
double zoom(double x) {
  if (x == 0) return 0;
  return x * (f + h) / (f - h);
}
double trapezium(int wh) {
  double l = zoom(x[wh]), r = zoom(y[wh]);
  return (y[wh] - x[wh] + r - l) * h;
}
void build(int wh, int sgn) {
  double l = zoom(x[wh]), r = zoom(y[wh]);
  if (sgn == 1) {
    line[++ln] = vct(x[wh], h, y[wh], h);
    line[++ln] = vct(y[wh], h, r, -h);
    line[++ln] = vct(r, -h, l, -h);
    line[++ln] = vct(l, -h, x[wh], h);
  } else {
    line[++ln] = vct(y[wh], -h, x[wh], -h);
    line[++ln] = vct(x[wh], -h, l, h);
    line[++ln] = vct(l, h, r, h);
    line[++ln] = vct(r, h, y[wh], -h);
  }
}
int parallel(vct l1, vct l2) {
  pt A = pt(l1.dx, l1.dy), B = pt(l2.dx, l2.dy);
  if (fabs(A * B) > 1e-9) return 0;
  double cj = pt(l1.x2 - l2.x1, l1.y2 - l2.y1) * B;
  if (cj < 0)
    return -1;
  else
    return 1;
}
bool cmp(const vct &A, const vct &B) {
  if (fabs(A.ang - B.ang) > 1e-9) return A.ang < B.ang;
  if (parallel(A, B) == -1)
    return 0;
  else
    return 1;
}
pt cross(vct A, vct B) {
  double S1 = pt(A.x1 - B.x1, A.y1 - B.y1) * pt(B.dx, B.dy),
         S2 = pt(B.dx, B.dy) * pt(A.dx, A.dy);
  return pt(A.x1 + A.dx * S1 / S2, A.y1 + A.dy * S1 / S2);
}
bool judger(int i) {
  if (l == r) return 0;
  pt P = cross(q[r], q[r - 1]);
  if ((pt(P.x - line[i].x1, P.y - line[i].y1) * pt(line[i].dx, line[i].dy)) < 0)
    return 1;
  return 0;
}
bool judgel(int i) {
  if (l == r) return 0;
  pt P = cross(q[l], q[l + 1]);
  if ((pt(P.x - line[i].x1, P.y - line[i].y1) * pt(line[i].dx, line[i].dy)) < 0)
    return 1;
  return 0;
}
bool judget() {
  if (r - l <= 1) return 0;
  pt P = cross(q[r], q[r - 1]);
  if ((pt(P.x - q[l].x1, P.y - q[l].y1) * pt(q[l].dx, q[l].dy)) < 0) return 1;
  return 0;
}
double common(int a, int b) {
  int i;
  double sum = 0;
  ln = 0;
  line[++ln] = vct(-1e9, 5000, 1e9, 5000);
  line[++ln] = vct(1e9, 5000, 1e9, -5000);
  line[++ln] = vct(1e9, -5000, -1e9, -5000);
  line[++ln] = vct(-1e9, -5000, -1e9, 5000);
  build(a, 1);
  build(b, -1);
  sort(line + 1, line + 1 + ln, cmp);
  tn = ln;
  ln = 0;
  for (i = 1; i <= tn; i++)
    if (i == 1 || fabs(line[i].ang - line[i - 1].ang) > 1e-9)
      line[++ln] = line[i];
  q[l = r = 1] = line[1];
  for (i = 2; i <= ln; i++) {
    while (judger(i)) r--;
    while (judgel(i)) l++;
    if (l > r) return 0;
    q[++r] = line[i];
  }
  while (judget()) r--;
  if (r - l <= 1) return 0;
  cn = 0;
  for (i = l; i <= r - 1; i++) conv[++cn] = cross(q[i], q[i + 1]);
  conv[++cn] = cross(q[r], q[l]);
  for (i = 3; i <= cn; i++)
    sum += fabs(pt(conv[i].x - conv[1].x, conv[i].y - conv[1].y) *
                pt(conv[i - 1].x - conv[1].x, conv[i - 1].y - conv[1].y)) /
           2;
  return sum;
}
int main() {
  scanf("%d%lf%lf", &n, &h, &f);
  for (i = 1; i <= n; i++) scanf("%lf%lf", &x[i], &y[i]);
  for (i = 1; i <= n; i++) ans += trapezium(i) * 2;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= n; j++) ans -= common(i, j);
  printf("%.9lf\n", ans);
  return 0;
}
