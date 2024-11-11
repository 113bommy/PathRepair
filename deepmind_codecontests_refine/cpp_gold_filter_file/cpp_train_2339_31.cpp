#include <bits/stdc++.h>
using namespace std;
bool f(char x, char y) {
  if ((x == 'r' && y == 's') || (x == 'p' && y == 'r') ||
      (x == 's' && y == 'p')) {
    return 1;
  }
  return 0;
}
int main() {
  string aa, bb, cc;
  char a, b, c;
  cin >> aa >> bb >> cc;
  a = aa[0];
  b = bb[0];
  c = cc[0];
  if (a == b && a != c) {
    if (f(c, a)) {
      cout << "S";
    } else {
      cout << "?";
    }
  } else {
    if (a == c && a != b) {
      if (f(b, a)) {
        cout << "M";
      } else {
        cout << "?";
      }
    } else {
      if (b == c && b != a) {
        if (f(a, b)) {
          cout << "F";
        } else {
          cout << "?";
        }
      } else {
        cout << "?";
      }
    }
  }
}
