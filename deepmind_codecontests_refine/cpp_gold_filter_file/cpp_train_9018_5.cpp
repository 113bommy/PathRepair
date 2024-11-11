#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  while (cin >> x >> y) {
    if (!x && !y) {
      cout << "No" << endl;
    } else if (x == 0 && y == 1) {
      cout << "Yes" << endl;
    } else if (y <= 1) {
      cout << "No" << endl;
    } else if (x >= y - 1 && (x - y) % 2) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }
}
