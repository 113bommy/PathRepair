#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int ans = 0;
  int x, y, z, x1, y1, z1, a1, a2, a3, a4, a5, a6;
  cin >> x >> y >> z >> x1 >> y1 >> z1 >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
  if (y > y1) ans += a1;
  if (y < 0) ans += a2;
  if (x > x1) ans += a3;
  if (x < 0) ans += a4;
  if (z > z1) ans += a5;
  if (z < 0) ans += a6;
  cout << ans;
  return 0;
}
