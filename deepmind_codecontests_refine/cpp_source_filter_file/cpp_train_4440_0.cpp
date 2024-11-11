#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, g, b;
  cin >> r >> g >> b;
  r = (r + 1) / 2 - 1;
  g = (g + 1) / 2 - 1;
  b = (b + 1) / 2 - 1;
  r = 3 * r + 0;
  g = 3 * g + 1;
  b = 3 * b + 2;
  int res = min(min(r, g), b) + 30;
  cout << res;
}
