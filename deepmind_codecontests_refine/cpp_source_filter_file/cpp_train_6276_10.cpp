#include <bits/stdc++.h>
using namespace std;
bool f(long long a, long long b) { return a > b; }
long long dist(long long x1, long long y1, long long x2, long long y2) {
  return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
void solve() {
  long long xa, xb, ya, yb;
  cin >> xa >> ya >> xb >> yb;
  long long minx = min(xa, xb), maxx = max(xa, xb), miny = min(ya, yb),
            maxy = max(ya, yb), i;
  std::vector<pair<long long, long long> > p;
  for (i = minx; i <= maxx; i++) {
    p.push_back(make_pair(i, miny));
  }
  for (i = minx; i <= maxx; i++) {
    p.push_back(make_pair(i, maxy));
  }
  for (i = miny + 1; i < maxy; i++) {
    p.push_back(make_pair(minx, i));
  }
  for (i = miny + 1; i < maxy; i++) {
    p.push_back(make_pair(maxx, i));
  }
  long long num_radar, rx, ry, r, c = 0;
  cin >> num_radar;
  while (num_radar--) {
    cin >> rx >> ry >> r;
    for (i = 0; i < p.size(); i++) {
      if (dist(p[i].first, p[i].second, rx, ry) <= r) p[i].first = 10000;
    }
    if (num_radar == 1) {
      for (i = 0; i < p.size(); i++) {
        if (p[i].first != 10000) c++;
      }
    }
  }
  cout << c;
}
int32_t main() {
  long long t = 1;
  while (t--) {
    solve();
  }
}
