#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int l, r, x, y;
    cin >> l >> r;
    if (l == 1 || r % l == 0)
      cout << l << " " << r << "\n";
    else {
      if (r < 2 * l)
        cout << "-1 -1\n";
      else
        cout << l << " " << 2 * l << "\n";
    }
  }
  return 0;
}
