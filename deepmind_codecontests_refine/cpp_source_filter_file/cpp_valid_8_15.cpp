#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  int x, c1, c2;
  while (t--) {
    cin >> x;
    if (x % 3 == 0) {
      c1 = x / 3;
      c2 = (2 * x) / 3;
    } else {
      if ((x % 3) % 2 == 0) {
        c1 = x / 3;
        c2 = (x - c1) / 2;
      } else {
        c1 = (x / 3) + 1;
        c2 = (x - c1) / 2;
      }
    }
    cout << c1 << " " << c2 << endl;
  }
  return 0;
}
