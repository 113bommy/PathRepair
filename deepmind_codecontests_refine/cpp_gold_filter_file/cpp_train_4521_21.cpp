#include <bits/stdc++.h>
using namespace std;
int get() {
  char c;
  int res = 0;
  while (c = getchar(), !isdigit(c))
    ;
  do {
    res = (res << 3) + (res << 1) + (c - '0');
  } while (c = getchar(), isdigit(c));
  return res;
}
struct point {
  double x, y;
  int made;
  inline point(double _x = 0.0, double _y = 0.0) {
    x = _x;
    y = _y;
  }
  inline point operator-(const point &b) const {
    return point(x - b.x, y - b.y);
  }
  inline point operator+(const point &b) const {
    return point(x + b.x, y + b.y);
  }
  inline point operator|(const double &b) const { return point(x * b, y * b); }
  inline double operator^(const point &b) const { return x * b.y - y * b.x; }
  inline double operator*(const point &b) const { return x * b.x + y * b.y; }
  inline void input() { scanf("%lf%lf", &x, &y); }
};
double A[700001], ans, tmp, tt;
int l, r, n, k, i, j, jj, N, cnt;
int main() {
  scanf("%d%d", &n, &k);
  N = 700000 / k;
  for (i = 1; i <= n; i++) {
    ans = 0;
    scanf("%d", &l);
    cnt = 0;
    for (j = 1; j <= k; j++) {
      scanf("%d", &r);
      tmp = 1.0 * (r - l) / N;
      for (jj = 0; jj <= N; jj++) {
        tt = 1.0 * l + tmp * jj;
        if (tt > A[cnt]) {
          ans += (tt - A[cnt]);
          A[cnt] = tt;
        }
        cnt++;
      }
      cnt--;
      l = r;
    }
    printf("%lf\n", ans / N);
  }
  return 0;
}
