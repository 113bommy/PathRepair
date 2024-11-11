#include <bits/stdc++.h>
const long long MOD = 1000000007;
const int MAX = 1e9 + 7;
const int MIN = -1e9 + 7;
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long x, y, z;
  cin >> x >> y >> z;
  long long ans = (x + y) / z;
  long long cnt = ((x % z) + (y % z) >= z) ? min(y % z, x % z) : 0;
  cout << ans << " " << min(cnt, z - max(y % z, x % z));
  return 0;
}
