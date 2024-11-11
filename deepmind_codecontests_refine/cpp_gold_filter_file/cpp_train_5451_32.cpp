#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int ans = 0;
  int x, y, z, x1, y1, z1, a1, a2, a3, a4, a5, a6;
  cin >> x >> y >> z >> x1 >> y1 >> z1 >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
  if (y > y1) ans += a2;
  if (y < 0) ans += a1;
  if (x > x1) ans += a6;
  if (x < 0) ans += a5;
  if (z > z1) ans += a4;
  if (z < 0) ans += a3;
  cout << ans;
  return 0;
}
