#include <bits/stdc++.h>
using namespace std;
int n;
long long e, f, a, b;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  cin >> e >> f;
  cin >> a >> b;
  vector<pair<long long, long long> > d;
  for (int i = 0; i < n; i++) {
    long long x, y;
    cin >> x >> y;
    d.push_back({(x - e) * (x - e) + (y - f) * (y - f),
                 (x - a) * (x - a) + (y - b) * (y - b)});
  }
  sort(d.begin(), d.end());
  long long ans = 5e18;
  for (auto i : d) {
    long long dis1 = i.first;
    long long dis2 = 0;
    for (auto j : d) {
      if (j.first > dis1) {
        dis2 = max(dis2, j.second);
      }
    }
    ans = min(ans, dis1 + dis2);
  }
  for (auto i : d) {
    long long dis1 = i.second;
    long long dis2 = 0;
    for (auto j : d) {
      if (j.first > dis1) {
        dis2 = max(dis2, j.first);
      }
    }
    ans = min(ans, dis1 + dis2);
  }
  cout << ans;
  return 0;
}
