#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  string s;
  cin >> s;
  int i, j, n = s.size();
  vector<int> v;
  v.clear();
  int cr = 0, ind;
  for (i = 0; i < n; ++i) {
    if (s[i] == '(')
      ++cr;
    else {
      --cr;
      if (s[i] == '#') ind = i, v.push_back(1);
    }
    if (cr < 0) {
      cout << -1;
      return 0;
    }
  }
  v[v.size() - 1] += cr;
  cr = 0;
  for (i = 0; i < n; ++i) {
    if (s[i] == '(')
      ++cr;
    else if (i == ind)
      cr -= v[v.size() - 1];
    else
      --cr;
    if (cr < 0) {
      cout << -1;
      return 0;
    }
  }
  if (cr != 0) {
    cout << -1;
    return 0;
  }
  for (auto it : v) cout << it << '\n';
  return 0;
}
