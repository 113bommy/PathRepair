#include <bits/stdc++.h>
using namespace std;
int n, R, a[55], b[55], p[55];
double ans, f[55][5505];
inline int read() {
  int ret = 0, ff = 1;
  char ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') ff = -ff;
    ch = getchar();
  }
  while (isdigit(ch)) {
    ret = (ret << 3) + (ret << 1) + ch - '0';
    ch = getchar();
  }
  return ret * ff;
}
void write(int x) {
  if (x > 9) write(x / 10);
  putchar(x % 10 + 48);
}
bool check(double mid) {
  for (int i = n; i >= 1; i--) {
    for (int j = 0; j <= R; j++) {
      double x =
          ((j + a[i] > R ? mid : f[i + 1][j + a[i]]) + a[i]) * p[i] / 100.;
      double y = ((j + b[i] > R ? mid : f[i + 1][j + b[i]]) + b[i]) *
                 (100 - p[i]) / 100.;
      f[i][j] = min(mid, x + y);
    }
  }
  return f[1][0] < mid;
}
signed main() {
  n = read(), R = read();
  for (int i = 1; i <= n; i++) a[i] = read(), b[i] = read(), p[i] = read();
  double l = 0, r = 1e10;
  int T = 100;
  while (T--) {
    double mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }
  printf("%.10lf", l);
  return 0;
}
