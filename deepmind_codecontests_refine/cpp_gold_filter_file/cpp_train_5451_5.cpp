#include <bits/stdc++.h>
using namespace std;
int x, y, z;
int _x, _y, _z;
int a[6];
long long int ans = 0LL;
int main() {
  ios::sync_with_stdio(false);
  cin >> x >> y >> z;
  cin >> _x >> _y >> _z;
  for (int i = 0; i < 6; i++) cin >> a[i];
  if (y < 0) ans += a[0];
  if (y > _y) ans += a[1];
  if (z < 0) ans += a[2];
  if (z > _z) ans += a[3];
  if (x < 0) ans += a[4];
  if (x > _x) ans += a[5];
  cout << ans;
  return 0;
}
