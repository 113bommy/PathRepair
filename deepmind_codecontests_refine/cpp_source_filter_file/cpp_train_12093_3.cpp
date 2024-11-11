#include <bits/stdc++.h>
using namespace std;
int n, sm, x[51], y[51];
int64_t ans;
long double m, c;
set<pair<long double, long double>> s;
map<long double, int> mp;
void help(long double x1, long double y1, long double x2, long double y2) {
  if (x1 == x2) {
    if (!s.count({1e9, x1})) ++mp[1e9];
    s.insert({1e9, x1});
  } else {
    if (!s.count({(y2 - y1) / (x2 - x1), (x2 * y1 - x1 * y2) / (x1 - x2)}))
      ++mp[(y2 - y1) / (x2 - x1)];
    s.insert({(y2 - y1) / (x2 - x1), (x2 * y1 - x1 * y2) / (x1 - x2)});
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i];
    for (int j = i - 1; j; --j) help(x[i], y[i], x[j], y[j]);
  }
  sm = s.size();
  for (auto it : s) ans += sm - mp[it.first];
  cout << ans / 2;
}
