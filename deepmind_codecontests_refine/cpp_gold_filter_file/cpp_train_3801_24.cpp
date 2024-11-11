#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
const ll inf = 1;
const ll mod = 1E9;
int main() {
  ios::sync_with_stdio(false);
  ll x;
  while (cin >> x) {
    vector<pll> ans;
    for (ll n = 1; n <= min(2000000LL, x); n++) {
      ll m = 6LL * x;
      m = m + (n * n * n) - n;
      if (m % (3LL * n * (n + 1LL)) == 0) {
        m /= (3LL * n * (n + 1LL));
        if (m >= n) {
          ans.push_back({n, m});
        }
      }
    }
    set<pll> ms;
    for (auto it : ans) {
      ms.insert(it);
      ms.insert({it.second, it.first});
    }
    cout << (int)ms.size() << endl;
    for (auto it : ms) {
      cout << it.first << ' ' << it.second << endl;
    }
  }
  return 0;
}
