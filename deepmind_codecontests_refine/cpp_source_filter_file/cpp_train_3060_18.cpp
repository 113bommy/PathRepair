#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, l, t;
  cin >> n >> l >> t;
  vector<long long> a(2 * n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i + n] = l + a[i];
  }
  long double bl = t / l;
  long double ans = n * (n - 1) * bl;
  t %= l;
  for (int i = n; i < 2 * n; ++i) {
    int p = i;
    int lo = p - n, hi = p;
    while (hi - lo > 1) {
      int mid = (lo + hi) / 2;
      if (a[p] - a[mid] + l <= 2 * t)
        hi = mid;
      else
        lo = mid;
    }
    ans += 2 * (p - hi);
    p = hi;
    lo = p - n;
    while (hi - lo > 1) {
      int mid = (lo + hi) / 2;
      if (a[p] - a[mid] <= 2 * t)
        hi = mid;
      else
        lo = mid;
    }
    ans += p - hi;
  }
  ans *= 0.25;
  cout << fixed << setprecision(10) << ans << '\n';
  return 0;
}
