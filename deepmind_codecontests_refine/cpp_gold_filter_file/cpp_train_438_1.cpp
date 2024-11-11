#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long a[n];
  bool f = 1;
  set<long long> s;
  for (long long i = 0; i < n; i++) {
    cin >> a[i];
    if (s.count((a[i] % n + i + n) % n)) {
      f = 0;
    } else
      s.insert((a[i] % n + i + n) % n);
  }
  cout << (f ? "YES" : "NO") << endl;
}
int32_t main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
