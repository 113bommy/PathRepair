#include <bits/stdc++.h>
using namespace std;
map<long long, int> mp;
int main() {
  long long q, op, u, v, w, ans;
  for (cin >> q; q--;) {
    cin >> op >> u >> v;
    if (op == 1) {
      cin >> w;
      while (u != v) {
        if (u < v) swap(u, v);
        mp[u] = mp[u] + w;
        u /= 2;
      }
    } else {
      ans = 0;
      while (u != v) {
        if (u < v) swap(u, v);
        ans += mp[u];
        u /= 2;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
