#include <bits/stdc++.h>
using namespace std;
int a[2000009];
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int t, i, j, k, x, y, z, n, m, ln, sq, q, l, r, up, in, op = 1;
  int ans = 0, sum = 0, ct = 0, ok = 0, mx = -INT_MAX, mn = INT_MAX,
      hi = INT_MAX, lo = 0, mid;
  string s, st;
  cin >> t;
  while (t--) {
    cin >> n;
    for (i = 0; i < n; i++) cin >> a[i];
    ok = 0, ct = 0, mn = 0;
    for (i = 0; i < n; i++) {
      if (a[i] == 1) ok = 1;
      if (ok == 1 && a[i] == 0) ct++;
      if (ok == 1 && a[i] == 1) {
        mn += ct;
        ct = 0;
      }
    }
    ok = 0, ct = 0, ans = 0;
    for (i = n - 1; i >= 0; i--) {
      if (a[i] == 1) ok = 1;
      if (ok == 1 && a[i] == 0) ct++;
      if (ok == 1 && a[i] == 1) {
        ans += ct;
        ct = 0;
      }
    }
    ans = min(ans, mn);
    cout << ans << "\n";
  }
}
