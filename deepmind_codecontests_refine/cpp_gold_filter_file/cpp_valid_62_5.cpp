#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long n;
  cin >> n;
  long long arr[n];
  for (long long i = 0; i < n; i++) cin >> arr[i];
  long long i;
  for (i = 1; i < n; i++) {
    if (arr[i - 1] == 0 && arr[i] == 1) break;
  }
  if (i == n) {
    if (arr[0] == 1) {
      cout << n + 1 << " ";
      for (long long k = 1; k <= n; k++) cout << k << " ";
    } else if (arr[n - 1] == 0) {
      for (long long k = 1; k <= n; k++) cout << k << " ";
      cout << n + 1 << " ";
    } else
      cout << -1;
    cout << endl;
    return;
  }
  for (long long k = 1; k <= i; k++) cout << k << " ";
  cout << n + 1 << " ";
  for (long long k = i + 1; k <= n; k++) cout << k << " ";
  cout << endl;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
