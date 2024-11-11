#include <bits/stdc++.h>
using namespace std;
void solve() {
  int w1, h1, w2, h2;
  cin >> w1 >> h1 >> w2 >> h2;
  long long ans = 0;
  ans += 2 * (h1 + h1 + 2) + (w1 + w2 + (w1 - w2));
  cout << ans << endl;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}
