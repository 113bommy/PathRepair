#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const long long INF = 2e18;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  ;
  int tc;
  cin >> tc;
  while (tc--) {
    long long h, c, t;
    cin >> h >> c >> t;
    if (t >= h) {
      cout << "1\n";
    } else {
      long double gap = fabs(t - (h + c) / 2.0);
      int res = 2;
      int n = (int)round((long double)(1 - t) / (long double)(t - h - c));
      for (int i = max(0, n - 100); i <= n + 100; ++i) {
        int k = i + i + 1;
        long double temp = (long double)(h * (i + 1) + c * i) / k;
        long double tg = fabs(temp - t);
        if (tg < gap) res = k, gap = tg;
      }
      cout << res << "\n";
    }
  }
  return 0;
}
