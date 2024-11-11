#include <bits/stdc++.h>
namespace Main {
namespace Source {
static inline const long double max(const long double a, const long double b) {
  return a < b ? b : a;
}
static inline const void amax(long double& a, const long double b) {
  a = max(a, b);
}
}  // namespace Source
using namespace Source;
enum { N = 2500 };
struct point {
  signed int x, y;
  point() : x(), y() {}
  point(const signed int x, const signed int y) : x(x), y(y) {}
  inline const void read() { scanf("%d%d", &x, &y); }
  static inline const long double dis(const point& a, const point& b) {
    return sqrtl(powl(a.x - b.x, 2) + powl(a.y - b.y, 2));
  }
};
static short unsigned int n;
static point p[N];
static long double f[N][N], g[N][N];
static long double ans;
static const long double (*dis)(const point&, const point&)(point::dis);
static inline const void main() {
  scanf("%hu", &n);
  for (short unsigned int i(0); i < n; ++i) p[i].read();
  for (short unsigned int i(0); i < n; ++i) g[0][i] = f[0][i] = 0;
  for (short unsigned int i(1); i < n; ++i)
    for (short unsigned int j(0); j < n; ++j)
      f[i][j] = max(f[i - 1][(j + 1) % n] + dis(p[j], p[(j + 1) % n]),
                    g[i - 1][(j + 1) % n] + dis(p[j], p[(j + i) % n])),
      g[i][j] = max(f[i - 1][j] + dis(p[(j + i) % n], p[j]),
                    g[i - 1][j] + dis(p[(j + i) % n], p[(j + i - 1) % n]));
  for (short unsigned int i(0); i < n; ++i)
    amax(ans, max(f[n - 1][i], g[n - 1][i]));
  printf("%.12Lf\n", ans);
}
}  // namespace Main
signed int main() {
  Main::main();
  return 0;
}
