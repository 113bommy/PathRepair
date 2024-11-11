#include <bits/stdc++.h>
using namespace std;
int main() {
  int a[100] = {}, b = 0, c, d, x, y, i, max = -1, f = 0;
  cin >> x >> y;
  for (i = 1; i <= 10; i++) {
    cin >> c;
    a[c]++;
  }
  for (i = 1; i <= 100; i++) {
    if (a[i] > max) max = a[i];
    if (a[i] != 0) f++;
  }
  if (max % y == 0)
    b = max / y;
  else
    b = max / y + 1;
  cout << b * y * f - x;
}
