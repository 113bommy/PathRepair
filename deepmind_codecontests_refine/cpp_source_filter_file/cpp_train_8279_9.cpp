#include <bits/stdc++.h>
using namespace std;
map<pair<long long, long long>, long> mp;
int main() {
  int q, n;
  long long u, v, w, a, b, ans;
  cin >> q;
  while (q--) {
    cin >> n;
    if (n == 1) {
      cin >> u >> v >> w;
      a = 1;
      while (u != v) {
        if (u > v) {
          a = u / 2;
          mp[make_pair(a, u)] += w;
          u = a;
        } else {
          a = v / 2;
          mp[make_pair(a, v)] += w;
          v = a;
        }
      }
    } else {
      cin >> u >> v;
      ans = 0;
      while (u != v) {
        if (u > v) {
          a = u / 2;
          ans += mp[make_pair(a, u)];
          u = a;
        } else {
          a = v / 2;
          ans += mp[make_pair(a, v)];
          v = a;
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}
