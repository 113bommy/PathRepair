#include <bits/stdc++.h>
using namespace std;
long long x, y, z, r;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> x >> y >> z;
  r = (x + y) / z;
  if (x / z + y / z == r)
    cout << r << ' ' << 0;
  else
    cout << r << ' ' << min(x % z, y % z);
}
