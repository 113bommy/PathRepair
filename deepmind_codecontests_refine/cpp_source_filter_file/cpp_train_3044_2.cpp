#include <bits/stdc++.h>
using namespace std;
const long long int N = 2e5 + 5;
void solve() {
  long long int n, i;
  cin >> n;
  vector<pair<long long int, long long int> > a(n), b(n);
  for (auto &x : a) {
    cin >> x.first;
    cin >> x.second;
  };
  b = a;
  long long int mi = LLONG_MAX, x = -1;
  long long int ans = LLONG_MAX, sum = 0;
  for (i = 0; i < n; i++) {
    if (i == 0) {
      a[i].first -= a[n - 1].second;
      a[i].first = max(0LL, a[i].first);
    } else {
      a[i].first -= a[i - 1].second;
      a[i].first = max(0LL, a[i].first);
    }
    sum += a[i].first;
  }
  for (i = 0; i < n; i++) {
    sum -= a[i].first;
    sum += b[i].first;
    ans = min(ans, sum);
    sum -= b[i].first;
    sum += a[i].first;
  }
  cout << ans;
}
signed main() {
  ios_base::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
  long long int t = 1;
  cin >> t;
  while (t--) {
    solve();
  }
}
