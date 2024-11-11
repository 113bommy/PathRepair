#include <bits/stdc++.h>
const long long MXN = 1e5 + 12;
const double eps = 1e-10;
const double pi = acos(-1.0);
const long long OO = 1e18 + 1;
const int MNN = 1e5 + 1;
const int MOD = 1e9 + 7;
using namespace std;
double a, b, c, x1, fkjalskdf, x2, y2, dist = OO;
vector<pair<double, double> > s, e;
double get_dist(double x1, double fkjalskdf, double x2, double y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (fkjalskdf - y2) * (fkjalskdf - y2));
}
int main() {
  ios_base::sync_with_stdio(0), cout.tie(0), cin.tie(0);
  ;
  cin >> a >> b >> c;
  cin >> x1 >> fkjalskdf >> x2 >> y2;
  if (b != 0) {
    s.push_back(make_pair(x1, -(a * x1 + c) / b));
    e.push_back(make_pair(x2, -(a * x2 + c) / b));
  }
  if (a != 0) {
    s.push_back(make_pair(-(fkjalskdf * b + c) / a, fkjalskdf));
    e.push_back(make_pair(-(y2 * b + c) / a, y2));
  }
  for (int i = 0; i < s.size(); i++) {
    for (int j = 0; j < e.size(); j++) {
      dist =
          min(get_dist(x1, fkjalskdf, s[i].first, s[i].second) +
                  get_dist(s[i].first, s[i].second, e[j].first, e[j].second) +
                  get_dist(e[j].first, e[j].second, x2, y2),
              dist);
    }
  }
  cout << fixed << setprecision(6)
       << min(dist, abs(x1 - x2) + abs(fkjalskdf - y2));
  return 0;
}
