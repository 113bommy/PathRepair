#include <bits/stdc++.h>
using namespace std;
vector<pair<pair<int, int>, char> > vpp;
vector<pair<int, int> > vp;
const int INF = 1e9;
long double caldis(long double x1, long double y1, long double x2,
                   long double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}
long double solve_cos(long double a, long double b, long double c) {
  return acos((a * a + b * b - c * c) / (2 * a * b));
}
long double intersect(long double ang, long double r) {
  long double s1, s2;
  s1 = ang * r * r / 2;
  s2 = sin(ang) * r * r / 2;
  return s1 - s2;
}
int main() {
  long double x1, x2, r1, r2, y1, y2;
  cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
  if (r1 < r2) {
    swap(x1, x2);
    swap(y1, y2);
    swap(r1, r2);
  }
  long double dis = caldis(x1, y1, x2, y2);
  if (dis + r2 <= r1 + 1e-16) {
    cout << setprecision(15);
    cout << (r2 * r2) * acos(-1.0) << endl;
  } else if (dis >= r1 + r2 - 1e-16) {
    cout << 0 << endl;
  } else {
    long double ang1 = solve_cos(dis, r1, r2);
    long double ang2 = solve_cos(dis, r2, r1);
    long double part1 = intersect(ang1 * 2.0, r1);
    part1 += (intersect(ang2 * 2.0, r2));
    cout << setprecision(15);
    cout << part1 << endl;
  }
  return 0;
}
