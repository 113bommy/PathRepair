#include <bits/stdc++.h>
using namespace std;
const long long mx = 200007;
long long a[mx];
bool ok(long long mid, long long k, long long n) {
  for (long long i = 0; i < n; i++)
    if (abs(a[i] - mid) > k) return false;
  return true;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long q, n, k;
  cin >> q;
  while (q--) {
    cin >> n >> k;
    long long mx = INT_MIN, mn = INT_MAX;
    for (long long i = 0; i < n; i++) {
      cin >> a[i];
      mx = max(mx, a[i]);
      mn = min(mn, a[i]);
    }
    if (mx - mn > 2 * k)
      cout << -1 << "\n";
    else {
      cout << mn + k << "\n";
    }
  }
  return 0;
}
