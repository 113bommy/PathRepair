#include <bits/stdc++.h>
using namespace std;
const long long N = 100 + 7;
const long long INF = 1e9;
const long long mod = 1e9 + 7;
long long x;
long long y;
long long z;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> x >> y >> z;
  long long ans = x / z + y / z;
  x %= z, y %= z;
  if (x + y >= z) {
    cout << ans + 1 << " " << min(z - x, z - y);
  } else {
    cout << ans << " " << 0;
  }
}
