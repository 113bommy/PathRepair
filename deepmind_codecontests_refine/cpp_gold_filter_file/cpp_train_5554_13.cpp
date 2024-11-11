#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-6;
const int INF = 0x3f3f3f3f;
struct Node {
  double x, y, v, r;
} p, Q, mubiao;
double mid, high, low;
double angle, R;
double dis(Node a, Node b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double slove(double t) {
  double angle_new = (angle + t * p.v / R);
  mubiao.x = R * cos(angle_new), mubiao.y = R * sin(angle_new);
  double len1 = sqrt(Q.x * Q.x + Q.y * Q.y - Q.r * Q.r);
  double len_2 =
      sqrt((mubiao.x * mubiao.x) + (mubiao.y * mubiao.y) - (Q.r * Q.r));
  double dd = dis(Q, mubiao);
  if (len1 + len_2 > dd) {
    return dd;
  } else {
    double dis1 = sqrt(Q.x * Q.x + Q.y * Q.y);
    double dis2 = sqrt(mubiao.x * mubiao.x + mubiao.y * mubiao.y);
    double angle_cricle =
        acos((dis1 * dis1 + dis2 * dis2 - dd * dd) / (2 * dis1 * dis2)) -
        atan(len1 / Q.r) - atan(len_2 / Q.r);
    return angle_cricle * Q.r + len1 + len_2;
  }
}
int main() {
  cin >> p.x >> p.y >> p.v;
  cin >> Q.x >> Q.y >> Q.v >> Q.r;
  angle = atan2(p.y, p.x);
  R = sqrt(p.x * p.x + p.y * p.y);
  high = 10000000;
  low = 0;
  while (high - low > 1e-12) {
    mid = (high + low) / 2;
    if (slove(mid) <= (1e-12 + mid * Q.v))
      high = mid;
    else
      low = mid;
  }
  printf("%.9f\n", mid);
  return 0;
}
