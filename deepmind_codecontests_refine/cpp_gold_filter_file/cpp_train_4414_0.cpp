#include <bits/stdc++.h>
using namespace std;
const int maxn = 5;
const double eps = 1e-6;
const int INF = 1e9;
int n;
double r[maxn];
double minans = INF;
struct point {
  double x, y;
  point() : x(0), y(0) {}
  point(double a, double b) : x(a), y(b) {}
  double dis(point &b) {
    return sqrt((x - b.x) * (x - b.x) + (y - b.y) * (y - b.y));
  }
  point operator+(point b) { return point(x + b.x, y + b.y); }
  point operator-(point b) { return point(x - b.x, y - b.y); }
  point operator*(double p) { return point(x * p, y * p); }
  point operator/(double p) { return point(x / p, y / p); }
} p[maxn], now;
double sqr(double x) { return x * x; }
double calc(point &a) {
  return (sqr(p[1].dis(a) / r[1] - p[2].dis(a) / r[2]) +
          sqr(p[1].dis(a) / r[1] - p[3].dis(a) / r[3]) +
          sqr(p[2].dis(a) / r[2] - p[3].dis(a) / r[3])) *
         1e8;
}
int check(double d, double T) {
  double a = 1.0 * rand();
  double b = exp(-d / T) * RAND_MAX;
  return (d < 0) || (a < b);
}
void solve(point &initp, double initT, double dec, double endT) {
  double temp = initT;
  now = initp;
  double nowans = calc(now);
  while (temp > endT) {
    point next(now.x + temp * (1.0 * rand() * 2 / RAND_MAX - 1),
               now.y + temp * (1.0 * rand() / RAND_MAX * 2 - 1));
    double ans = calc(next);
    if (check(ans - nowans, temp)) {
      nowans = ans;
      now = next;
    }
    temp *= dec;
  }
}
int main() {
  point init;
  for (int i = 1; i <= 3; i++) {
    scanf("%lf %lf %lf", &p[i].x, &p[i].y, &r[i]);
    init = init + p[i];
  }
  init = init / 3;
  for (int i = 1; i <= 4; i++) solve(init, 20, 0.99815, 1e-14);
  if (calc(now) < eps)
    printf("%.5lf %.5lf\n", now.x, (fabs(now.y) < 1e-5) ? fabs(now.y) : now.y);
  else
    printf("\n");
  return 0;
}
