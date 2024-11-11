#include <bits/stdc++.h>
using namespace std;
int main() {
  int m, d, s, a, r;
  cin >> m >> d;
  if (m == 2) {
    s = 7 - d + 1;
    r = (28 - s) / 7;
    if ((28 - s) % 7 == 0) {
      a = r + 1;
    } else {
      a = r + 2;
    }
  } else if (m == 4 || m == 6 || m == 9 || m == 11) {
    s = 7 - d + 1;
    r = (30 - s) / 7;
    if ((30 - s) % 7 == 0) {
      a = r + 1;
    } else {
      a = r + 2;
    }
  } else {
    s = 7 - d + 1;
    r = (31 - s) / 7;
    if ((31 - s) % 7 == 0) {
      a = r + 1;
    } else {
      a = r + 2;
    }
  }
  cout << a;
  return 0;
}
