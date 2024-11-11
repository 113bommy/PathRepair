#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y, n = 0;
    cin >> x >> y;
    for (int i = 2; i <= x; i++) {
      if (x % i == 0) {
        n = i;
        break;
      }
    }
    cout << x + n + (y - 1) * 2 << endl;
  }
}
