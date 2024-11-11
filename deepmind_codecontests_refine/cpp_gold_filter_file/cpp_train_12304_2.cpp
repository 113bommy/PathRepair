#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, a, b;
  cin >> x >> y;
  if (x == y) {
    a = 10 * x;
    b = a + 1;
    cout << a << " " << b << endl;
  } else if (y - x == 1) {
    a = x;
    b = y;
    cout << a << " " << b << endl;
  } else if (x == 9 && y == 1) {
    cout << 9 << " " << 10 << endl;
  } else
    cout << "-1" << endl;
}
