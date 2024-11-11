#include <bits/stdc++.h>
using namespace std;
int a[7];
int x, y, z;
int xa, ya, za;
int ans;
int main() {
  cin >> x >> y >> z;
  cin >> xa >> ya >> za;
  for (int i = 1; i <= 6; i++) cin >> a[i];
  if (xa <= x) ans += a[6];
  if (0 > x) ans += a[5];
  if (za <= z) ans += a[4];
  if (0 > z) ans += a[3];
  if (ya <= y) ans += a[2];
  if (0 > y) ans += a[1];
  cout << ans;
  return 0;
}
