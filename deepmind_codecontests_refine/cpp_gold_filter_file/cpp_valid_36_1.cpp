#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t, n, i, j, x, y, z;
  cin >> t;
  while (t--) {
    cin >> n;
    x = (n + 1) / 2;
    for (i = 1; i <= n; i++) {
      if (n & 1) {
        if (i == x || i == x + 1) {
          if (i & 1) {
            cout << "b";
          } else {
            cout << "c";
          }
        } else {
          cout << "a";
        }
      } else if (n % 2 == 0) {
        if (i == x) {
          cout << "b";
        } else {
          cout << "a";
        }
      }
    }
    cout << endl;
  }
}
