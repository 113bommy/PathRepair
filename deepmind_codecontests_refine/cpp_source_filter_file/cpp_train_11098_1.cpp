#include <bits/stdc++.h>
using namespace std;
char x, y;
int n;
int main() {
  char a[120];
  a[0] = 118;
  a[1] = 60;
  a[2] = 94;
  a[3] = 62;
  a[4] = 118;
  a[5] = 60;
  a[6] = 94;
  a[7] = 62;
  cin >> x >> y >> n;
  if ((n % 4) == 0) {
    cout << "undefined" << endl;
    return 0;
  }
  if (x == a[0] && y == a[2]) {
    cout << "undefined" << endl;
    return 0;
  }
  if (x == a[2] && y == a[0]) {
    cout << "undefined" << endl;
    return 0;
  }
  if (x == a[1] && y == a[3]) {
    cout << "undefined" << endl;
    return 0;
  }
  if (x == a[3] && y == a[1]) {
    cout << "undefined" << endl;
    return 0;
  }
  if ((int)x == 118 && n % 4 == 1) {
    if (y == a[1]) {
      cout << "cw" << endl;
      return 0;
    } else {
      cout << "ccw" << endl;
      return 0;
    }
  }
  if ((int)x == 118 && n % 4 == 3) {
    if (y == a[3]) {
      cout << "cw" << endl;
      return 0;
    } else {
      cout << "ccw" << endl;
      return 0;
    }
  }
  if ((int)x == 60 && n % 4 == 1) {
    if (y == a[2]) {
      cout << "cw" << endl;
      return 0;
    } else {
      cout << "ccw" << endl;
      return 0;
    }
  }
  if ((int)x == 60 && n % 4 == 3) {
    if (y == a[1]) {
      cout << "cw" << endl;
      return 0;
    } else {
      cout << "ccw" << endl;
      return 0;
    }
  }
  if ((int)x == 94 && n % 4 == 1) {
    if (y == a[3]) {
      cout << "cw" << endl;
      return 0;
    } else {
      cout << "ccw" << endl;
      return 0;
    }
  }
  if ((int)x == 94 && n % 4 == 3) {
    if (y == a[1]) {
      cout << "cw" << endl;
      return 0;
    } else {
      cout << "ccw" << endl;
      return 0;
    }
  }
  if ((int)x == 62 && n % 4 == 1) {
    if (y == a[2]) {
      cout << "cw" << endl;
      return 0;
    } else {
      cout << "ccw" << endl;
      return 0;
    }
  }
  if ((int)x == 62 && n % 4 == 3) {
    if (y == a[0]) {
      cout << "cw" << endl;
      return 0;
    } else {
      cout << "ccw" << endl;
      return 0;
    }
  }
}
