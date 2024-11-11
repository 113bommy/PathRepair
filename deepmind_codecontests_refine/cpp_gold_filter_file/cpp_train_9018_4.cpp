#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  if (y == 0) {
    cout << "No";
  }
  if (y == 1) {
    if (x >= 1) {
      cout << "No";
    } else {
      cout << "Yes";
    }
  }
  if (y >= 2) {
    if (x == y) {
      cout << "No";
    }
    if (x > y) {
      if ((x - y) % 2 == 0) {
        cout << "No";
      } else {
        cout << "Yes";
      }
    }
    if (x < y) {
      if (y - x == 1) {
        cout << "Yes";
      } else {
        cout << "No";
      }
    }
  }
  return 0;
}
