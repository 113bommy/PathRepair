#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > p[2];
int S;
set<pair<int, int> > val;
const int HIGH = 1000000;
bool can(long double T) {
  int last_low = -1, last_hi = -1;
  val.clear();
  bool very_good = false;
  for (pair<int, int> pp : p[0]) {
    int x = pp.first;
    double v = pp.second;
    if (T * pp.second >= x) {
      very_good = true;
      break;
    }
    long double t = x / (S + v);
    if (t > T) continue;
    double dx2 = (T - t) / (1 - v / (S + v)) * (S - v);
    int x2 = min(HIGH, x + (int)(min(1e8, dx2)));
    if (last_hi >= x)
      last_hi = max(last_hi, x2);
    else {
      val.insert(pair<int, int>(last_low, last_hi));
      last_low = x, last_hi = x2;
    }
  }
  if (!very_good && last_low == -1) return false;
  val.insert(pair<int, int>(last_low, last_hi));
  for (pair<int, int> pp : p[1]) {
    int d = HIGH - pp.first;
    if (T * pp.second >= d) return true;
    long double v = pp.second;
    long double t = d / (S + v);
    if (t > T) continue;
    if (very_good) return true;
    double dx2 = d + (T - t) / (1 - v / (S + v)) * (S - v);
    int d2 = min(1e8, dx2);
    int x = max(0, HIGH - d2), x2 = HIGH - d;
    auto it = val.lower_bound(pair<int, int>(x2, HIGH + 1));
    --it;
    if (it->second >= x) return true;
  }
  return false;
}
int main() {
  int n;
  scanf("%d %d", &n, &S);
  for (int i = (0); i < (n); ++i) {
    int x, v, t;
    scanf("%d %d", &x, &v);
    scanf("%d", &t);
    p[t - 1].push_back(pair<int, int>(x, v));
  }
  sort(p[0].begin(), p[0].end());
  double t0 = 0, t1 = 1e5;
  for (int i = (0); i < (300); ++i) {
    double mid = (t0 + t1) / 2;
    if (can(mid))
      t1 = mid;
    else
      t0 = mid;
  }
  printf("%.8lf\n", t0);
}
