#include <bits/stdc++.h>
using namespace std;
template <class TT>
TT abs(TT a) {
  if (a < 0) return -a;
  return a;
}
template <class ZZ>
ZZ max(ZZ a, ZZ b, ZZ c) {
  return max(a, max(b, c));
}
template <class ZZ>
ZZ min(ZZ a, ZZ b, ZZ c) {
  return min(a, min(b, c));
}
typedef struct {
  double x, y, z;
  void scan() { scanf("%lf%lf%lf", &x, &y, &z); }
} PP;
PP p[100], P;
int main() {
  int i, j, k, tks, ks = 1, n, m;
  double a, dis, md;
  while (cin >> n) {
    P.x = P.y = P.z = 0.0;
    for (i = 0; i < n; i++) {
      p[i].scan();
      P.x += p[i].x;
      P.y += p[i].y;
      P.z += p[i].z;
    }
    P.x /= n;
    P.y /= n;
    P.y /= n;
    a = 0.1;
    for (j = 0; j < 100000; j++) {
      k = 0;
      md = sqrt(((p[0].x - P.x) * (p[0].x - P.x)) +
                ((p[0].y - P.y) * (p[0].y - P.y)) +
                ((p[0].z - P.z) * (p[0].z - P.z)));
      for (i = 1; i < n; i++) {
        dis = sqrt(((p[i].x - P.x) * (p[i].x - P.x)) +
                   ((p[i].y - P.y) * (p[i].y - P.y)) +
                   ((p[i].z - P.z) * (p[i].z - P.z)));
        if (dis > md) {
          k = i;
          md = dis;
        }
      }
      P.x += (p[k].x - P.x) * a;
      P.y += (p[k].y - P.y) * a;
      P.z += (p[k].z - P.z) * a;
      a *= 0.999;
    }
    printf("%lf %lf %lf\n", P.x, P.y, P.z);
  }
  return 0;
}
