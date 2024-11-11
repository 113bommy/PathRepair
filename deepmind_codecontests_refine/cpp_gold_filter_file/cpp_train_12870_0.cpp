#include <bits/stdc++.h>
using namespace std;
long long n, x, k;
long long a[100010];
long long f(int l, int r) {
  if (l > r) swap(l, r);
  return a[r] / x - (a[l] - 1) / x;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> x >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a, a + n + 1);
  long long ans = 0;
  long long lo = 1, hi = 1;
  for (int i = 1; i <= n; i++) {
    while (lo < n && a[lo] < a[i]) lo++;
    while (hi < n && a[hi] < a[i]) hi++;
    while (lo < n && f(lo, i) < k) lo++;
    while (hi <= n && f(hi, i) <= k) hi++;
    if (f(lo, i) == k) {
      ans += (hi - lo);
    }
  }
  cout << ans << endl;
  return 0;
}
