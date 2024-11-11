#include <bits/stdc++.h>
using namespace std;
vector<int> get(string &s, string &t) {
  vector<int> ans(t.size());
  for (int i = 0, j = 0; i < s.size() && j < t.size(); i++) {
    if (s[i] == t[j]) {
      ans[j++] = i + 1;
    }
  }
  return ans;
}
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, t;
  cin >> s >> t;
  vector<int> v = get(s, t);
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  vector<int> vr = get(s, t);
  int ans = s.size() - min(v[t.size() - 1], vr[t.size() - 1]);
  for (int i = 0; i + 1 < t.size(); i++) {
    ans = max<int>(ans, s.size() - v[i] - vr[t.size() - i - 2]);
  }
  cout << ans;
  return 0;
}
