#include <bits/stdc++.h>
using namespace std;
int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  string l;
  l.reserve(n);
  cin >> l;
  string r;
  r.reserve(n);
  cin >> r;
  vector<int> lc[26] = {};
  vector<int> la;
  vector<int> rc[26] = {};
  vector<int> ra;
  for (int i = 0; i < n; i++) {
    char c = l[i];
    if (c == '?') {
      la.push_back(i);
    } else {
      lc[c - 'a'].push_back(i);
    }
  }
  for (int i = 0; i < n; i++) {
    char c = r[i];
    if (c == '?') {
      ra.push_back(i);
    } else {
      rc[c - 'a'].push_back(i);
    }
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i < 26; i++) {
    for (int j = 0, k = min(lc[i].size(), rc[i].size()); j < k; j++) {
      int p = lc[i].back();
      lc[i].pop_back();
      int q = rc[i].back();
      rc[i].pop_back();
      ans.push_back({p, q});
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0, k = min(lc[i].size(), ra.size()); j < k; j++) {
      int p = lc[i].back();
      lc[i].pop_back();
      int q = ra.back();
      ra.pop_back();
      ans.push_back({p, q});
    }
  }
  for (int i = 0; i < 26; i++) {
    for (int j = 0, k = min(rc[i].size(), la.size()); j < k; j++) {
      int p = rc[i].back();
      rc[i].pop_back();
      int q = la.back();
      la.pop_back();
      ans.push_back({p, q});
    }
  }
  for (int j = 0, k = min(la.size(), ra.size()); j < k; j++) {
    int p = la.back();
    la.pop_back();
    int q = ra.back();
    ra.pop_back();
    ans.push_back({p, q});
  }
  cout << ans.size() << '\n';
  for (auto p : ans) {
    cout << (p.first + 1) << ' ' << (p.second + 1) << '\n';
  }
}
