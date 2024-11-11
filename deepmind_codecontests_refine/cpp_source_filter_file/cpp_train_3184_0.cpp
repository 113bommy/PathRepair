#include <bits/stdc++.h>
using namespace std;
int main() {
  long long ts, tf, t, n, a, ans, m = 1 << 30;
  cin >> ts >> tf >> t >> n;
  while (n--) {
    cin >> a;
    if (a && a + t <= tf) {
      if (max(ts, a) + t <= tf && ts - a + 1 < m) {
        m = ts - a + 1, ans = min(ts, a - 1);
      }
      ts = max(ts, a) + t;
    }
  }
  if (ts + t <= tf) ans = ts;
  cout << ans << endl;
}
