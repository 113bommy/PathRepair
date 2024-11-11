#include <bits/stdc++.h>
using namespace std;
const int bound = 100;
const double eps = 1e-9, inf = 1e9 + 9, pi = acos(-1.0);
double ans, r, h, xa, ya, za, xb, yb, zb, la, ra, mxa, mya, lb, rb, mxb, myb,
    lv, rv, lz, rz;
double dtheta;
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
double compute(double alpha, double beta) {
  return solve(xa, ya, za, r * cos(alpha), r * sin(alpha), 0) +
         solve(xb, yb, zb, r * cos(beta), r * sin(beta), 0) +
         dist(r * cos(alpha), r * sin(alpha), 0, r * cos(beta), r * sin(beta),
              0);
}
double compute(double alpha) {
  double theta, vl, ch, ret = inf;
  for (theta = 0; theta < 2 * pi; theta += dtheta) {
    vl = compute(alpha, theta);
    if (ret > vl) {
      ret = vl;
      ch = theta;
    }
  }
  lb = max(0., ch - dtheta);
  rb = min(2 * pi, ch + dtheta);
  while (lb < rb) {
    mxb = 0.5 * (lb + rb);
    myb = mxb + eps;
    if (compute(alpha, mxb) > compute(alpha, myb))
      lb = mxb + eps;
    else
      rb = mxb - eps;
  }
  vl = compute(alpha, 0.5 * (lb + rb));
  if (ret > vl) ret = vl;
  return ret;
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
  double theta, vl, ch, mi = inf;
  dtheta = 2 * pi / bound;
  mi = inf;
  for (theta = 0; theta < 2 * pi; theta += dtheta) {
    vl = solve(xa, ya, za, r * cos(theta), r * sin(theta), 0) +
         solve(xb, yb, zb, r * cos(theta), r * sin(theta), 0);
    if (mi > vl) {
      mi = vl;
      ch = theta;
    }
    if (ans > vl) ans = vl;
  }
  la = max(0., ch - dtheta);
  ra = min(2 * pi, ch + dtheta);
  while (la < ra) {
    mxa = 0.5 * (la + ra);
    mya = mxa + eps;
    lv = solve(xa, ya, za, r * cos(mxa), r * sin(mxa), 0) +
         solve(xb, yb, zb, r * cos(mxa), r * sin(mxa), 0);
    rv = solve(xa, ya, za, r * cos(mya), r * sin(mya), 0) +
         solve(xb, yb, zb, r * cos(mya), r * sin(mya), 0);
    if (lv > rv)
      la = mxa + eps;
    else
      ra = mxa - eps;
  }
  vl =
      solve(xa, ya, za, r * cos(0.5 * (la + ra)), r * sin(0.5 * (la + ra)), 0) +
      solve(xb, yb, zb, r * cos(0.5 * (la + ra)), r * sin(0.5 * (la + ra)), 0);
  if (ans > vl) ans = vl;
  mi = inf;
  for (theta = 0; theta < 2 * pi; theta += dtheta) {
    vl = compute(theta);
    if (mi > vl) {
      mi = vl;
      ch = theta;
    }
    if (ans > vl) ans = vl;
  }
  la = max(0., ch - dtheta);
  ra = min(2 * pi, ch + dtheta);
  while (la < ra) {
    mxa = 0.5 * (la + ra);
    mya = mxa + eps;
    if (compute(mxa) > compute(mya))
      la = mxa + eps;
    else
      ra = mxa - eps;
  }
  vl = compute(0.5 * (la + ra));
  if (ans > vl) ans = vl;
  printf("%.20f\n", ans);
  return 0;
}
