#include <bits/stdc++.h>
using namespace std;
long long d[100005];
long long c[100005];
long long a[100005];
int main() {
  long long n, p, q, r;
  while (cin >> n >> p >> q >> r) {
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
      if (i == 0) {
        d[i] = a[i] * p;
      } else {
        d[i] = max(a[i] * p, d[i - 1]);
      }
    }
    for (int i = n - 1; i >= 0; i--) {
      if (i == n - 1) {
        c[i] = a[i] * r;
      } else {
        c[i] = max(c[i + 1], a[i] * r);
      }
    }
    long long ans = -1e18;
    for (int i = 0; i < n; i++) {
      ans = max(ans, c[i] + d[i] + a[i] * q);
    }
    cout << ans << endl;
  }
  return 0;
}
