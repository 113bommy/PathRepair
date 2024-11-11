#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n, m, s = 0;
  cin >> n >> m;
  long long a[n];
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    s += a[i];
  }
  if (s < m) {
    cout << -1;
    return;
  }
  if (s == m) {
    cout << n;
    return;
  }
  sort(a, a + n, greater<long long>());
  for (long long i = 1; i <= n; i++) {
    long long sum = 0;
    for (long long j = 0; j < n; j++) {
      sum += max(a[j] - j / i, 0ll);
    }
    if (sum >= i) {
      cout << i << '\n';
      return;
    }
  }
  cout << -1 << '\n';
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
