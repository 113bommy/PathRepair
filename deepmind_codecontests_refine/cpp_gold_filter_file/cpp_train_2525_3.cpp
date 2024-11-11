#include <bits/stdc++.h>
using namespace std;
const long long oo = 1e18 + 7, mod = 1e9 + 7;
long long t, n, k, l, d[300005], ini;
bool up_or_down;
signed main() {
  ios_base::sync_with_stdio(0);
  cin >> t;
  while (t--) {
    cin >> n >> k >> l;
    for (long long i = 1; i <= n; i++) cin >> d[i];
    ini = k;
    up_or_down = 1;
    bool ok = 1;
    for (long long i = 1; i <= n; i++) {
      if (d[i] > l) {
        ok = 0;
        break;
      }
      if (ini == k) {
        if ((l - d[i]) < k)
          up_or_down = 1;
        else
          continue;
      }
      if (!ini) up_or_down = 0;
      if (up_or_down == 1) {
        if (l - d[i] >= k) {
          ini = k;
          continue;
        }
        if (ini > (l - d[i] + 1))
          ini = l - d[i];
        else
          ini--;
      } else {
        if (ini >= l - d[i]) {
          ok = 0;
          break;
        }
        if ((l - d[i]) < k)
          ini++;
        else
          ini = k;
      }
    }
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
