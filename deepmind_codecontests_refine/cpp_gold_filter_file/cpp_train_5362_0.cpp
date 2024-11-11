#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const double INF = 1e8;
int x[2], y[2], tx[2], ty[2];
int t, v;
inline double P(double t) { return t * t; }
bool yes(double m) {
  if (m <= t)
    return v * m >=
           sqrt(P(x[0] + m * tx[0] - x[1]) + P(y[0] + m * ty[0] - y[1]));
  else
    return v * m >= sqrt(P(x[0] + t * tx[0] + (m - t) * tx[1] - x[1]) +
                         P(y[0] + t * ty[0] + (m - t) * ty[1] - y[1]));
}
double gao() {
  double l = 0, r = INF;
  while (r - l > eps) {
    double mid = (l + r) / 2;
    if (yes(mid))
      r = mid;
    else
      l = mid;
  }
  return r;
}
int main() {
  for (int i = 0; i < 2; ++i) scanf("%d %d", x + i, y + i);
  scanf("%d %d", &v, &t);
  for (int i = 0; i < 2; ++i) scanf("%d %d", tx + i, ty + i);
  printf("%.8lf\n", gao());
  return 0;
}
