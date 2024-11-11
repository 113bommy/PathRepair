#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, i, j, x, y, k, m, n;
  while (cin >> a >> b >> c >> d) {
    while (1) {
      a = a - c;
      if (a < 0) {
        cout << "Second" << endl;
        break;
      }
      b = b - d;
      if (b < 0) {
        cout << "First" << endl;
        break;
      }
    }
  }
  return 0;
}
