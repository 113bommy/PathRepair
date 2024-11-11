#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c, i = 0;
  cin >> a >> b >> c;
  int x, y, z;
  cin >> x >> y >> z;
  if (a < x) {
    if (b > y) {
      while (b > y + 1 && a < x) {
        a++;
        b -= 2;
      }
    }
    if (c > z) {
      while (c > z + 1 && a < x) {
        a++;
        c -= 2;
      }
    }
  }
  if (b < y) {
    if (a > x) {
      while (a > x + 1 && b < y) {
        b++;
        a -= 2;
      }
    }
    if (c > z) {
      while (c > z + 1 && b < y) {
        b++;
        c -= 2;
      }
    }
  }
  if (c < z) {
    if (a > x) {
      while (a > x + 1 && c < z) {
        c++;
        a -= 2;
      }
    }
    if (b > y) {
      while (b > y + 1 && c < z) {
        c++;
        b -= 2;
      }
    }
  }
  if (a >= x && b >= y && c >= z) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
