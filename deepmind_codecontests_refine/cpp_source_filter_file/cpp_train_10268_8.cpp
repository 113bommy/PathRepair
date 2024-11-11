#include <bits/stdc++.h>
using namespace std;
int n, i, a[200100], b[200100], d[200100], k, ans = 0;
int main() {
  cin >> n;
  for (i = 1; i <= n; ++i) {
    cin >> a[i] >> b[i];
  }
  k = a[1] + b[1];
  for (i = 1; i <= n; ++i) d[i] = a[i] + b[i];
  for (i = 2; i <= n; ++i) {
    d[i] = min(d[i], k + 1);
    if (d[i] < a[i]) {
      cout << -1;
      return 0;
    }
    k = d[i];
  }
  k = a[n] + b[n];
  for (i = n - 1; i >= 1; --i) {
    d[i] = min(d[i], k + 1);
    if (d[i] < a[i]) {
      cout << -1;
      return 0;
    }
    k = d[i];
  }
  for (i = 1; i <= n; ++i) ans += d[i] - a[i];
  cout << ans << endl;
  for (i = 1; i <= n; ++i) cout << d[i] << " ";
  return 0;
}
