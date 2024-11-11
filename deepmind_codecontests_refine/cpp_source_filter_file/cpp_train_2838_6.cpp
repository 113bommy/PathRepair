#include <bits/stdc++.h>
using namespace std;
void solve() {
  int x, y, z;
  cin >> x >> y >> z;
  if (x == z && x >= y) {
    cout << "YES" << '\n';
    cout << x << ' ' << y << ' ' << z;
    cout << '\n';
  } else if ((x == y && x >= z)) {
    cout << "YES" << '\n';
    cout << x << ' ' << z << ' ' << z;
    cout << '\n';
  } else if ((y == z && y >= x)) {
    cout << "YES" << '\n';
    cout << x << ' ' << x << ' ' << z;
    cout << '\n';
  } else {
    cout << "NO" << '\n';
  }
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) solve();
}
