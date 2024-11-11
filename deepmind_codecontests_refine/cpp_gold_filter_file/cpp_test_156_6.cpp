#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n;
  long long k;
  cin >> n >> k;
  vector<long long> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  reverse(a.begin() + 1, a.end());
  for (int i = 1; i < n; ++i) a[i] += a[i - 1];
  long long res = 1e18;
  for (int i = 0; i < n; ++i) {
    long long l = 0, r = 1e18, s = a[n - 1] - a[i];
    while (l < r) {
      long long mid = (l + r) >> 1;
      __int128_t sum = a[0] - mid;
      sum *= (i + 1);
      if (sum + s <= k)
        r = mid;
      else
        l = mid + 1;
    }
    res = min(res, l + i);
  }
  cout << res << endl;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
