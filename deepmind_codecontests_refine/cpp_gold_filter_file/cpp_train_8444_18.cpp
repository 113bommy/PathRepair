#include <bits/stdc++.h>
using namespace std;
void QuickStart() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
}
void solve() {
  int y, b, r;
  cin >> y >> b >> r;
  int ans = -1;
  for (int i = 1; i <= y; i++) {
    if (i + 1 > b || i + 2 > r) {
      continue;
    }
    ans = max(ans, 3 * i + 3);
  }
  cout << ans;
}
int main() {
  QuickStart();
  int t = 1;
  while (t--) solve();
  return 0;
}
