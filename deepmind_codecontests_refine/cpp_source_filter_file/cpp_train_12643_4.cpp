#include <bits/stdc++.h>
using namespace std;
int main() {
  long long base = 1000000007, x, y, n;
  cin >> x >> y >> n;
  if (n == 1) {
    cout << (x + base) % base;
    return 0;
  }
  if (n == 2) {
    cout << (y + base) % base;
    return 0;
  }
  if (n == 3) {
    cout << (y - x + 3 * base) % base;
    return 0;
  }
  switch (n % 6) {
    case 4:
      cout << (-x + base * 3) % base;
      return 0;
    case 5:
      cout << (-y + 3 * base) % base;
      return 0;
    case 0:
      cout << (x - y + 3 * base) % base;
      return 0;
    case 1:
      cout << (x + base) % base;
      return 0;
    case 2:
      cout << (-y + base) % base;
      return 0;
    case 3:
      cout << (-x - y + 3 * base) % base;
      return 0;
  }
  return 0;
}
