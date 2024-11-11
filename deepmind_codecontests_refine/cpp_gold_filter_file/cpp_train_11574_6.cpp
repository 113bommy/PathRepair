#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> v(n);
  for (auto &&x : v) cin >> x;
  unordered_map<char, int> vvl;
  vvl['a'] = 1;
  vvl['e'] = 1;
  vvl['i'] = 1;
  vvl['o'] = 1;
  vvl['u'] = 1;
  vector<pair<pair<int, char>, string>> vv;
  for (auto &&s : v) {
    int count = 0;
    char last;
    for (auto &&c : s) {
      if (vvl[c]) {
        count++;
        last = c;
      }
    }
    vv.push_back({{count, last}, s});
  }
  sort(vv.begin(), vv.end());
  vector<pair<string, string>> one, two;
  bool vis[n];
  memset(vis, 0, sizeof(vis));
  for (int i = 0; i < n - 1; ++i) {
    if (vv[i].first == vv[i + 1].first) {
      two.push_back({vv[i].second, vv[i + 1].second});
      vis[i] = 1;
      vis[i + 1] = 1;
      i++;
    }
  }
  for (int i = 0; i < n - 1; ++i) {
    if (vis[i])
      continue;
    else {
      int j = i + 1;
      while (vv[i].first.first == vv[j].first.first) {
        if (!vis[j]) {
          one.push_back({vv[i].second, vv[j].second});
          vis[j] = 1;
          break;
        } else
          j++;
      }
      i = j - 1;
    }
  }
  if (one.size() >= two.size()) {
    cout << two.size() << '\n';
    for (int i = 0; i < two.size(); ++i) {
      cout << one[i].first << " " << two[i].first << '\n';
      cout << one[i].second << " " << two[i].second << '\n';
    }
  } else {
    int x = one.size() + (two.size() - one.size()) / 2;
    cout << x << '\n';
    int i = 0;
    for (; i < one.size(); ++i) {
      cout << one[i].first << " " << two[i].first << '\n';
      cout << one[i].second << " " << two[i].second << '\n';
    }
    for (; i < two.size() && i + 1 < two.size(); i += 2) {
      cout << two[i].first << " " << two[i + 1].first << '\n';
      cout << two[i].second << " " << two[i + 1].second << '\n';
    }
  }
}
