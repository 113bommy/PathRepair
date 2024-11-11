#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, m, x, y, t, a, b, c, d, res = 0;
  cin >> n >> m >> x >> y >> t;
  while (t--) {
    cin >> a >> b;
    if (a == 0) {
      (b > 0) ? d = (m - y) / b : d = (y - 1) / -b;
      res += d;
      (b > 0) ? y += d* b : y -= d * b;
    } else if (b == 0) {
      (a > 0) ? c = (n - x) / a : c = (x - 1) / -a;
      res += c;
      (a > 0) ? x += c* a : x -= c * a;
    } else {
      (a > 0) ? c = (n - x) / a : c = (x - 1) / a;
      (b > 0) ? d = (m - y) / b : d = (y - 1) / b;
      res += min(c, d);
      (a > 0) ? x += min(c, d)* a : x -= min(c, d) * a;
      (b > 0) ? y += min(c, d)* b : y -= min(c, d) * b;
    }
  }
  cout << res;
  return 0;
}
