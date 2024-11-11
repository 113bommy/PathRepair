#include <bits/stdc++.h>
using namespace std;
const double one = 1.0, EPS = 1e-11;
void answer(double d) {
  cout << setprecision(10) << fixed << d << endl;
  exit(0);
}
double dist(pair<double, double> a, pair<double, double> b) {
  return hypot(a.first - b.first, a.second - b.second);
}
long long a, b, c;
pair<double, double> getX(long long x) {
  pair<double, double> res;
  res.first = x, res.second = (-one * (c + a * x)) / b;
  return res;
}
pair<double, double> getY(long long y) {
  pair<double, double> res;
  res.first = (-one * (c + b * y)) / a, res.second = y;
  return res;
}
bool equal(double p, double q) {
  if (-EPS < p - q && p - q < EPS) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> a >> b >> c;
  pair<long long, long long> s, t;
  cin >> s.first >> s.second >> t.first >> t.second;
  double val = abs(s.first - t.first) + abs(s.second - t.second);
  if (a == 0 || b == 0 || t.first == s.first || t.second == s.second) {
    answer(val);
  }
  pair<double, double> mid[4];
  mid[0] = getX(s.first);
  mid[1] = getX(t.first);
  mid[2] = getY(s.second);
  mid[3] = getY(t.second);
  for (int i = 0; i < 4; i++) {
    if (!equal(s.first, mid[i].first) && !equal(s.second, mid[i].second))
      continue;
    for (int j = 0; j < i; j++) {
      if (!equal(t.first, mid[j].first) && !equal(t.second, mid[j].second))
        continue;
      val = min(val, dist(s, mid[i]) + dist(mid[i], mid[j]) + dist(mid[j], t));
    }
  }
  answer(val);
  return 0;
}
