#include <bits/stdc++.h>
const double PI = 2 * acos(0.0);
using namespace std;
int main() {
  int a, b, c, a1, b1, c1, x = 0;
  cin >> a >> b >> c;
  cin >> a1 >> b1 >> c1;
  if (a == a1) {
    x++;
  }
  if (b == b1) {
    x++;
  }
  if (c == c1) {
    x++;
  }
  if (x <= 2) {
    cout << "YES"
         << "\n";
  } else {
    cout << "NO"
         << "\n";
  }
  return 0;
}
