#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
const ll inf = 1000000001, INF = (ll)1e18 + 1;
ld sqrd(ld x) { return x * x; }
ld dist(pair<ld, ld> a, pair<ld, ld> b) {
  if (a.first == b.first) return abs(a.second - b.second);
  if (a.second == b.second) return abs(a.first - b.first);
  return sqrt(sqrd(a.first - b.first) + sqrd(a.second - b.second));
}
void solve() {
  cout << setprecision(6) << fixed;
  int a, b, c, x1, y1, x2, y2;
  cin >> a >> b >> c >> x1 >> y1 >> x2 >> y2;
  vector<pair<ld, ld>> pa(2), pb(2);
  pa[0] = {x1, (ld)((ld)-x1 * a - c) / (ld)b};
  pa[1] = {(ld)((ld)-y1 * b - c) / (ld)a, y1};
  pb[0] = {x2, (ld)((ld)-x2 * a - c) / (ld)b};
  pb[1] = {(ld)((ld)-y2 * b - c) / (ld)a, y2};
  ld ans = abs(x1 - x2) + abs(y1 - y2);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      ans = min(ans, dist({x1, y1}, pa[i]) + dist(pa[i], pb[j]) +
                         dist(pb[j], {x2, y2}));
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  solve();
  return 0;
}
