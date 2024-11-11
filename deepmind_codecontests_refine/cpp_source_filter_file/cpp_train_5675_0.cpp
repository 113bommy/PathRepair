#include <bits/stdc++.h>
const double EPS = 1e-10;
using namespace std;
inline int rit() {
  int f = 0, key = 1;
  char c;
  do {
    c = getchar();
    if (c == '-') key = -1;
  } while (c < '0' || c > '9');
  do {
    f = f * 10 + c - '0';
    c = getchar();
  } while (c >= '0' && c <= '9');
  return f * key;
}
double dis(double x, double y, double x2, double y2) {
  return sqrt((x - x2) * (x - x2) + (y - y2) * (y - y2));
}
double x, x2, y, y2, mv, t, vx, vy, wx, wy;
int chk(double now) {
  double dx, dy, nowx, nowy;
  if (now > t) {
    dx = vx * t + wx * (now - t);
    dy = vy * t + wy * (now - t);
  } else {
    dx = vx * now;
    dy = vy * now;
  }
  nowx = dx + x;
  nowy = dy + y;
  if (mv * now < dis(nowx, nowy, x2, y2)) return 0;
  return 1;
}
void read() {
  double p, q, mid;
  cin >> x >> y >> x2 >> y2;
  cin >> mv >> t >> vx >> vy >> wx >> wy;
  p = 0, q = 10000000;
  while (q - p > 0.000000001) {
    mid = (p + q) / 2;
    if (chk(mid))
      q = mid;
    else
      p = mid;
  }
  printf("%lf\n", mid);
}
int main() {
  read();
  return 0;
}
