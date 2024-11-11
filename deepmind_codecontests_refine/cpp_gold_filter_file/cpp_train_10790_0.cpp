#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z;
  cin >> x >> y >> z;
  while (z > 0) {
    if (x < y)
      x++, z--;
    else
      y++, z--;
  }
  if (x > y)
    cout << y * 2;
  else
    cout << x * 2;
}
