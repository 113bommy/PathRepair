#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios_base::sync_with_stdio(false);
  int64_t Q;
  cin >> Q;
  for (int64_t q = 0; q < Q; ++q) {
    int64_t n, a, b;
    cin >> n >> a >> b;
    string str;
    cin >> str;
    bool bl = true;
    for (int64_t i = 0; i < str.size(); ++i) {
      if (str[i] == '1') {
        bl = false;
        break;
      }
    }
    if (bl) {
      cout << (n + 1) * b + a * n;
      continue;
    }
    vector<pair<int64_t, int64_t> > v;
    int64_t len = 0;
    for (int64_t i = 0; i < str.size(); ++i) {
      if (str[i] == '0')
        ++len;
      else {
        if (len) {
          v.push_back({i - len, i - 1});
          len = 0;
        }
      }
    }
    v.push_back({str.size() - len, str.size() - 1});
    int64_t ans =
        (v[v.size() - 1].first - v[0].second + n + 1) * b + (n + 2) * a;
    for (int64_t i = 1; i < v.size() - 1; ++i) {
      int64_t now = (v[i].second - v[i].first) * b;
      int64_t canbe = a * 2;
      if (canbe < now) ans = ans - now + canbe;
    }
    cout << ans << endl;
  }
}
