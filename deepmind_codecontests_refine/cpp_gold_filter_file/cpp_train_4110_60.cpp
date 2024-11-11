#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d, x = 0, y = 0;
  cin >> a >> b >> c >> d;
  if ((3 * a / 10) >= a - (a / 250 * c)) {
    x = 3 * a / 10;
  } else {
    x = a - (a / 250 * c);
  }
  if ((3 * b / 10) >= (b - (b / 250 * d))) {
    y = 3 * b / 10;
  } else {
    y = b - (b / 250 * d);
  }
  if (x < y) {
    cout << "Vasya" << endl;
    return 0;
  }
  if (x > y) {
    cout << "Misha" << endl;
    return 0;
  }
  if (x = y) {
    cout << "Tie" << endl;
    return 0;
  }
}
