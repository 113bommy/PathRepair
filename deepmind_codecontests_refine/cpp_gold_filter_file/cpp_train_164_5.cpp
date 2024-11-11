#include <bits/stdc++.h>
using namespace std;
double dis(double ax, double ay, double bx, double by) {
  return sqrt(pow(ax - bx, 2) + pow(ay - by, 2));
}
bool f(double a, double b, double c) {
  if (a == sqrt(pow(b, 2) + pow(c, 2)))
    return true;
  else
    return false;
}
int main() {
  cout << fixed << setprecision(15);
  double ax, ay, bx, by, cx, cy;
  cin >> ax >> ay >> bx >> by >> cx >> cy;
  double ab = dis(ax, ay, bx, by), bc = dis(bx, by, cx, cy),
         ac = dis(ax, ay, cx, cy);
  bool res = true;
  if (ab == bc) {
    if (ay - by == 0) {
      if (ay == by && ay == cy) res = false;
    } else if (ax - bx == 0) {
      if (ax == bx && ax == cx) res = false;
    } else {
      double m = (ay - by) / (ax - bx);
      if (cy == (m * cx + ay - m * ax)) res = false;
    }
  } else
    res = false;
  if (res)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
