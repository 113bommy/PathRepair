#include <bits/stdc++.h>
using namespace std;
const double sin60 = sqrt(3.0) / 2;
int main() {
  int h, r;
  cin >> r >> h;
  if (h < r / 2.0) {
    cout << 1;
  } else if (h >= r / 2.0 && h < sin60 * r) {
    cout << 2;
  } else {
    int t = (h - sin60 * r) / r;
    int s = 2 * t + 3;
    if (h >= 2 * sin60 * r + t * r) {
      s += 1;
    }
    cout << s;
  }
  return 0;
}
