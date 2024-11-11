#include <bits/stdc++.h>
using namespace std;
int main() {
  int t, r, g, b, w, x, y;
  cin >> t;
  while (t--) {
    cin >> r >> g >> b >> w;
    x = r % 2 + b % 2 + g % 2 + w % 2;
    y = r && b && g;
    if (x <= 1 || x == 4 || x == 3 && y)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
  return 0;
}
