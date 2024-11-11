#include <bits/stdc++.h>
using namespace std;
double dist(int x1, int y1, int z1, int x2, int y2, int z2) {
  x1 -= x2;
  y1 -= y2;
  z1 -= z2;
  return sqrt(x1 * x1 + y1 * y1 + z1 * z1);
}
int n;
int x[5001], y[5001], z[5001];
int main(void) {
  scanf("%d", &n);
  double MinDist = 100000;
  for (int i = 0; i < n; i++) scanf("%d%d%d", &x[i], &y[i], &z[i]);
  for (int i = 1; i < n - 1; i++)
    for (int j = i + 1; j < n; j++) {
      double di = dist(x[i], y[i], z[i], x[0], y[0], z[0]);
      double dj = dist(x[j], y[j], z[j], x[0], y[0], z[0]);
      double dij = dist(x[j], y[j], z[j], x[i], y[i], z[i]);
      double diff = fabs(di - dj);
      MinDist = min(MinDist, fabs(max(di, dj) + (dij - diff) / 2));
    }
  printf("%.7lf", MinDist);
  return 0;
}
