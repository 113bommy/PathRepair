#include <bits/stdc++.h>
using namespace std;
int64_t mod = 1e9 + 7, inf = 4e18;
int64_t bruteForce(string &s) {
  for (int64_t i = 1; i <= 10; i++) {
    for (int64_t j = 0; j < (1 << i); j++) {
      string cur = "";
      for (int64_t k = 0; k < i; k++) cur += (j & (1 << k)) ? "1" : "0";
      if (s.find(cur) == -1) return i - 1;
    }
  }
}
int32_t main() {
  ios::sync_with_stdio(false), cin.tie(nullptr);
  cout << fixed << setprecision(0);
  int64_t n, m;
  cin >> n;
  vector<int64_t> ans(n);
  vector<string> s(n);
  for (int64_t i = 0; i < int64_t(n); ++i) {
    cin >> s[i];
    ans[i] = bruteForce(s[i]);
  }
  int64_t l, r, ind = 0;
  for (cin >> m; m--; cout << ans.back() << endl) {
    cin >> l >> r;
    l--, r--;
    s.push_back(s[l] + s[r]);
    if (s.back().size() > 1000) {
      s.back() =
          s.back().substr(0, 500) + s.back().substr(s.back().size() - 501, 500);
    }
    ans.push_back(max(bruteForce(s.back()), max(ans[l], ans[r])));
  }
  return 0;
}
