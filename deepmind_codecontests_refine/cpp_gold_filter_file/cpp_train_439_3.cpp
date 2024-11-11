#include <bits/stdc++.h>
using namespace std;
void solve() {
  int x = 0, y = 0;
  cin >> x >> y;
  cout << min({x, y, (x + y) / 3}) << "\n";
}
int main() {
  int t = 0;
  cin >> t;
  while (t--) {
    solve();
  }
}
