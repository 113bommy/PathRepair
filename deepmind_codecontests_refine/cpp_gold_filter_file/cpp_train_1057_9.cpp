#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x, y, z;
  cin >> x >> y >> z;
  long long numx = x / z, numy = y / z;
  x -= numx * z;
  y -= numy * z;
  if (x + y < z) {
    cout << numx + numy << " " << 0 << endl;
  } else {
    long long give = min(z - x, z - y);
    cout << numx + numy + 1 << " " << give << endl;
  }
  return 0;
}
