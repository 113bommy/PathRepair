#include <bits/stdc++.h>
using namespace std;
const long long N = 2e+5;
long long mon[N + 5];
long long emx[N + 5];
int32_t main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    for (long long i = 0; i <= n; i++) emx[i] = 0;
    long long lx = 0, rx = 0;
    for (long long i = 1; i <= n; i++) {
      cin >> mon[i];
      lx = max(lx, mon[i]);
    }
    long long m;
    cin >> m;
    for (long long i = 1; i <= m; i++) {
      long long p, e;
      cin >> p >> e;
      rx = max(rx, p);
      emx[e] = max(emx[e], p);
    }
    if (lx > rx) {
      cout << -1 << "\n";
      continue;
    }
    for (long long i = n; i >= 1; i--) {
      emx[i] = max(emx[i], emx[i + 1]);
    }
    long long ans = 1, p = 0, c = 0;
    for (long long i = 1; i <= n; i++) {
      p = max(p, mon[i]);
      c++;
      if (emx[c] >= p) {
        continue;
      } else {
        ++ans;
        p = mon[i];
        c = 1;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
