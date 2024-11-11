#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, y, z;
  int x1, y1, z1;
  cin >> x >> y >> z;
  cin >> x1 >> y1 >> z1;
  int a[6];
  int ans(0);
  for (int i(0); i < 6; ++i) cin >> a[i];
  if (z > z1) ans += a[3];
  if (z < 0) ans += a[2];
  if (x < 0) ans += a[4];
  if (x > x1) ans += a[5];
  if (y > y1) ans += a[1];
  if (y < 0) ans += a[0];
  cout << ans << endl;
  return 0;
}
