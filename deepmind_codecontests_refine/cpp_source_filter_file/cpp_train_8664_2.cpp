#include <bits/stdc++.h>
using namespace std;
const long long N = 500005;
const long long mod = 1e9 + 7;
vector<long long> cnt(N);
void solve() {
  long long x = 0, y = 0, c = 0, ans = 0;
  long long n, m, k;
  cin >> n >> k;
  long long a[k + 1];
  x = 1;
  for (long long i = 1; i <= k; ++i) {
    cin >> a[i];
    c += a[i];
    if (i >= n - a[i] + 1) {
      cout << -1 << "\n";
      return;
      ;
    }
  }
  if (c < n) {
    cout << -1 << "\n";
    return;
    ;
  }
  for (long long i = k + 1 - 1; i >= 1; i--) {
    cnt[i] = cnt[i + 1] + a[i];
  }
  for (long long i = 1; i <= k; ++i) {
    cout << max(i, n - cnt[i] + 1) << " ";
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  solve();
  return 0;
}
