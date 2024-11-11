#include <bits/stdc++.h>
using namespace std;
long long int solve() {
  long long int n;
  cin >> n;
  long long int a[n];
  long long int co = 0, ce = 0;
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] % 2 != 0)
      co++;
    else
      ce++;
  }
  if (co % 2 != 0)
    return cout << 1 << endl, 0;
  else
    return cout << ce << endl, 0;
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long int tests = 1;
  while (tests--) solve();
  return 0;
}
