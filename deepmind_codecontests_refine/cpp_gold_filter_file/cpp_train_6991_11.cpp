#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y, z;
  cin >> x >> y >> z;
  if (x == y) {
    if (z == 0)
      cout << '0';
    else
      cout << '?';
  } else if (y > x) {
    if (y - x > z)
      cout << '-';
    else
      cout << '?';
  } else {
    if (x - y > z)
      cout << '+';
    else
      cout << '?';
  }
  return 0;
}
