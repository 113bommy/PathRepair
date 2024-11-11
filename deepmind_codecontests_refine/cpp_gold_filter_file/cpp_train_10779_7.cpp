#include <bits/stdc++.h>
using namespace std;
const int nax = 1005;
struct P {
  int x, y;
  void read() { scanf("%d%d", &x, &y); }
  P operator-(P other) { return P{x - other.x, y - other.y}; }
  long long operator*(P other) {
    return (long long)x * other.y - (long long)y * other.x;
  }
  double norm() { return sqrt(double(x) * x + double(y) * y); }
};
int n;
P t[nax];
P roz[nax];
double inv_di[nax];
bool ta[nax][nax];
double interval(int from, int to, double x, double y) {
  double r = -1;
  for (int i = (from); i <= (to); ++i) {
    double tmp = roz[i].x * (y - t[i].y) - roz[i].y * (x - t[i].x);
    r = max(r, abs(tmp * inv_di[i]));
  }
  return r;
}
double best_x[nax][nax], best_y[nax][nax], val[nax][nax];
int main() {
  scanf("%d", &n);
  for (int i = (0); i <= ((n)-1); ++i) t[i].read();
  if (n == 3) {
    puts("0");
    for (int i = (0); i <= ((2) - 1); ++i) printf("%d %d\n", t[i].x, t[i].y);
    return 0;
  }
  for (int i = (0); i <= ((2 * n) - 1); ++i) t[n + i] = t[i];
  for (int i = (0); i <= ((3 * n) - 1); ++i) roz[i] = t[i + 1] - t[i];
  for (int i = (0); i <= ((3 * n) - 1); ++i)
    inv_di[i] = double(1) / roz[i].norm();
  for (int start = (0); start <= ((n)-1); ++start)
    for (int end = (start + 1); end <= (10000); ++end) {
      if (roz[start] * roz[end] <= 0) {
        break;
      }
      assert(end <= start + n);
      int tu = start;
      while (tu < end && interval(start, end, t[tu].x, t[tu].y) >
                             interval(start, end, t[tu + 1].x, t[tu + 1].y))
        ++tu;
      for (int rep = (0); rep <= ((2) - 1); ++rep) {
        if (rep) tu = max(0, tu - 1);
        double low = 0, high = 1;
        double dx = t[tu + 1].x - t[tu].x;
        double dy = t[tu + 1].y - t[tu].y;
        for (int _ = (0); _ <= ((42) - 1); ++_) {
          double one = (6 * low + 5 * high) / 11;
          double two = (5 * low + 6 * high) / 11;
          if (one < 1e-11) break;
          if (interval(start, end, t[tu].x + one * dx, t[tu].y + one * dy) >
              interval(start, end, t[tu].x + two * dx, t[tu].y + two * dy))
            low = one;
          else
            high = two;
        }
        double bb = (low + high) / 2;
        double tmp = interval(start, end, t[tu].x + bb * dx, t[tu].y + bb * dy);
        if (rep == 0 || tmp < val[start][end]) {
          best_x[start][end] = best_x[start + n][end + n] = t[tu].x + bb * dx;
          best_y[start][end] = best_y[start + n][end + n] = t[tu].y + bb * dy;
          val[start][end] = val[start + n][end + n] =
              interval(start, end, best_x[start][end], best_y[start][end]);
          ta[start][end] = ta[start + n][end + n] = true;
        }
      }
    }
  double v = 1e7;
  double a, b, c, d;
  for (int start = (0); start <= ((n)-1); ++start)
    for (int end = (start + 1); end <= (start + n); ++end)
      if (ta[start][end] && ta[end + 1][start + n - 1]) {
        double maybe = max(val[start][end], val[end + 1][start + n - 1]);
        if (maybe < v) {
          v = maybe;
          a = best_x[start][end];
          b = best_y[start][end];
          c = best_x[end + 1][start + n - 1];
          d = best_y[end + 1][start + n - 1];
        }
      }
  printf("%.10lf\n", v);
  printf("%.10lf %.10lf\n", a, b);
  printf("%.10lf %.10lf\n", c, d);
  return 0;
}
