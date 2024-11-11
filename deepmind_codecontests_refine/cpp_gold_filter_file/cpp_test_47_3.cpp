#include <bits/stdc++.h>
using namespace std;
const long long MOD = 1000000007;
int main() {
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(false);
  cout.precision(15);
  int tt;
  cin >> tt;
  while (tt--) {
    int n, k;
    cin >> n >> k;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];
    sort(a.begin(), a.end());
    if ((fabs(a[n - 1]) >= fabs(a[0])) && a[n - 1] > 0) {
      reverse(a.begin(), a.end());
      for (int i = 0; i < n; ++i) a[i] *= -1;
    }
    int start;
    for (int i = 0; i < n; i++) {
      if (a[i] > 0) {
        start = i;
        break;
      }
    }
    int r = n - 1;
    long long ans = 0;
    while (r >= start + k && a[r] > 0) {
      ans += 2 * a[r];
      r -= k;
    }
    if (a[r] > 0) ans += 2 * a[r];
    reverse(a.begin(), a.end());
    for (int i = 0; i < n; ++i) a[i] *= -1;
    for (int i = 0; i < n; i++) {
      if (a[i] > 0) {
        start = i;
        break;
      }
    }
    r = n - 1;
    while (r >= start + k && a[r] > 0) {
      ans += 2 * a[r];
      r -= k;
    }
    if (a[r] > 0) ans += 2 * a[r];
    ans -= a[n - 1];
    cout << ans << '\n';
  }
  return 0;
}
