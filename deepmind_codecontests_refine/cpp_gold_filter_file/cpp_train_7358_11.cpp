#include <bits/stdc++.h>
using namespace std;
int testnum;
double a, b, l;
void preprocess() {}
double value(double x) {
  double y, z, det;
  y = sqrt(l * l - x * x);
  x = 1 / x;
  y = 1 / y;
  det = sqrt(x * x + y * y);
  det = (a * x + b * y - 1) / det;
  return det;
}
void solve() {
  double lo = 0;
  double hi = l;
  double x, y, vx, vy;
  for (int i = 0; i < 1000; i++) {
    x = (lo + lo + hi) / 3;
    y = (lo + hi + hi) / 3;
    vx = value(x);
    vy = value(y);
    if (vx < vy)
      hi = y;
    else
      lo = x;
  }
  vx = value(lo);
  if (l <= a) vx = max(vx, b);
  if (l <= b) vx = max(vx, a);
  if (l > a && l > b) {
    if (vx > a) vx = a;
    if (vx > b) vx = b;
  }
  if (vx > l) vx = l;
  if (vx <= 0)
    printf("My poor head =(\n");
  else
    printf("%.9lf\n", vx);
}
bool input() {
  int aa, bb, ll;
  scanf("%d", &aa);
  scanf("%d", &bb);
  scanf("%d", &ll);
  a = aa;
  b = bb;
  l = ll;
  return true;
}
int main() {
  preprocess();
  int T = 1;
  for (testnum = 1; testnum <= T; testnum++) {
    if (!input()) break;
    solve();
  }
}
