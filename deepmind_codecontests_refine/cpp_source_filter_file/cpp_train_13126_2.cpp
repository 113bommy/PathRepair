#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long int n;
  cin >> n;
  long long int a, cs = 0, cb = 0;
  for (long long int i = 1; i <= n; i++) {
    cin >> a;
    cs += a;
  }
  for (long long int i = 1; i <= n; i++) {
    cin >> a;
    cb += a;
  }
  cout << (cs == cb ? "Yes\n" : "No\n");
}
int32_t main() {
  long long int T = 1;
  for (long long int t = 1; t <= T; t++) {
    solve();
  }
  return 0;
}
