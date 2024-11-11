#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, x, y, c = 1;
  cin >> a >> x >> y;
  if (y / a != 0 && (y / a) % 2 == 0) {
    if (x == 0 || x >= a || x <= a * -1 || y % a == 0) {
      cout << -1 << endl;
      return 0;
    } else {
      for (int i = 1; i <= y / a; i++) {
        if (i % 2 == 0) {
          c += 2;
        } else {
          c++;
        }
      }
      if (x < 0) {
        c--;
      }
    }
  } else {
    if (y % a == 0 || (x >= a / 2 && x % 2 == 0) ||
        (x <= (a / 2) * -1 && a % 2 == 0) || (x > (a / 2) && a % 2 != 0) ||
        (x < (a / 2) * -1 && a % 2 != 0)) {
      cout << -1 << endl;
      return 0;
    } else {
      for (int i = 1; i <= y / a; i++) {
        if (i % 2 == 0) {
          c += 2;
        } else {
          c++;
        }
      }
    }
  }
  cout << c << endl;
  return 0;
}
