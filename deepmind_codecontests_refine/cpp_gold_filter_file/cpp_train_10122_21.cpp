#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int x, y, a, b;
    cin >> x >> y;
    if (x % 2 == 0) {
      a = 0;
    } else {
      a = 1;
    }
    if (y % 2 == 0) {
      b = 0;
    } else {
      b = 1;
    }
    if (x == y) {
      cout << "0\n";
    } else if (x < y) {
      if (a != b) {
        cout << 1 << "\n";
      } else {
        cout << 2 << "\n";
      }
    } else if (x > y) {
      if (a != b) {
        cout << 2 << "\n";
      } else {
        cout << 1 << "\n";
      }
    }
  }
  return 0;
}
