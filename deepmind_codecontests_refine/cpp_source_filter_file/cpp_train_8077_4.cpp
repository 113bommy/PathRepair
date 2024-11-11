#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y;
  cin >> x >> y;
  for (int i = 1;; ++i) {
    if (i & 1) {
      if (x - i < 0) {
        cout << "Vladik";
        return 0;
      }
      x -= i;
    } else {
      if (x - i < 0) {
        cout << "Valera";
        return 0;
      }
      y -= i;
    }
  }
  return 0;
}
