#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-9, inf = 1e9 + 9, pi = acos(-1.0), dtheta = pi / 4.;
double ans, r, h, xa, ya, za, xb, yb, zb, la, ra, mxa, mya, lb, rb, mxb, myb,
    lv, rv, lz, rz;
double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) +
              (z1 - z2) * (z1 - z2));
}
void norm(double &theta) {
  while (theta < -eps) theta += 2 * pi;
  while (theta > 2 * pi - eps) theta -= 2 * pi;
}
double solve(double x1, double y1, double z1, double x2, double y2, double z2) {
  double l1, l2, l, cj, alpha, dj, theta, res;
  if (fabs(z1) < eps && fabs(z2) < eps) return dist(x1, y1, z1, x2, y2, z2);
  l1 = dist(x1, y1, z1, 0, 0, h);
  l2 = dist(x2, y2, z2, 0, 0, h);
  alpha = atan2(y2, x2) - atan2(y1, x1);
  norm(alpha);
  if (alpha > pi) alpha = 2 * pi - alpha;
  l = alpha * r;
  cj = sqrt(r * r + h * h);
  theta = l / cj;
  double u1, v1, u2, v2;
  u1 = 0;
  v1 = l1;
  u2 = l2 * sin(theta);
  v2 = l2 * cos(theta);
  res = sqrt((u1 - u2) * (u1 - u2) + (v1 - v2) * (v1 - v2));
  theta = 2 * pi - theta;
  u1 = 0;
  v1 = l1;
  u2 = l2 * sin(theta);
  v2 = l2 * cos(theta);
  res = min(res, sqrt((u1 - u2) * (u1 - u2) + (v1 - v2) * (v1 - v2)));
  return res;
}
int main() {
  int i, j, s, p, q, it1, it2;
  scanf("%lf%lf", &r, &h);
  scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &za, &xb, &yb, &zb);
  ans = inf;
  if (fabs(za) > eps && fabs(zb) > eps)
    ans = min(ans, solve(xa, ya, za, xb, yb, zb));
  if (fabs(za) < eps && fabs(zb) < eps)
    ans = min(ans, dist(xa, ya, za, xb, yb, zb));
  if (fabs(zb) < eps) {
    swap(xa, xb);
    swap(ya, yb);
    swap(za, zb);
  }
  la = 0;
  ra = 2 * pi;
  for (it1 = 0; it1 < 1000; it1++) {
    mxa = (29. * la + ra) / 30.;
    mya = (la + 29. * ra) / 30.;
    lv = solve(xa, ya, za, r * cos(mxa), r * sin(mxa), 0) +
         solve(xb, yb, zb, r * cos(mxa), r * sin(mxa), 0);
    rv = solve(xa, ya, za, r * cos(mya), r * sin(mya), 0) +
         solve(xb, yb, zb, r * cos(mya), r * sin(mya), 0);
    ans = min(ans, lv);
    ans = min(ans, rv);
    if (lv > rv)
      la = mxa;
    else
      ra = mya;
  }
  la = 0;
  ra = 2 * pi;
  for (it1 = 0; it1 < 600; it1++) {
    mxa = (49. * la + ra) / 50.;
    mya = (la + 49. * ra) / 50.;
    lb = 0;
    rb = 2 * pi;
    for (it2 = 0; it2 < 600; it2++) {
      mxb = (49.0 * lb + rb) / 50.;
      myb = (lb + 49.0 * rb) / 50.;
      lv = solve(xa, ya, za, r * cos(mxa), r * sin(mxa), 0) +
           solve(xb, yb, zb, r * cos(mxb), r * sin(mxb), 0) +
           dist(r * cos(mxa), r * sin(mxa), 0, r * cos(mxb), r * sin(mxb), 0);
      rv = solve(xa, ya, za, r * cos(mxa), r * sin(mxa), 0) +
           solve(xb, yb, zb, r * cos(myb), r * sin(myb), 0) +
           dist(r * cos(mxa), r * sin(mxa), 0, r * cos(myb), r * sin(myb), 0);
      if (lv > rv)
        lb = mxb;
      else
        rb = myb;
    }
    mxb = 0.5 * (lb + rb);
    lz = solve(xa, ya, za, r * cos(mxa), r * sin(mxa), 0) +
         solve(xb, yb, zb, r * cos(mxb), r * sin(mxb), 0) +
         dist(r * cos(mxa), r * sin(mxa), 0, r * cos(mxb), r * sin(mxb), 0);
    lb = 0;
    rb = 2 * pi;
    for (it2 = 0; it2 < 600; it2++) {
      mxb = (49. * lb + rb) / 50.;
      myb = (lb + 49. * rb) / 50.;
      lv = solve(xa, ya, za, r * cos(mya), r * sin(mya), 0) +
           solve(xb, yb, zb, r * cos(mxb), r * sin(mxb), 0) +
           dist(r * cos(mya), r * sin(mya), 0, r * cos(mxb), r * sin(mxb), 0);
      rv = solve(xa, ya, za, r * cos(mya), r * sin(mya), 0) +
           solve(xb, yb, zb, r * cos(myb), r * sin(myb), 0) +
           dist(r * cos(mya), r * sin(mya), 0, r * cos(myb), r * sin(myb), 0);
      ans = min(ans, lv);
      ans = min(ans, rv);
      if (lv > rv)
        lb = mxb;
      else
        rb = myb;
    }
    mxb = 0.5 * (lb + rb);
    rz = solve(xa, ya, za, r * cos(mya), r * sin(mya), 0) +
         solve(xb, yb, zb, r * cos(mxb), r * sin(mxb), 0) +
         dist(r * cos(mya), r * sin(mya), 0, r * cos(mxb), r * sin(mxb), 0);
    if (lz > rz)
      la = mxa;
    else
      ra = mya;
  }
  printf("%.20f\n", ans);
  return 0;
}
