#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m, mx1 = 0, mx2 = 0, ans, x, y;
    cin >> n;
    while (n--) {
      cin >> m;
      mx1 += m;
      if (m == 0) mx2++;
    }
    if (mx1 == 0)
      cout << max(1, mx2) << endl;
    else if (mx1 != 0 && mx2 == 0)
      cout << 0 << endl;
    else if (mx1 < 0 && mx2 == mx1)
      cout << mx2 + 1 << endl;
    else if (mx1 != 0 && mx2 > 0)
      cout << mx2 << endl;
  }
}
