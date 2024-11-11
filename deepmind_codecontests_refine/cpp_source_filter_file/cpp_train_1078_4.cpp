#include <bits/stdc++.h>
using namespace std;
int a, b, c, d, e, i;
int main() {
  cin >> a;
  if (a == 1)
    cout << "-1";
  else {
    b = a - 1;
    if (b < 7) {
      if (b == 1) cout << "-1";
      if (b == 2) cout << "210";
      if (b == 3) cout << "1050";
      if (b == 4) cout << "10080";
      if (b == 5) cout << "100170";
      if (b == 6) cout << "1000020";
    } else {
      c = b % 6;
      if (c == 1) {
        cout << 1;
        for (i = 0; i < b - 3; i++) cout << 0;
        cout << 200;
      }
      if (c == 2) {
        cout << 1;
        for (i = 0; i < b - 3; i++) cout << 0;
        cout << 110;
      }
      if (c == 3) {
        cout << 1;
        for (i = 0; i <= b - 3; i++) cout << 0;
        cout << 50;
      }
      if (c == 4) {
        cout << 1;
        for (i = 0; i <= b - 3; i++) cout << 0;
        cout << 80;
      }
      if (c == 5) {
        cout << 1;
        for (i = 0; i < b - 3; i++) cout << 0;
        cout << 310;
      }
      if (c == 0) {
        cout << 1;
        for (i = 0; i <= b - 3; i++) cout << 0;
        cout << 20;
      }
    }
  }
  return 0;
}
