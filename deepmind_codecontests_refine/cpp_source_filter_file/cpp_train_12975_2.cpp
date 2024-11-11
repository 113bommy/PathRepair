#include <bits/stdc++.h>
using namespace std;
const int N = 1551;
const double eps = 1e-10;
struct disx {
  double x, y;
} now[N];
int n, r;
double dist(disx a, disx b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double undist(double r, double x) { return sqrt(r * r - x * x); }
double fabs(double a) {
  if (a > 0.0)
    return a;
  else
    return -a;
}
double max(double a, double b) {
  if (a - b > eps)
    return a;
  else
    return b;
}
void solve() {
  scanf("%d%d", &n, &r);
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    now[i].x = double(x);
  }
  now[1].y = double(r);
  double disr = double(r) * 2.0;
  for (int i = 2; i <= n; i++) {
    now[i].y = 0.0;
    for (int j = 1; j < i; j++) {
      double xx = fabs(now[i].x - now[j].x);
      now[i].y = max(undist(disr, xx) + now[j].y, now[i].y);
    }
  }
  for (int i = 1; i <= n; i++) printf("%.10lf ", now[i].y);
}
int main() {
  int T;
  T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
