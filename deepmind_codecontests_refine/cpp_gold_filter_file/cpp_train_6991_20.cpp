#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int a = x - y;
  if (a == 0 && z == 0) {
    cout << 0 << endl;
    return 0;
  } else if (a == 0 && z != 0) {
    cout << "?" << endl;
    return 0;
  }
  if (a > 0) {
    a = a - z;
    if (a > 0) {
      cout << "+" << endl;
      return 0;
    } else {
      cout << "?" << endl;
      return 0;
    }
  } else {
    a = a + z;
    if (a < 0) {
      cout << "-" << endl;
      return 0;
    } else {
      cout << "?" << endl;
      return 0;
    }
  }
}
