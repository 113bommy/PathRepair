#include <bits/stdc++.h>
const int MAXN = 100000 + 10;
const double pi = acos(-1.0);
int N;
double px, py, x[MAXN], y[MAXN];
double dist(double x1, double y1, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
double get(double x1, double y1, double x2, double y2, double px, double py) {
  double dx = x2 - x1, dy = y2 - y1;
  double l = 0, r = 1;
  double ans = 100000000;
  for (int i = 1; i <= 40; ++i) {
    double mid1 = l + (r - l) / 3, mid2 = l + (r - l) / 3 * 2;
    double mx1 = x1 + dx * mid1, my1 = y1 + dy * mid1;
    double mx2 = x1 + dx * mid2, my2 = y1 + dy * mid2;
    if (dist(mx1, my1, px, py) < dist(mx2, my2, px, py)) {
      r = mid2;
    } else {
      l = mid1;
    }
  }
  return dist(x1 + dx * l, y1 + dy * l, px, py);
}
int main() {
  scanf("%d", &N);
  scanf("%lf%lf", &px, &py);
  for (int i = 0; i < N; ++i) {
    scanf("%lf%lf", &x[i], &y[i]);
  }
  double MAX = -1, MIN = 100000000;
  for (int i = 0; i < N; ++i) {
    MAX = std::max(MAX, dist(x[i], y[i], px, py));
    MIN = std::min(MIN, dist(x[i], y[i], px, py));
  }
  for (int i = 0; i < N; ++i) {
    int j = (i + 1) % N;
    MIN = std::min(MIN, get(x[i], y[i], x[j], y[j], px, py));
  }
  double ans = pi * (MAX * MAX - MIN * MIN);
  printf("%.8f\n", ans);
  return 0;
}
