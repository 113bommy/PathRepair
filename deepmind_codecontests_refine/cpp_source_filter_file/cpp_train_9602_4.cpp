#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  long long n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  long long tot = 0;
  vector<vector<long long>> ans;
  while (1) {
    ans.push_back({});
    for (long long i = 0; i < n - 1; ++i) {
      if (s[i] == 'R' && s[i + 1] == 'L') {
        ans.back().push_back(i);
        ++tot;
      }
    }
    for (auto j : ans.back()) {
      swap(s[j], s[j + 1]);
    }
    if (ans.back().size() == 0) {
      ans.pop_back();
      break;
    }
  }
  if (k < ans.size() || k > tot) {
    cout << -1;
    return 0;
  }
  for (long long i = 0; i < ans.size(); ++i) {
    while (ans.size() > k && ans[i].size() > 1) {
      --k;
      cout << "1 " << ans[i].back() + 1 << '\n';
      ans[i].pop_back();
    }
    cout << ans[i].size() << ' ';
    for (auto x : ans[i]) {
      cout << (x + 1) << ' ';
    }
    cout << '\n';
  }
}
