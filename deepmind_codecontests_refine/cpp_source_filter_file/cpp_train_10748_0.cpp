#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int n, x, a, odd = 0, y = 0;
    cin >> n >> x;
    for (int j = 0; j < x; j++) {
      cin >> a;
      if (a % 2 != 0) {
        odd++;
      }
    }
    if (odd == 0) {
      cout << "no\n";
      continue;
    }
    for (int j = 1; j <= x; j = j + 2) {
      if ((j <= odd) && ((x - j) <= (x - odd))) {
        cout << "yes\n";
        y = 1;
        break;
      }
    }
    if (y != 1) {
      cout << "no\n";
      y = 0;
    }
  }
  return 0;
}
