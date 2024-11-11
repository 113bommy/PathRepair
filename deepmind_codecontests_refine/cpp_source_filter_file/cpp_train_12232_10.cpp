#include <bits/stdc++.h>
#pragma warning(disable : 4996)
using namespace std;
int n, m;
long long x, y;
pair<long long, long long> a[200000], b[200000];
vector<pair<long long, long long> > c, d;
long long ccw(pair<long long, long long> x, pair<long long, long long> y,
              pair<long long, long long> z) {
  return (y.first - x.first) * (z.second - x.second) -
         (y.second - x.second) * (z.first - x.first);
}
bool cmp(pair<long long, long long> p, pair<long long, long long> q) {
  return ccw(pair<long long, long long>(0, 0), p, q) != 0
             ? ccw(pair<long long, long long>(0, 0), p, q) > 0
             : p.first < q.first;
}
vector<pair<long long, long long> > getcon(int n,
                                           pair<long long, long long> a[]) {
  vector<pair<long long, long long> > q;
  int i, j, k;
  q.push_back(pair<long long, long long>(0, 0));
  sort(a + 1, a + n, cmp);
  q.push_back(pair<long long, long long>(0, 0));
  for (i = 1; i < n; i++) {
    while (q.size() >= 2 && ccw(q[q.size() - 2], q[q.size() - 1], a[i]) <= 0)
      q.pop_back();
    q.push_back(a[i]);
  }
  return q;
}
int main() {
  int i, j, k;
  ios::sync_with_stdio(false);
  cin >> n >> m >> x >> y;
  for (i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
  for (i = 0; i < m; i++) cin >> b[i].first >> b[i].second;
  long long xmax = 0, ymax = 0;
  for (i = 0; i < n; i++)
    xmax = max(xmax, a[i].first), ymax = max(ymax, a[i].second);
  a[n] = pair<long long, long long>(xmax, 0),
  a[n + 1] = pair<long long, long long>(0, ymax),
  a[n + 2] = pair<long long, long long>(0, 0);
  xmax = 0, ymax = 0;
  for (i = 0; i < m; i++)
    xmax = max(xmax, b[i].first), ymax = max(ymax, b[i].second);
  b[m] = pair<long long, long long>(xmax, 0),
  b[m + 1] = pair<long long, long long>(0, ymax),
  b[m + 2] = pair<long long, long long>(0, 0);
  n += 3, m += 3;
  sort(a, a + n), sort(b, b + m);
  n = unique(a, a + n) - a, m = unique(b, b + m) - b;
  c = getcon(n, a), d = getcon(m, b);
  int dab = 0;
  for (i = 1; i < n; i++) {
    auto it = lower_bound(d.begin(), d.end(), c[i], cmp);
    i = i;
    if (it->second * c[i].first == it->first * c[i].second) {
      if (max(c[i].first, c[i].second) >= max(it->first, it->second)) dab = 1;
    } else {
      auto it2 = it--;
      if (ccw(*it2, *it, c[i]) >= 0) dab = 1;
    }
  }
  printf(dab == 1 ? "Max" : "Min");
  return 0;
}
