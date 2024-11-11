#include <bits/stdc++.h>
using namespace std;
int n, m, k, TC;
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int x, xc, y, yc, z, zc;
  cin >> x >> y >> z;
  cin >> xc >> yc >> zc;
  int a1, a2, a3, a4, a5, a6;
  cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
  long long ans = 0;
  if (y < 0) ans += a1;
  if (y > yc) ans += a2;
  if (z < 0) ans += a3;
  if (z > zc) ans += a4;
  if (x < 0) ans += a5;
  if (x > xc) ans += a6;
  cout << ans << endl;
  return 0;
}
