#include <bits/stdc++.h>
using namespace std;
const int MOD1 = 1e9 + 7;
const int MOD2 = 998244353;
const long long INF = 2 * 1e18;
const long double PI = 3.14159265358979323846;
pair<long long, long long> p[300005];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long n, minx = INF, miny = INF, maxx = -INF, maxy = -INF, ans = 0;
  cin >> n;
  vector<pair<long long, pair<long long, long long> > > v;
  for (long long i = 0; i < n; i++) {
    cin >> p[i].first >> p[i].second;
    minx = min(minx, p[i].first);
    miny = min(miny, p[i].second);
    maxx = max(maxx, p[i].first);
    maxy = max(maxy, p[i].second);
  }
  for (long long i = 0; i < n; i++) {
    if (p[i].first == minx || p[i].first == maxx || p[i].second == miny ||
        p[i].second == maxy)
      v.push_back(make_pair(i, p[i]));
  }
  for (long long i = 0; i < v.size(); i++) {
    for (int j = i + 1; j < v.size(); j++) {
      for (long long k = 0; k < n; k++) {
        if (k == v[i].first || k == v[j].first) continue;
        long long x1 = v[i].second.first, x2 = v[j].second.first,
                  x3 = p[k].first, y1 = v[i].second.second,
                  y2 = v[j].second.second, y3 = p[k].second;
        ans = max(ans, abs(x1 - x2) + abs(x2 - x3) + abs(x3 - x1) +
                           abs(y1 - y2) + abs(y2 - y3) + abs(y3 - y1));
      }
    }
  }
  cout << ans << " ";
  for (long long i = 0; i < n - 3; i++)
    cout << 2 * (maxx - minx + maxy - miny) << " ";
}
