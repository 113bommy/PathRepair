#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  string s;
  cin >> s;
  vector<pair<char, int>> v;
  vector<char> smh;
  int n = s.length();
  vector<pair<int, string>> ans(n);
  for (int i = n - 1; i >= 0; --i) {
    v.push_back({s[i], i});
    if (v.size() == 1)
      smh.push_back(0);
    else if (v.end()[-2].first != v.end()[-1].first)
      smh.push_back(v.end()[-2].first);
    else {
      char ch = smh.end()[-1];
      smh.push_back(ch);
    }
    {
      if (v.size() > 1 && v.end()[-1].first == v.end()[-2].first &&
          v.end()[-2].second - v.end()[-1].second == 1) {
        if (v.size() == 2 || v.end()[-3].first < v.end()[-1].first ||
            (v.end()[-3].first == v.end()[-1].first &&
             smh.end()[-3] < v.end()[-1].first))
          v.pop_back(), v.pop_back(), smh.pop_back(), smh.pop_back();
      }
    }
    if (v.size() <= 10) {
      for (auto j : v) ans[i].second += j.first;
      reverse(ans[i].second.begin(), ans[i].second.end());
    } else {
      for (int j = -1; j >= -5; --j) ans[i].second += v.end()[j].first;
      ans[i].second += "...";
      ans[i].second += v[1].first;
      ans[i].second += v[0].first;
    }
    ans[i].first = v.size();
  }
  for (auto i : ans) cout << i.first << " " << i.second << "\n";
  return 0;
}
