#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9 + 9, mod = 1e9 + 7;
int n, a[100005];
void solve() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (n == 1) {
    cout << 0 << '\n';
    return;
  }
  int cur = a[n - 1], cnt = 0;
  for (int i = n - 2; i >= 0; i--) {
    if (a[i] > cur) {
      cur = a[i];
      ++cnt;
    }
  }
  cout << cnt << '\n';
}
int32_t main() {
  cin.tie(0)->sync_with_stdio(0);
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
