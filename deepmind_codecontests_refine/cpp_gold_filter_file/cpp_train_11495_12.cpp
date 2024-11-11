#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, x, c1 = 0, c2 = 0, f = 0, i;
  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> x;
    if (x == 25) {
      c1++;
    } else if (x == 50) {
      if (c1 < 1) {
        f = 1;
        break;
      }
      c2++;
      c1--;
    } else {
      if (c1 + 2 * c2 < 3 || c1 < 1) {
        f = 1;
        break;
      }
      if (c2 >= 1) {
        c2--;
        c1--;
      } else {
        c1 = c1 - 3;
      }
    }
  }
  f == 0 ? cout << "YES\n" : cout << "NO\n";
}
