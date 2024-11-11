#include <bits/stdc++.h>
using namespace std;
const int N = 3e5;
pair<long long, long long> a[N];
int main() {
  long long n, maxx = -1e8, maxy = -1e8, minx = 1e8, miny = 1e8, res3 = -1e9,
               res;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
    maxx = max(maxx, a[i].first);
    maxy = max(maxy, a[i].second);
    minx = min(minx, a[i].first);
    miny = min(miny, a[i].second);
  }
  res = 2 * (maxx - minx + maxy - miny);
  for (int i = 0; i < n; ++i) {
    res3 = max(res3, 2 * (maxx - a[i].first + maxy - a[i].second));
    res3 = max(res3, 2 * (maxx - a[i].first - miny + a[i].second));
    res3 = max(res3, 2 * (a[i].first - minx + maxy - a[i].second));
    res3 = max(res3, 2 * (a[i].first - minx - miny + a[i].second));
  }
  cout << res3;
  for (int i = 4; i <= n; ++i) cout << ' ' << res;
}
