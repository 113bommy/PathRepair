#include <bits/stdc++.h>
using namespace std;
using namespace std;
long long T, n, t;
void solve() {
  long long int mx = 0, ans = 0, flag = 0, a, i, j, k, x, y, a1, a2, b1, b2, xs,
                ys, t, dist, b;
  cin >> x >> y >> a1 >> a2 >> b1 >> b2;
  cin >> xs >> ys >> t;
  a = x;
  b = y;
  vector<pair<long long, long long>> v;
  while (1) {
    v.push_back(make_pair(a, b));
    a = a * a1 + b1;
    b = b * a2 + b2;
    if (a > 10000000000000000 || b > 10000000000000000) break;
  }
  for (i = 0; i < v.size(); i++) {
    dist = abs(xs - v[i].first) + abs(ys - v[i].second);
    for (j = 0; j < v.size(); j++) {
      ans =
          dist + abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
      if (ans <= t) mx = max(mx, abs(j - i) + 1);
    }
  }
  cout << mx;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  t = 1;
  while (t--) solve();
  return 0;
}
