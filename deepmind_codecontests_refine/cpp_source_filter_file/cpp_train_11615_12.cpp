#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int a = (int)s[0];
  int b = (int)s[1];
  int c = (int)s[3];
  int d = (int)s[4];
  a = a - 48;
  b = b - 48;
  c = c - 48;
  d = d - 48;
  int i = 0;
  int f = 10 * a + b;
  int g = 10 * c + d;
  if (n == 12) {
    if (f == 0) {
      if (g <= 59) {
        cout << a << "1"
             << ":" << c << d;
        return 0;
      } else {
        cout << a << "1"
             << ":"
             << "0" << d;
        return 0;
      }
    }
    if (f <= 12) {
      if (g <= 59) {
        cout << a << b << ":" << c << d;
        return 0;
      } else {
        cout << a << b << ":"
             << "0" << d;
        return 0;
      }
    }
    if (f > 12) {
      if (g <= 59) {
        a = 0;
        if (b == 0) a = 1;
        cout << "0" << b << ":" << c << d;
        return 0;
      } else {
        a = 0;
        if (b == 0) a = 1;
        cout << "0" << b << ":"
             << "0" << d;
        return 0;
      }
    }
  }
  if (n == 24) {
    if (f < 24) {
      if (g <= 59) {
        cout << a << b << ":" << c << d;
        return 0;
      } else {
        cout << a << b << ":"
             << "0" << d;
        return 0;
      }
    } else {
      if (g <= 59) {
        cout << "0" << b << ":" << c << d;
        return 0;
      } else {
        cout << "0" << b << ":"
             << "0" << d;
        return 0;
      }
    }
  }
}
