#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, ma = 0, mi, m, k, z;
  cin >> t;
  while (t--) {
    long long a[200001];
    ma = 0, mi = 1000000000, m = 0;
    cin >> n;
    for (long long i = 0; i < n; ++i) cin >> a[i];
    for (long long i = 0; i < n; ++i) {
      if (a[i] != -1) {
        if (i > 0)
          if (a[i - 1] == -1) {
            mi = min(mi, a[i]);
            ma = max(ma, a[i]);
          }
        if (i < n - 1)
          if (a[i + 1] == -1) {
            mi = min(mi, a[i]);
            ma = max(ma, a[i]);
          }
        if (i > 0 && i < n - 1) {
          if (a[i - 1] != -1) m = max(m, abs(a[i] - a[i - 1]));
          if (a[i + 1] != -1) m = max(m, abs(a[i] - a[i + 1]));
        }
      }
    }
    if (m > 0) z = m;
    {
      if (mi != 1000000000) {
        k = ceil((ma - mi) / 2.0);
        m = max(m, k);
      }
    }
    cout << m << " ";
    cout << (ma + mi) / 2 << endl;
  }
}
