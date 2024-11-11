#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x;
  cin >> x;
  x %= 360;
  if (x <= 45 && x >= -45) cout << 0;
  if (x > 45 && x <= 135) cout << 1;
  if (x > 135 && x <= 225) cout << 2;
  if (x > 225 && x < 315) cout << 3;
  if (x >= 315 && x < 360) cout << 0;
  if (x < -45 && x >= -135) cout << 3;
  if (x < -135 && x >= -225) cout << 2;
  if (x < -225 && x > -315) cout << 1;
  if (x <= -315) cout << 0;
  return 0;
}
