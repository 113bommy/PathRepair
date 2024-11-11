#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x, y, z;
  cin >> x >> y >> z;
  if (x == 0 && y == 0) {
    if (z != 0) {
      cout << "0";
    } else {
      cout << "?";
    }
  } else {
    if ((x + z) - y > 0 && x - (y + z) > 0) {
      cout << "+";
    } else if ((x + z) - y < 0 && x - (y + z) < 0) {
      cout << "-";
    } else if (x = y = z) {
      cout << "?";
    } else if ((x + z) - (y + z) == 0) {
      cout << "0";
    } else if ((x + z) - y == 0 || x - (y + z) == 0) {
      cout << "?";
    }
  }
  return 0;
}
