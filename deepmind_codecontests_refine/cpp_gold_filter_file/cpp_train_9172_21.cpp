#include <bits/stdc++.h>
using namespace std;
const int INF = 2147483647;
const long long LLINF = 9223372036854775807LL;
const int maxn = 110;
int xx[maxn], yy[maxn], zz[maxn];
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &xx[i], &yy[i], &zz[i]);
  }
  double step = 1;
  double cx = 0, cy = 0, cz = 0;
  for (int iter = 0; iter < 20000; ++iter) {
    int mid = 0;
    double mx = 0;
    for (int i = 0; i < n; ++i) {
      double curd =
          sqrt((xx[i] - cx) * (xx[i] - cx) + (yy[i] - cy) * (yy[i] - cy) +
               (zz[i] - cz) * (zz[i] - cz));
      if (curd > mx) {
        mx = curd;
        mid = i;
      }
    }
    double vx = xx[mid] - cx;
    double vy = yy[mid] - cy;
    double vz = zz[mid] - cz;
    vx *= step;
    vy *= step;
    vz *= step;
    cx += vx;
    cy += vy;
    cz += vz;
    step *= .995;
  }
  printf("%.10lf %.10lf %.10lf", cx, cy, cz);
  return 0;
}
