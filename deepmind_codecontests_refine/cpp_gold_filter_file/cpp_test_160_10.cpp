#include <bits/stdc++.h>
using namespace std;
void solve() {
  int n, m, rb, cb, rd, cd;
  cin >> n >> m >> rb >> cb >> rd >> cd;
  int x = (rb <= rd) ? abs(rd - rb) : (abs(rb - n) + abs(n - rd));
  int y = (cb <= cd) ? abs(cd - cb) : (abs(cb - m) + abs(m - cd));
  int ans = min(x, y);
  cout << ans << endl;
}
int main() {
  int t;
  cin >> t;
  while (t--) solve();
  return 0;
}
