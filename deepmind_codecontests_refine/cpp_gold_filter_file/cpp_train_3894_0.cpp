#include <bits/stdc++.h>
using namespace std;
int main() {
  int r, g, b;
  cin >> r >> g >> b;
  int m = min(r, min(g, b));
  int x = (r - m) / 3 + (g - m) / 3 + (b - m) / 3 + m;
  r -= m;
  g -= m;
  b -= m;
  if (r % 3 + g % 3 + b % 3 == 4 && m > 0) x++;
  cout << x;
  return 0;
}
