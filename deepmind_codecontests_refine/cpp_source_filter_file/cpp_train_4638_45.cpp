#include <bits/stdc++.h>
using namespace std;
int n;
struct Point {
  double x, y, z;
} p[10005], h, ans;
double vs, vp;
double have;
double anst;
double dis(Point a, Point b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) +
              (a.z - b.z) * (a.z - b.z));
}
Point getmid(Point a, Point b) {
  Point mid;
  mid.x = (a.x + b.x) / 2.0;
  mid.y = (a.y + b.y) / 2.0;
  mid.z = (a.z + b.z) / 2.0;
  return mid;
}
void equ(Point &a, Point b) {
  a.x = b.x;
  a.y = b.y;
  a.z = b.z;
}
bool solve(Point a, Point b) {
  Point l, m, r;
  equ(l, a);
  equ(r, b);
  double t1, t2;
  while (dis(l, r) > 1e-8) {
    m = getmid(l, r);
    t1 = (have + dis(m, a)) / vs;
    t2 = dis(h, m) / vp;
    if (abs(t1 - t2) < 1e-8) {
      anst = t1;
      equ(ans, m);
      return true;
    } else if (t1 > t2)
      equ(r, m);
    else if (t1 < t2)
      equ(l, m);
  }
  return false;
}
int main() {
  int i;
  while (scanf("%d", &n) != EOF) {
    for (i = 0; i <= n; i++) scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
    scanf("%lf%lf", &vp, &vs);
    scanf("%lf%lf%lf", &h.x, &h.y, &h.z);
    have = 0.0;
    bool flag = false;
    for (i = 0; i < n; i++) {
      if (solve(p[i], p[i + 1])) {
        printf("YES\n");
        printf("%.10lf\n", anst);
        printf("%.10lf %.10lf %.10lf\n", ans.x, ans.y, ans.z);
        flag = true;
        break;
      }
      have += dis(p[i], p[i + 1]);
    }
    if (!flag) printf("NO\n");
  }
  return 0;
}
