#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4 + 17;
const int MOD = 1e9 + 17;
int main(int argc, char const *argv[]) {
  set<int> s0, s1;
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); ++i) {
    if (str[i] == '0')
      s0.insert(i);
    else
      s1.insert(i);
  }
  vector<vector<int> > ans;
  bool can = true;
  while (!s1.empty() && can) {
    if (s0.empty()) {
      can = false;
      break;
    }
    int st = *s0.begin();
    s0.erase(st);
    vector<int> tmp;
    tmp.push_back(st);
    int k = 1;
    while (1) {
      if (k == 1) {
        if (s1.upper_bound(st) != s1.end()) {
          st = *s1.upper_bound(st);
          tmp.push_back(st);
          s1.erase(st);
          k = 0;
        } else
          break;
      }
      if (k == 0) {
        if (s0.upper_bound(st) != s0.end()) {
          st = *s0.upper_bound(st);
          tmp.push_back(st);
          s0.erase(st);
          k = 1;
        } else {
          can = false;
          break;
        }
      }
    }
    ans.push_back(tmp);
  }
  while (!s0.empty()) {
    vector<int> tmp;
    tmp.push_back(*s0.begin());
    s0.erase(s0.begin());
    ans.push_back(tmp);
  }
  if (!can) return cout << -1 << endl, 0;
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); ++i) {
    cout << ans[i].size() << " ";
    for (int j = 0; j < ans[i].size(); ++j) {
      cout << ans[i][j] << " ";
    }
    cout << endl;
  }
  return 0;
}
