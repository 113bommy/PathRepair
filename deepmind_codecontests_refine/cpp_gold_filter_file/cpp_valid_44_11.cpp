#include <bits/stdc++.h>
using namespace std;
int main() {
  int T;
  cin >> T;
  while (T--) {
    int x, y;
    cin >> x >> y;
    int d = abs(x - y);
    if (d == 1) {
      cout << -1 << '\n';
    } else if (d == 0) {
      if (x == 0) {
        cout << 0 << '\n';
      } else {
        cout << 1 << '\n';
      }
    } else if (d == 2) {
      cout << 2 << '\n';
    } else {
      if (d % 2 == 0) {
        if (x == 0 || y == 0) {
          cout << 2 << '\n';
        } else {
          cout << 2 << '\n';
        }
      } else
        cout << -1 << '\n';
    }
  }
}
