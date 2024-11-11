#include <bits/stdc++.h>
using namespace std;
class rec {
 public:
  long double x, y;
} p[2000];
int N, t, ans;
long double xk, xb, k, b, l, r, tt;
long double jiao(long double k1, long double b1, long double k2,
                 long double b2) {
  long double x = (b1 - b2) / (k2 - k1);
  return x;
}
int main() {
  scanf("%d", &N);
  for (int i = 1; i <= N; i++) {
    double x, y;
    scanf("%lf%lf", &x, &y);
    p[i].x = x;
    p[i].y = y;
  }
  if (p[1].x > p[2].x)
    for (int i = 1; i <= N; i++) {
      p[i].x = -p[i].x;
      if (abs(p[i].x) == 0) p[i].x = 0;
      p[i].y = -p[i].y;
      if (abs(p[i].y) == 0) p[i].y = 0;
    }
  xk = 0;
  xb = p[1].y;
  l = p[1].x;
  r = p[2].x;
  for (int i = 3; i <= N; i++) {
    t = i % N + 1;
    if (p[t].y >= p[i].y) {
      if (p[i].x == p[t].x) {
        tt = p[i].x;
      } else {
        k = (p[i].y - p[t].y) / (p[i].x - p[t].x);
        b = p[i].y - k * p[i].x;
        if (k == xk) {
          if (p[t].x < p[i].x)
            tt = -1e9;
          else
            tt = 1e9;
        } else
          tt = jiao(k, b, xk, xb);
      }
      l = max(l, tt);
    }
    t = i - 1;
    if (p[t].y >= p[i].y) {
      if (p[i].x == p[t].x) {
        tt = p[i].x;
      } else {
        k = (p[i].y - p[t].y) / (p[i].x - p[t].x);
        b = p[i].y - k * p[i].x;
        if (k == xk) {
          if (p[t].x > p[i].x)
            tt = 1e9;
          else
            tt = -1e9;
        } else
          tt = jiao(k, b, xk, xb);
      }
      r = min(r, tt);
    }
  }
  int ll = int(l - 1e-6);
  if (ll < l - 1e-6) ll++;
  int rr = int(r + 1e-6);
  if (rr > r + 1e-6) rr--;
  ans = max(0, rr - ll + 1);
  printf("%d", ans);
}
