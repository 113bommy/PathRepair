#include <bits/stdc++.h>
using namespace std;
using ll = long long;
void solve() {
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  if (x1 == x2) {
    cout << abs(y1 - y2) << "\n";
  } else if (y1 == y2) {
    cout << abs(x1 - x2) << "\n";
  } else {
    cout << 2 * (abs(x1 - x2) + abs(y1 - y2)) << "\n";
  }
}
int main() {
  int t;
  cin >> t;
  while (t > 0) {
    solve();
    t--;
  }
  return 0;
}
