#include <bits/stdc++.h>
using namespace std;
const double pi = 3.1415926535897;
long long m, n, t, mod = 1000000007, yy[1000005];
inline long long quick(long long e, long long f, long long o) {
  long long s = 1;
  while (e) {
    if (e % 2) {
      e--;
      s = s * f % o;
    } else {
      e >>= 1;
      f = f * f % o;
    }
  }
  return s;
}
signed main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  cin >> t;
  while (t--) {
    cin >> m >> n;
    for (long long i = 0; i < m; ++i) cin >> yy[i];
    if (n == 1) {
      cout << (m ^ 2) << endl;
      continue;
    }
    sort(yy, yy + m);
    long long ok = 0;
    for (long long i = m - 1; i >= 0; --i) {
      if (i > 0 && yy[i] == yy[i - 1])
        --i;
      else {
        long long p = 1, e = i, ans = 0;
        for (long long j = i - 1; j >= 0; --j) {
          long long d = yy[j + 1] - yy[j];
          while (d-- && p <= j && p > 0) p *= n;
          if (p > j) p = -1;
          if (p > 0) p--;
          i = j;
          if (p == 0) {
            ans = -1;
            break;
          } else
            ans = (ans + quick(yy[j], n, mod)) % mod;
        }
        if (i <= 0 && ans != -1) {
          cout << ((quick(yy[e], n, mod) - ans) % mod + mod) % mod << endl;
          ok = 1;
        }
      }
    }
    if (!ok) cout << 0 << endl;
  }
  return 0;
}
