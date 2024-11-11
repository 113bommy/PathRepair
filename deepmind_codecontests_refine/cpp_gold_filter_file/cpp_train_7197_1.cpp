#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, x, y, ans(0), c(0);
  cin >> n;
  vector<pair<long long, long long> > v;
  map<pair<long long, long long>, long long> mp;
  for (long long i = 0; i < n; i++) {
    cin >> x >> y;
    mp[{x, y}] = mp[{x, y}] + 1;
    if (mp[{x, y}] == 1) v.push_back({x, y});
    if (x == y and mp[{x, y}] == 1) c++;
  }
  if (v[0].first != 0 or v[0].second != 0) {
    v.push_back({0, 0});
    sort(v.begin(), v.end());
    c++;
  }
  for (long long i = 0; i + 1 < v.size(); i++) {
    long long x1(v[i].first), x2(v[i + 1].first), y1(v[i].second),
        y2(v[i + 1].second);
    if (x2 < y1 or y2 < x1) {
    } else if (y1 <= x1 and x2 <= y2) {
      ans += (x2 - x1 + 1);
    } else if (x1 <= y1 and y2 <= x2) {
      ans += (y2 - y1 + 1);
    } else if ((y1 < x1 and y2 <= x2) or (y1 <= x1 and y2 < x2)) {
      ans += (y2 - x1 + 1);
    } else if (x1 < y1 and x2 <= y2 or (x1 <= y1 and x2 < y2)) {
      ans += (x2 - y1 + 1);
    }
    if (v[i].first == v[i].second) ans--;
    if (v[i + 1].first == v[i + 1].second) ans--;
  }
  ans += c;
  cout << ans;
  return 0;
}
