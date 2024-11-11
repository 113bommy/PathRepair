#include <bits/stdc++.h>
using namespace std;
void DBG() { cerr << "]\n"; }
template <typename T, typename... Args>
void DBG(T first, Args... args) {
  cerr << first;
  if (sizeof...(args)) cerr << ", ";
  DBG(args...);
}
void solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) cin >> a[i];
  long long int ans = 0;
  vector<long long int> bits(32, 0);
  for (long long int i = 0; i < n; i++) {
    for (long long int j = 31; j >= 0; j--) {
      if (a[i] & (1 << j)) {
        bits[j]++;
        break;
      }
    }
  }
  for (long long int i = 0; i < 32; i++) {
    ans += bits[i] * (bits[i] - 1) / 2;
  }
  cout << ans << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  long long int t = 1;
  cin >> t;
  for (long long int tt = 1; tt <= t; tt++) {
    solve();
  }
}
