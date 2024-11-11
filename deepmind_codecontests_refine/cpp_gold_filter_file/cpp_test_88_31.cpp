#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
void solve() {
  long long n, i;
  cin >> n;
  long long a[n];
  for (i = 0; i < n; i++) cin >> a[i];
  if (n % 2 == 0) {
    cout << "YES\n";
    return;
  }
  for (i = 0; i < n - 1; i++) {
    if (a[i] >= a[i + 1]) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
}
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
