#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, g, b, max = 0, min = 0;
  cin >> r >> g >> b;
  max = r / 3 + g / 3 + b / 3;
  if (r == 0 || g == 0 || b == 0) {
  } else {
    r = r % 3;
    g = g % 3;
    b = b % 3;
    if (r * b * g == 0 && (r + b + g) == 4) max++;
    min = r;
    if (min < g) min = g;
    if (min < b) min = b;
    max = max + min;
  }
  cout << max;
  return 0;
}
