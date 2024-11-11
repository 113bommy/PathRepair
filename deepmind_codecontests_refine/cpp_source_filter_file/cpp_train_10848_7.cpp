#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int zer = 0;
  if (a == 0) zer++;
  if (b == 0) zer++;
  if (c == 0) zer++;
  if (d == 0) zer++;
  int leftpairs = a;
  int rightpairs = d;
  int remaining1 = b - leftpairs;
  int remaining2 = c - rightpairs;
  if (zer <= 1) {
    if (remaining1 < 0 || remaining2 < 0 || abs(remaining1 - remaining2) > 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      if (remaining1 > remaining2 && remaining1 != 0) {
        cout << 1 << " ";
      }
      for (int i = 0; i < leftpairs; i++) {
        cout << 0 << " " << 1 << " ";
      }
      for (int i = 0; i < min(remaining1, remaining2); i++) {
        cout << "2 1 ";
      }
      for (int i = 0; i < rightpairs; i++) {
        cout << 2 << " " << 3 << " ";
      }
      if (remaining2 > remaining1) cout << 2 << endl;
    }
  } else {
    if (a + b + c + d == 1) {
      cout << "YES" << endl;
      if (a != 0) cout << 0 << endl;
      if (b != 0) cout << 1 << endl;
      if (c != 0) cout << 2 << endl;
      if (d != 0) cout << 3 << endl;
    } else if (a == 0 && b == 0) {
      if (c != 0 && d != 0 && abs(c - d) == 1) {
        cout << "YES" << endl;
        if (c > d) cout << 2 << " ";
        int k = min(c, d);
        while (k--) cout << "3 2 ";
        if (d > c) cout << 3 << endl;
      } else {
        cout << "NO" << endl;
      }
    } else if (c == 0 && d == 0) {
      if (a != 0 && b != 0 && abs(a - b) == 1) {
        cout << "YES" << endl;
        if (a > b) cout << 0 << " ";
        int k = min(a, b);
        while (k--) cout << "1 0 ";
        if (b > a) cout << 1 << endl;
      } else {
        cout << "NO" << endl;
      }
    } else if (a == 0 && d == 0) {
      if (b != 0 && c != 0 && abs(c - b) == 1) {
        cout << "YES" << endl;
        if (b > c) cout << 1 << " ";
        int k = min(c, b);
        while (k--) cout << "2 1 ";
        if (c > b) cout << 2 << endl;
      } else {
        cout << "NO" << endl;
      }
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
