#include <bits/stdc++.h>
using namespace std;
void solve() {
  long long x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  x2 -= x1 - 1;
  y2 -= y1 - 1;
  long long ans = x2 * y2 - (x2 + y2 - 1) + 1;
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t;
  cin >> t;
  while (t-- > 0) {
    solve();
  }
  return 0;
}
