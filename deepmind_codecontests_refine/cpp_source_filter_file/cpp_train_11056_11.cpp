#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, x, y;
  cin >> t;
  for (int tt = 0; tt < t; ++tt) {
    cin >> x >> y;
    if (x > 3 || (x == 1 && y == 1) || ((x == 2 || x == 3) && y <= 4))
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
