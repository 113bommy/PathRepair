#include <bits/stdc++.h>
using namespace std;
const int64_t M1 = 998244353;
const int64_t M2 = 1000000007;
mt19937 rng((uint64_t)chrono::steady_clock::now().time_since_epoch().count());
void solve() {
  int64_t n;
  cin >> n;
  vector<pair<int64_t, int64_t>> a;
  for (int64_t i = 0; i < n; i++) {
    int64_t x;
    cin >> x;
    a.push_back({x, i + 1});
  }
  sort(a.begin(), a.end());
  if (a[0].first == a[n - 1].first) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
    int64_t l = 0;
    while (a[l].first == a[0].first) l++;
    int64_t r = l - 1;
    while (l < n) cout << a[0].first << " " << a[l++].second << "\n";
    while (r > 0) cout << a[n - 1].second << " " << a[r--].second << "\n";
  }
}
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int64_t t;
  cin >> t;
  while (t--) solve();
}
