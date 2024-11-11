#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a[3];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a + 3);
  if (a[1] != a[2]) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    cout << a[0] << " " << a[0] << " " << a[2] << endl;
  }
}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  long long t;
  cin >> t;
  while (t--) solve();
  return 0;
}
