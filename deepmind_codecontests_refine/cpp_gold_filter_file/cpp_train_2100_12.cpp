#include <bits/stdc++.h>
using namespace std;
signed main() {
  long long s, b;
  cin >> s >> b;
  vector<long long> q(s);
  for (long long i = 0; i < s; ++i) {
    cin >> q[i];
  }
  vector<pair<long long, long long>> bs(b);
  for (long long i = 0; i < b; ++i) {
    cin >> bs[i].first >> bs[i].second;
  }
  sort(bs.begin(), bs.end());
  for (long long i = 1; i < b; ++i) {
    bs[i].second += bs[i - 1].second;
  }
  for (long long i = 0; i < s; ++i) {
    auto x =
        upper_bound(bs.begin(), bs.end(), make_pair(q[i], (long long)1e18));
    if (x == bs.begin()) {
      cout << 0 << " ";
    } else {
      x--;
      cout << x->second << " ";
    }
  }
}
