#include <bits/stdc++.h>
using namespace std;
struct Vex {
  int x, y;
  Vex() {}
  Vex(int _x, int _y) : x(_x), y(_y) {}
  void scan() { scanf("%d%d", &x, &y); }
  friend double dis(const Vex &A, const Vex &B) {
    return sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
  }
  friend bool CrossPoint(const Vex &A, double radA, const Vex &B, double radB,
                         double &pointx) {
    double l = sqrt((A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y));
    if (l > radA + radB + 1e-8) return false;
    double cos0 = (B.x - A.x) / l,
           cos1 = (radA * radA + l * l - radB * radB) / 2 / radA / l;
    pointx = A.x + radA * cos0 * cos1;
    return true;
  }
} V[3];
int t1, t2;
double R[3], disAB, disAC, disBC, ans;
inline bool check(double d) {
  R[0] = d, R[1] = disAC + t2 - d, R[2] = disAB + t1 - d;
  double l, r, mid;
  for (int i = 0; i < 3; ++i)
    if (!i)
      l = V[i].x - R[i], r = V[i].x + R[i];
    else {
      l = max(l, (double)V[i].x - R[i]);
      r = min(r, (double)V[i].x + R[i]);
    }
  if (l > r) return false;
  for (int times = 0; times < 30; ++times) {
    mid = (l + r) / 2;
    double up, low;
    int a, b;
    for (int i = 0; i < 3; ++i) {
      double delta = sqrt(R[i] * R[i] - (mid - V[i].x) * (mid - V[i].x));
      double u = V[i].y + delta, v = V[i].y - delta;
      if (!i || u < up) up = u, a = i;
      if (!i || v > low) low = v, b = i;
    }
    if (up + 1e-8 >= low) return true;
    double _x;
    if (!CrossPoint(V[a], R[a], V[b], R[b], _x)) return false;
    if (_x > mid)
      l = mid;
    else
      r = mid;
  }
  return false;
}
int main() {
  scanf("%d%d", &t1, &t2);
  for (int i = 0; i < 3; ++i) V[i].scan();
  disAB = dis(V[0], V[2]);
  disAC = dis(V[0], V[1]);
  disBC = dis(V[1], V[2]);
  ans = (disAB + disBC <= disAC + t2) ? min(disAB + disBC + t1, disAC + t2) : 0;
  double l = 0, r = disAC + t2, mid;
  for (int times = 0; times < 30; ++times) {
    mid = (l + r) / 2;
    if (check(mid))
      l = mid;
    else
      r = mid;
  }
  printf("%.6lf\n", max(ans, mid));
  return 0;
}
