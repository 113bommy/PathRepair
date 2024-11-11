#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
void solve() {
  long long n;
  cin >> n;
  vector<long long> a(n);
  for (long long i = 0; i < n; ++i) {
    cin >> a[i];
  }
  if (n % 2 == 0) {
    for (long long i = 0; i < n; i += 2) {
      cout << -a[i + 1] << " " << -a[i] << " ";
    }
    cout << '\n';
    return;
  }
  for (long long i = 0; i < n - 3; i += 2) {
    cout << -a[i + 1] << " " << -a[i] << " ";
  }
  if (a[n - 1] + a[n - 2] != 0) {
    cout << (a[n - 1] + a[n - 2]) << " " << -a[n - 3] << " " << -a[n - 3]
         << '\n';
    return;
  }
  if (a[n - 3] + a[n - 2] != 0) {
    cout << -a[n - 1] << " " << -a[n - 1] << " " << (a[n - 3] + a[n - 2])
         << '\n';
    return;
  }
  if (a[n - 1] + a[n - 3] != 0) {
    cout << -a[n - 2] << " " << (a[n - 1] + a[n - 3]) << " " << -a[n - 2]
         << '\n';
    return;
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long t = 1;
  cin >> t;
  for (long long i = 1; i <= t; i++) {
    solve();
  }
}
