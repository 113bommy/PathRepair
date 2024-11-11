#include <bits/stdc++.h>
using namespace std;
long long mod = 1000000007LL;
long long large = 2000000000000000000LL;
int main() {
  ios::sync_with_stdio(false);
  mod = 998244353LL;
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    set<pair<int, int> > a;
    vector<int> comp(n, -1);
    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      x--;
      a.insert(pair<int, int>(i, x));
      comp[x] = i;
    }
    vector<int> b(k, 0);
    for (int i = 0; i < k; i++) {
      cin >> b[i];
      b[i]--;
    }
    set<int> bb;
    for (int i = 0; i < k; i++) bb.insert(b[i]);
    bb.insert(-1);
    long long ans = 1;
    for (int i = 0; i < k; i++) {
      int x = b[i];
      set<pair<int, int> >::iterator it =
          a.upper_bound(pair<int, int>(comp[x], -1));
      int l = -1, r = -1;
      if (it != a.begin()) {
        it--;
        l = (*it).second;
        it++;
      }
      it++;
      if (it != a.end()) {
        r = (*it).second;
      }
      it--;
      if (bb.count(l)) swap(l, r);
      if (bb.count(l)) {
        ans = 0;
        break;
      }
      a.erase(pair<int, int>(comp[l], l));
      bb.erase(x);
      if (bb.count(r) == 0) {
        ans *= 2;
        ans %= mod;
      }
    }
    cout << ans << endl;
  }
  return 0;
}
