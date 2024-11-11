#include <bits/stdc++.h>
using namespace std;
bool home = 1;
signed realMain();
signed main() {
  home = 0;
  if (home) {
    freopen("input", "r", stdin);
  } else {
    ios::sync_with_stdio(0);
    cin.tie(0);
  }
  realMain();
}
long long k, a[7];
signed realMain() {
  long long t;
  cin >> t;
  while (t--) {
    long long total = 0;
    cin >> k;
    for (long long i = 0; i < 7; i++) {
      cin >> a[i];
      total += a[i];
    }
    long long ret = (long long)1e18;
    for (long long s = 0; s < 7; s++) {
      long long need = k, cost = 0;
      for (long long i = s; i < 7; i++) {
        if (need == 0) {
          break;
        }
        need -= a[i];
        cost++;
      }
      if (need >= total + 1) {
        long long k = (need - 1) / total + 1;
        need -= total * k;
        cost += 7 * k;
      }
      for (long long i = 0; i < 7; i++) {
        if (need == 0) {
          break;
        }
        need -= a[i];
        cost++;
      }
      ret = min(ret, cost);
    }
    cout << ret << "\n";
  }
  return 0;
}
