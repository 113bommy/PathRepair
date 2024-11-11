#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x, y, z;
  cin >> n;
  if (n < 10) {
    cout << n;
    return 0;
  } else if (n >= 10 && n <= 189) {
    x = 10 + (n - 10) / 2;
    y = n % 2;
    while (y < 2) {
      z = x % 10;
      x = x / 10;
      y++;
    }
    cout << z;
    return 0;
  } else {
    x = 100 + (n - 190) / 3;
    y = n % 3;
    if (y == 0) {
      z = x % 10;
      cout << z;
      return 0;
    }
    while (y < 3) {
      z = x % 10;
      x = x / 10;
      y++;
    }
    cout << z;
    return 0;
  }
}
