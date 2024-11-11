#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long x, y;
    cin >> x >> y;
    if (x < 4) {
      if (x % 2 == 0) {
        if (y > x * 1.5)
          cout << "NO\n";
        else
          cout << "YES\n";
      } else {
        if (x == 1) {
          if (y == 1)
            cout << "YES\n";
          else
            cout << "NO\n";
        } else if (x == 3) {
          if (y > 3)
            cout << "NO\n";
          else
            cout << "YES\n";
        } else if (x == 5) {
          if (y == 6)
            cout << "YES\n";
          else if (y > 5)
            cout << "NO\n";
          else
            cout << "YES\n";
        }
      }
    } else
      cout << "YES\n";
  }
  return 0;
}
