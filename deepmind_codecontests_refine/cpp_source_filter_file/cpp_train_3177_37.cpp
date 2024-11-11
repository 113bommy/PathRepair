#include <bits/stdc++.h>
using namespace std;
int a, b, c, x, y, z;
int main() {
  cin >> a >> b >> c >> x >> y >> z;
  while (a < x) {
    if (b - 2 >= y) {
      b -= 2;
      ++a;
      continue;
    }
    if (c - 2 >= z) {
      c -= 2;
      ++a;
    }
    if (a - 2 < x && b - 2 < y) {
      break;
    }
  }
  while (b < y) {
    if (a - 2 >= x) {
      a -= 2;
      ++b;
      continue;
    }
    if (c - 2 >= z) {
      c -= 2;
      ++b;
    }
    if (a - 2 < x && b - 2 < y) {
      break;
    }
  }
  while (c < z) {
    if (b - 2 >= y) {
      b -= 2;
      ++c;
      continue;
    }
    if (a - 2 >= x) {
      a -= 2;
      ++c;
    }
    if (a - 2 < x && b - 2 < y) {
      break;
    }
  }
  if (a >= x && b >= y && c >= z) {
    cout << "Yes";
  } else {
    cout << "No";
  }
  return 0;
}
