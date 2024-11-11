#include <bits/stdc++.h>
const int MOD = int(1e9 + 7);
const int MX = int(2e6 + 9);
using namespace std;
void solve() {
  int n, a[200005], i, j, k, rest = 0, res = 0;
  cin >> n;
  for (i = 0; i < n; ++i) cin >> a[i];
  for (i = 0; i < 2 * n; i++) {
    if (a[i % n] == 1) {
      rest = rest + 1;
      res = max(res, rest);
    } else
      rest = 0;
  }
  cout << res << endl;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int t;
  t = 1;
  while (t--) {
    solve();
  }
}
