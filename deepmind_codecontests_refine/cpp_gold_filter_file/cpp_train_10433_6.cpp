#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
const int MAX(int &a, int b) { return a = max(a, b); }
const int MIN(int &a, int b) { return a = min(a, b); }
long long xz, yz, ax, ay, bx, by;
long long sx, sy, mt;
int n;
long long man_dist(long long x1, long long y1, long long x2, long long y2) {
  return abs(x2 - x1) + abs(y2 - y1);
}
int main() {
  int t = 1;
  while (t--) {
    cin >> xz >> yz >> ax >> ay >> bx >> by;
    cin >> sx >> sy >> mt;
    vector<long long> x, y;
    long long top = 1e18 + 1;
    x.push_back(xz);
    y.push_back(yz);
    while ((top - bx) / ax >= x.back() && (top - by) / ay >= y.back()) {
      x.push_back(ax * x.back() + bx);
      y.push_back(ay * y.back() + by);
    }
    n = x.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) {
        long long common_dist = man_dist(x[i], y[i], x[j], y[j]);
        if (mt >= min(man_dist(sx, sy, x[i], y[i]) + common_dist,
                      man_dist(sx, sy, x[j], y[j]) + common_dist))
          MAX(ans, j - i + 1);
      }
    cout << ans << '\n';
  }
}
