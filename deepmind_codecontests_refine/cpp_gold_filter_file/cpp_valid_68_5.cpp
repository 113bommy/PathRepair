#include <bits/stdc++.h>
using namespace std;
long long t, n, k, b, c;
const long long inf = 1e9 + 10;
const long long maxn = 1e5 + 10;
void solve() {
  cin >> k;
  long long i;
  for (i = 1; i < 100000; i++) {
    if (i * i <= k && (i + 1) * (i + 1) > k) {
      break;
    }
  }
  if (i * i == k) {
    cout << i << " 1" << '\n';
    return;
  }
  if (k - (i * i) == i + 1) {
    cout << i + 1 << " " << i + 1 << '\n';
    return;
  }
  if (k - (i * i) < i + 1) {
    cout << k - (i * i) << " " << i + 1 << '\n';
    return;
  }
  if (k - (i * i) > i + 1) {
    cout << i + 1 << " " << (i + 1) * (i + 1) - k + 1 << '\n';
    return;
  }
}
int32_t main() {
  cin >> t;
  while (t--) {
    solve();
  }
}
