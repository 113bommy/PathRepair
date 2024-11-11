#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const long long N = 1e5, alp = 26;
const long double pi = 3.14159265358979;
void solve() {
  long long l, r;
  cin >> l >> r;
  if (l * 2 <= r) {
    cout << l << " " << l * 2 << "\n";
  } else
    cout << "-1 -1\n";
}
int32_t main() {
  ios_base::sync_with_stdio(NULL);
  cin.tie(0);
  cout.tie(0);
  long long t = 1;
  cin >> t;
  while (t--) solve();
}
