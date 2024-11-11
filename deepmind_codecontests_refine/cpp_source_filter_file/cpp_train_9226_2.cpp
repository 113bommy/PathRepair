#include <bits/stdc++.h>
using namespace std;
int t, x, i, j, n, m, k;
int main() {
  cin >> t;
  while (t != 0) {
    cin >> x;
    while (x > 0) {
      if (x % 7 == 0)
        x = x - 7;
      else if (x % 3 == 0)
        x = x - 3;
      else if (x >= 7)
        x = x - 7;
      else if (x >= 3 && x < 7)
        x = x - 3;
      else
        x = x - 3;
    }
    if (x == 0)
      cout << "Yes" << '\n';
    else
      cout << "No" << '\n';
    t--;
  }
}
