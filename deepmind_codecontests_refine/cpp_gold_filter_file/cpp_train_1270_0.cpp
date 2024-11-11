#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int main() {
  map<int, int> mp;
  int t;
  cin >> t;
  while (t--) {
    int n;
    mp.clear();
    cin >> n;
    int ans = inf;
    for (int i = 0; i < n; i++) {
      int val;
      cin >> val;
      if (mp.count(val) != 0) {
        ans = min(ans, i - mp[val]);
      }
      mp[val] = i;
    }
    if (ans == inf)
      cout << -1 << endl;
    else
      cout << ans + 1 << endl;
  }
  return 0;
}
