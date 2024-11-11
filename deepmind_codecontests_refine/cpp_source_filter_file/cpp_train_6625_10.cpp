#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
string s1, s2;
map<char, vector<int>> mp1, mp2;
int next(int idx, char c) {
  auto it = upper_bound(mp1[c].begin(), mp1[c].end(), idx);
  if (it == mp1[c].end()) return s1.size();
  int ret_idx = it - mp1[c].begin();
  return mp1[c][ret_idx];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> s1 >> s2;
  for (int i = 0; i < s1.size(); ++i) {
    mp1[s1[i]].push_back(i);
  }
  for (int i = 0; i < s2.size(); ++i) mp2[s2[i]].push_back(i);
  for (auto i : mp2)
    if (!mp1.count(i.first)) {
      cout << -1;
      return 0;
    }
  int ans = 0;
  int t = -1;
  for (int i = 0; i < s2.size(); ++i) {
    if (false)
      cerr << "i"
           << " = " << i << " | "
           << "t"
           << " = " << t << "\n";
    ;
    t = next(t, s2[i]);
    if (t >= s1.size()) {
      ans++;
      t = -1;
      i--;
    }
  }
  if (t) ans++;
  cout << ans << "\n";
}
