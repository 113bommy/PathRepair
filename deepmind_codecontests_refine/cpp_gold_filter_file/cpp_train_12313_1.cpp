#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int a, x, y;
  cin >> a >> x >> y;
  if (y % a == 0) return cout << -1, 0;
  long long int z = y / a;
  if (z == 0 || z == 1 || z & 1) {
    if (abs(x) >= a / 2.0) return cout << -1, 0;
    z--;
    cout << (z + z / 2 + 2);
  } else {
    if (abs(x) >= a || x == 0) return cout << -1, 0;
    if (x < 0)
      cout << (z + z / 2);
    else
      cout << (z + z / 2 + 1);
  }
}
