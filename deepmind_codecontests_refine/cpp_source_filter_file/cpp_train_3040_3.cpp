#include <bits/stdc++.h>
using namespace std;
const int64_t N = 2e5 + 5;
const int64_t INF = 1e18 + 7;
const int64_t MOD = 1e9 + 7;
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int64_t q;
  cin >> q;
  while (q--) {
    int64_t n, k;
    cin >> n >> k;
    k--;
    string s;
    cin >> s;
    set<int64_t> v1;
    set<int64_t> v2;
    vector<pair<int64_t, int64_t>> ans;
    for (int64_t i = 0; i < n; i++) {
      if (s[i] == ')')
        v2.insert(i);
      else
        v1.insert(i);
    }
    for (int64_t i = 0; i < n; i++) {
      int64_t have = 1;
      if (i < (n - k * 2) / 2 + k * 2) have = 0;
      if (i < k * 2) have = (i % 2);
      int64_t it;
      if (s[i] == ')')
        it = 1;
      else
        it = 0;
      if (have != it) {
        int64_t pos;
        if (it == 1) {
          pos = *v1.upper_bound(i);
          v1.erase(pos);
        } else {
          pos = *v2.upper_bound(i);
          v1.erase(pos);
        }
        swap(s[pos], s[i]);
        ans.push_back({i, pos});
        if (pos - i > 2) {
          ans.push_back({i + 1, pos - 1});
        }
      }
    }
    cout << ans.size() << endl;
    for (auto x : ans) cout << x.first + 1 << " " << x.second + 1 << endl;
  }
}
