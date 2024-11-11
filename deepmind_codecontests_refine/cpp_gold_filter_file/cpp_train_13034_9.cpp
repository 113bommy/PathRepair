#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; i++) cin >> a[i];
  long long s = 0, x = 0;
  for (long long y : a) {
    s += y;
    x ^= y;
  }
  vector<long long> ans;
  long long large = 1ll << 50;
  if (s % 2) large++;
  s += large;
  x ^= large;
  ans.push_back(large);
  if (s < 2 * x) {
    long long d = 2 * x - s;
    ans.push_back(d / 2);
    ans.push_back(d / 2);
  }
  cout << ans.size() << "\n";
  for (long long x : ans) cout << x << " ";
  cout << "\n";
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  cout << fixed;
  long long tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
  }
}
