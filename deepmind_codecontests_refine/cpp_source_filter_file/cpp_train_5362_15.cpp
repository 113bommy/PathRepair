#include <bits/stdc++.h>
using namespace std;
template <class T>
inline bool RD(T &ret) {
  char c;
  int sgn;
  if (c = getchar(), c == EOF) return 0;
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  sgn = (c == '-') ? -1 : 1, ret = (c == '-') ? 0 : (c - '0');
  while (c = getchar(), c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
  ret *= sgn;
  return 1;
}
template <class T>
inline void PT(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) PT(x / 10);
  putchar(x % 10 + '0');
}
long long allx, ally;
long long sx, sy, gx, gy;
long long vx, vy, wx, wy;
long long mv, t;
bool ok(long double x) {
  long double dx = 0, dy = 0;
  if (x <= t) {
    dx = allx - vx * x;
    dy = ally - vy * x / mv;
  } else {
    dx = allx - vx * t - wx * (x - t);
    dy = ally - vy * t - wy * (x - t);
  }
  return dx * dx + dy * dy <= mv * x * mv * x;
}
int main() {
  cin >> sx >> sy >> gx >> gy;
  allx = gx - sx, ally = gy - sy;
  cin >> mv >> t;
  cin >> vx >> vy >> wx >> wy;
  long double lb = 0, ub = 1e10;
  for (int c = 0; c < int(1000); c++) {
    long double mid = (lb + ub) / 2.0;
    if (ok(mid))
      ub = mid;
    else
      lb = mid;
  }
  double ans = ub;
  printf("%.10f\n", ans);
}
