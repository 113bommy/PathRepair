#include <bits/stdc++.h>
using namespace std;
const int e = 1100;
const long long lim = 10000000000000000ll;
long long x0, yy00, ax, bx, ay, by, t, xs, ys;
int n = 61;
inline long long ab(long long t1) { return t1 < 0ll ? -t1 : t1; }
inline long long da(long long t1, long long t2) { return t1 < t2 ? t2 : t1; }
struct nod {
  long long x, y;
} w[e];
int cc(int p) {
  long long x = xs, y = ys;
  long long ti = 0;
  for (int i = p; i >= 0; i--) {
    ti += ab(w[i].x - x) + ab(w[i].y - y);
    cerr << i << ' ' << i << ' ' << ti << "\n";
    if (ti < 0ll) {
      return p - i;
    }
    if (ti > t) {
      return p - i;
    }
    x = w[i].x;
    y = w[i].y;
  }
  for (int i = p + 1; i <= n; i++) {
    ti += ab(w[i].x - x) + ab(w[i].y - y);
    if (ti < 0) {
      return i;
    }
    if (ti > t) {
      return i;
    }
    x = w[i].x;
    y = w[i].y;
  }
  return n;
}
int main() {
  cin >> x0 >> yy00 >> ax >> ay >> bx >> by >> xs >> ys >> t;
  w[0].x = x0;
  w[0].y = yy00;
  for (int i = 1; i <= 61; i++) {
    w[i].x = ax * w[i - 1].x + bx;
    w[i].y = ay * w[i - 1].y + by;
    if (w[i].y - ys > lim * 4 or w[i].x - xs > lim * 4) {
      n = i;
      break;
    }
  }
  if (n == 0) {
    w[1].x = ax * w[0].x + bx, w[1].y = ay * w[0].y + by;
    n = 1;
  }
  if (n == 1) {
    w[2].x = ax * w[1].x + bx, w[2].y = ay * w[1].y + by;
    n = 2;
  }
  while ((long double)w[n].x <
             (long double)((long double)ax * (long double)w[n - 1].x +
                           (long double)bx) or
         (long double) w[n].y <
             (long double)((long double)ay * (long double)w[n - 1].y +
                           (long double)by))
    n--;
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    ans = da(ans, cc(i));
  }
  cout << ans;
  return 0;
}
