#include <bits/stdc++.h>
using namespace std;
int main() {
  int x1, y1, z1, x, y, z, a1, a2, a3, a4, a5, a6, sum;
  cin >> x >> y >> z;
  cin >> x1 >> y1 >> z1 >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
  if (y1 > 0) {
    if (y > y1)
      sum += a2;
    else if (y < 0)
      sum += a1;
  } else {
    if (y > 0)
      sum += a2;
    else if (y < y1)
      sum += a1;
  }
  if (z1 > 0) {
    if (z > z1)
      sum += a4;
    else if (z < 0)
      sum += a3;
  } else {
    if (z > 0)
      sum += a4;
    else if (y < y1)
      sum += a3;
  }
  if (x1 > 0) {
    if (x > x1)
      sum += a6;
    else if (x < 0)
      sum += a5;
  } else {
    if (x > 0)
      sum += a6;
    else if (x < x1)
      sum += a5;
  }
  cout << sum << endl;
  return 0;
}
