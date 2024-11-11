#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int64_t n;
  string s;
  cin >> n >> s;
  vector<int64_t> ans, ans2;
  string s2 = s;
  bool ok = false, ok2 = false;
  map<char, char> m = {{'B', 'W'}, {'W', 'B'}};
  for (int64_t i = 0; i < n - 1; ++i) {
    if (s[i] == 'B' or ok) {
      ok = true;
      if (s[i + 1] == 'B') ok = false;
      s[i] = m[s[i]];
      s[i + 1] = m[s[i + 1]];
      ans.emplace_back(i);
    }
    if (s2[i] == 'W' or ok2) {
      ok2 = true;
      if (s2[i + 1] == 'W') ok2 = false;
      s2[i] = m[s2[i]];
      s2[i + 1] = m[s2[i + 1]];
      ans2.emplace_back(i);
    }
  }
  if (!ok and s[n - 1] != 'B') {
    cout << ans.size() << '\n';
    for (auto i : ans) cout << i << ' ';
  } else if (!ok2 and s2[n - 1] != 'W') {
    cout << ans2.size() << '\n';
    for (auto i : ans2) cout << i << ' ';
  } else
    cout << -1;
  return 0;
}
