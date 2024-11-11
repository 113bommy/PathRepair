#include <bits/stdc++.h>
using namespace std;
void solve() {
  int h1, h2, up, down;
  cin >> h1 >> h2 >> up >> down;
  if (up * 8 + h1 >= h2) {
    cout << "0\n";
    return;
  }
  if (up <= down) {
    cout << "-1\n";
    return;
  }
  int ans = 0;
  h1 += up * 8;
  h1 -= down * 10;
  while (1) {
    ans++;
    h1 += up * 10;
    if (h1 >= h2) break;
    h1 -= down * 10;
  }
  cout << ans << '\n';
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  while (t--) solve();
}
