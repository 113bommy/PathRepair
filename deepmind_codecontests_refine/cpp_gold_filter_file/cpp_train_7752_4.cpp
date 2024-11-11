#include <bits/stdc++.h>
const int maxn = 1e2 + 5;
const double e = 2.7182818284590452353602874713527;
const double eps = 1e-6;
using namespace std;
int n, k;
double f[maxn][maxn], p, r, l, tp[maxn];
struct node {
  double x, y;
} po[maxn];
double dis(int a, int b) {
  return sqrt((po[a].x - po[b].x) * (po[a].x - po[b].x) +
              (po[a].y - po[b].y) * (po[a].y - po[b].y));
}
double epx(double D) { return pow(e, D); }
double calc(double d, double R) {
  if (d <= R)
    return 1.0;
  else
    return epx(1.0 - d * d / (R * R));
}
bool check(double mi) {
  memset(f, 0, sizeof(f));
  f[0][0] = 1.0;
  for (int i = 1; i <= n; i++) tp[i] = 1.0 - calc(dis(0, i), mi);
  for (int i = 1; i <= n; i++) {
    f[i][0] = f[i - 1][0] * tp[i];
    for (int j = 1; j <= i; j++)
      f[i][j] = f[i - 1][j] * tp[i] + f[i - 1][j - 1] * (1.0 - tp[i]);
  }
  double sum = 0.0;
  for (int i = 0; i < k; i++) sum += f[n][i];
  return sum <= p / 1000.0;
}
int main() {
  scanf("%d %d %lf %lf %lf", &n, &k, &p, &po[0].x, &po[0].y);
  for (int i = 1; i <= n; i++) scanf("%lf %lf", &po[i].x, &po[i].y);
  for (int i = 1; i <= n; i++) r = max(r, dis(0, i));
  while (l + eps < r) {
    double mid = (l + r) / 2.0;
    if (check(mid))
      r = mid;
    else
      l = mid + eps;
  }
  printf("%.12lf\n", l);
  return 0;
}
