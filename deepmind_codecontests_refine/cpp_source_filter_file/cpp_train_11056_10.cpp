#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y;
    cin >> x >> y;
    if (x == 1) {
      y == 1 ? cout << "YES" : cout << "NO";
    } else if (x == 2 || x == 3) {
      (y == 1 || y == 2 || y == 3) ? cout << "YES" : cout << "NO";
    } else {
      cout << "YES\n";
    }
  }
  return 0;
}
