#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int c1, c2;
    int d1, d2;
    int diff1, diff2;
    for (int i = 0; i < 3; i++) {
      if ((n - i) % 3 == 0) {
        c2 = (n - i) / 3;
        c1 = n - 2 * c2;
        diff1 = i;
        break;
      }
    }
    for (int i = 0; i < 3; i++) {
      if ((n - i) % 3 == 0) {
        d2 = (n + i) / 3;
        d1 = n - 2 * d2;
        diff2 = i;
        break;
      }
    }
    if (diff1 < diff2)
      cout << c1 << " " << c2 << "\n";
    else
      cout << d1 << " " << d2 << "\n";
  }
}
