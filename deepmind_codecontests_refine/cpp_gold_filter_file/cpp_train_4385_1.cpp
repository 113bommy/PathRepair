#include <bits/stdc++.h>
using namespace std;
const int infi = 1e9 + 7;
const long long infl = (long long)1e18 + (long long)7;
int32_t main() {
  cin.sync_with_stdio(false);
  cin.tie(0);
  int x, y, z, t1, t2, t3;
  cin >> x >> y >> z >> t1 >> t2 >> t3;
  int ans1 = abs(x - y) * t1;
  int ans2 = (abs(z - x) + abs(y - x)) * t2 + 3 * t3;
  if (ans2 <= ans1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
