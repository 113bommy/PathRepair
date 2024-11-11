#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  long long a, b, x, y, z;
  cin >> a >> b;
  cin >> x >> y >> z;
  int need[2];
  need[0] = need[1] = 0;
  need[0] += x + x;
  need[0] += y;
  need[1] += y;
  need[1] += z + z + z;
  long long ans = 0;
  if (a < need[0]) {
    ans += need[0] - a;
  }
  if (b < need[1]) {
    ans += need[1] - b;
  }
  cout << ans << endl;
  return 0;
}
