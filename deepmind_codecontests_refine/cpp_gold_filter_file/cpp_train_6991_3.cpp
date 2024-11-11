#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z;
  cin >> x >> y >> z;
  int v = x - y;
  if (v == 0) {
    if (z == 0) {
      cout << 0 << endl;
    } else {
      cout << "?" << endl;
    }
  } else if (v > 0) {
    if (v > z) {
      cout << "+" << endl;
    } else {
      cout << "?" << endl;
    }
  } else {
    if (abs(v) > z) {
      cout << "-" << endl;
    } else {
      cout << "?" << endl;
    }
  }
  return 0;
}
