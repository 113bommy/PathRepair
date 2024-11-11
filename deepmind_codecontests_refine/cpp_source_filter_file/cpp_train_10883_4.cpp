#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double eps = 1e-9;
double dist(int x1, int y1, int x2, int y2) {
  return sqrt((x1 - x2) * 1.0 * (x1 - x2) + (y1 - y2) * 1.0 * (y1 - y2));
}
vector<pair<double, int> > p;
int main() {
  int x0, y0, v, t;
  cin >> x0 >> y0 >> v >> t;
  cout << fixed << setprecision(15);
  cerr << fixed << setprecision(15);
  double r0 = v * 1.0 * t;
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y, r;
    cin >> x >> y >> r;
    double d = dist(x0, y0, x, y);
    if (d < r + eps) {
      cout << 1.0 << endl;
      return 0;
    }
    if (r + r0 < d - eps) continue;
    double angC = atan2(y - y0, x - x0);
    if (angC < 0) angC += 2.0 * PI;
    double ang = 0.0;
    double tLen = sqrt(d * d - 1.0 * r * r);
    if (tLen < r0 + eps) {
      ang = asin(r / d);
    } else {
      ang = acos((d * d + r0 * r0 - r * 1.0 * r) / (2 * d * r0));
    }
    double angS = angC - ang;
    double angL = angC + ang;
    if (angS < 0) {
      p.push_back({angS + 2 * PI, 1});
      p.push_back({2 * PI, -1});
      p.push_back({0.0, 1});
      p.push_back({angL, -1});
    } else if (angL > 2 * PI) {
      p.push_back({angS, 1});
      p.push_back({2 * PI, -1});
      p.push_back({0.0, 1});
      p.push_back({angL - 2 * PI, -1});
    } else {
      p.push_back({angS, 1});
      p.push_back({angL, -1});
    }
  }
  sort(p.begin(), p.end());
  double ans = 0;
  int add = 0;
  double prev = 0;
  for (int i = 0; i < p.size(); i++) {
    if (add > 0) ans += p[i].first - prev;
    add += p[i].second;
    prev = p[i].first;
  }
  ans /= 2 * PI;
  cout << ans << endl;
  return 0;
}
