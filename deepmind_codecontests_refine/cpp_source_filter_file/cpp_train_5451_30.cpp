#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse4")
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long x, y, z, x1, y1, z1, ans = 0;
  cin >> x >> y >> z;
  cin >> x1 >> y1 >> z1;
  long long i, a[10];
  for (i = 1; i <= 6; i++) cin >> a[i];
  if (x > x1) ans += a[6];
  if (x < 0) ans += a[5];
  if (y > y1) ans += a[2];
  if (y < 0) ans += a[1];
  if (z > z1) ans += a[4];
  if (x < 0) ans += a[3];
  cout << ans;
  return 0;
}
