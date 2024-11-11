#include <bits/stdc++.h>
using namespace std;
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
int main() {
  long long t, n, m, x1, y1, x2, y2, r1, r2;
  long long ans, t1, t2;
  cin >> t;
  while (t--) {
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    t1 = n - max(x1, x2) + min(x1, x2);
    t2 = m - max(y1, y2) + min(y1, y2);
    ans = n * m;
    ans -= 2 * t1 * t2;
    r1 = m - t2 + 1;
    r2 = n - t1 + 1;
    if (r1 <= t2 && r2 <= t1) ans += (t2 - r1 + 1) * (t1 - r2 + 1);
    cout << ans << '\n';
  }
  return 0;
}
