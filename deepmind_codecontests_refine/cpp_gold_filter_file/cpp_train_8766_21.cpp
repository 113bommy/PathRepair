#include <bits/stdc++.h>
using namespace std;
const long long INF = (long long)9e16;
long long dist(pair<long long, long long> a, pair<long long, long long> b) {
  return abs(a.first - b.first) + abs(a.second - b.second);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long x0, y0, ax, ay, bx, by;
  cin >> x0 >> y0 >> ax >> ay >> bx >> by;
  long long xs, ys, t;
  cin >> xs >> ys >> t;
  vector<pair<long long, long long> > a = {{x0, y0}};
  while (ax * a.back().first + bx < INF && ay * a.back().second + by < INF) {
    a.emplace_back(ax * a.back().first + bx, ay * a.back().second + by);
  }
  long long n = a.size();
  long long ans = 0;
  pair<long long, long long> q = {xs, ys};
  for (long long i = 0; i < n; ++i) {
    for (long long j = i; j < n; ++j) {
      long long now = 0;
      now += min(dist(q, a[i]), dist(q, a[j]));
      now += dist(a[i], a[j]);
      if (now <= t) {
        ans = max(ans, j - i + 1);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
