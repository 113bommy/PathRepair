#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long a[6];
  for (long long i = 0; i < 5; i++) cin >> a[i];
  if (a[0] != a[3] && a[1] != a[4] && a[2] != a[5])
    cout << "NO\n";
  else
    cout << "YES\n";
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long T;
  T = 1;
  while (T--) {
    solve();
  }
  return 0;
}
