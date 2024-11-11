#include <bits/stdc++.h>
using namespace std;
const double EPS = 0.000001;
int n, vs;
bool check_poss(int dist, int mid, double t, pair<int, int> x) {
  double t1 = (double)abs(x.first - mid) / (vs - x.second);
  if (t1 > t) return 0;
  double x1 = t1 * x.second;
  double t2 = (double)abs(dist - x1) / (vs + x.second);
  return t1 + t2 <= t;
}
int bin_left(int pt, double t, pair<int, int> x) {
  int dist = abs(pt - x.first);
  if (t * x.second >= dist) return 0;
  int lo = 0, hi = x.first + 1;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (check_poss(dist, mid, t, x)) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo < x.first + 1 ? lo : -1;
}
int bin_right(int pt, double t, pair<int, int> x) {
  int dist = abs(pt - x.first);
  if (t * x.second >= dist) return 1e6;
  int lo = x.first - 1, hi = 1e6;
  while (lo < hi) {
    int mid = (lo + hi + 1) / 2;
    if (check_poss(dist, mid, t, x)) {
      lo = mid;
    } else {
      hi = mid - 1;
    }
  }
  return lo > x.first - 1 ? lo : -1;
}
bool check(int x, double t, pair<int, int> p) {
  return (double)abs(x - p.first) / p.second <= t;
}
vector<pair<int, int> > p[2], toleft, toright;
int x, v, t;
int main() {
  scanf("%d%d", &n, &vs);
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &x, &v, &t);
    t--;
    p[t].emplace_back(x, v);
  }
  double lo = 0, hi = 1e6;
  while (hi - lo > EPS) {
    toleft.clear();
    toright.clear();
    double mid = (lo + hi) / 2;
    for (auto i : p[0]) {
      int l = check(0, mid, i) ? 0 : i.first, r = bin_right(0, mid, i);
      if (l == -1 || r == -1) continue;
      toleft.emplace_back(l, r);
    }
    for (auto i : p[1]) {
      int l = bin_left(1e6, mid, i), r = check(1e6, mid, i) ? 1e6 : i.first;
      if (l == -1 || r == -1) continue;
      toright.emplace_back(l, r);
    }
    sort(toleft.begin(), toleft.end());
    sort(toright.begin(), toright.end());
    int it = 0, sz = toright.size();
    bool ok = 0;
    for (auto i : toleft) {
      while (it < sz && toright[it].second < i.first) it++;
      if (it < sz && toright[it].first <= i.second) {
        ok = 1;
      }
    }
    if (ok) {
      hi = mid;
    } else {
      lo = mid;
    }
  }
  printf("%lf\n", lo);
  return 0;
}
