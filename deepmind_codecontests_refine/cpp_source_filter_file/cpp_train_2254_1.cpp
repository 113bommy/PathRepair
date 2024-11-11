#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
const int MOD = 1e9 + 7;
void sm(string &s, int x) {
  for (int i = x + 1; i < s.size(); ++i) s[i] = '9';
  for (int i = x; i >= 0; --i) {
    if (s[i] == '0')
      s[i] = '9';
    else {
      s[i]--;
      break;
    }
  }
  if (s[0] == '0') s.erase(s.begin());
}
void solve() {
  string s, ans;
  cin >> s;
  int n = s.size();
  sm(s, n - 1);
  n = s.size();
  if (n % 2) {
    for (int i = 1; i < n; ++i) {
      cout << '9';
    }
    return;
  }
  if (s[0] == '1') {
    bool f = true;
    for (int i = 1; i < n; ++i) {
      if (s[i] != '0') f = false;
    }
    if (f) {
      for (int i = 2; i < n; ++i) {
        cout << '9';
      }
      return;
    }
  }
  for (int z = 0; z < 3; ++z) {
    ans.clear();
    for (int i = 0; i < n; ++i) ans.push_back('a');
    set<char, greater<char>> t;
    int i = 0, del = 0;
    for (; i < n; ++i) {
      if (t.find(s[i]) != t.end())
        t.erase(s[i]), del += 2;
      else {
        if (2 * t.size() >= (n - del)) break;
        t.insert(s[i]);
      }
      ans[i] = s[i];
    }
    if (t.empty()) {
      cout << s;
      return;
    }
    bool f = false;
    for (; i < n; ++i) {
      for (auto &it : t) {
        if (f || it <= s[i]) {
          if (it != s[i]) f = true;
          ans[i] = it;
          break;
        }
      }
      if (ans[i] == 'a') {
        sm(s, i - 1);
        n = s.size();
        break;
      }
      t.erase(ans[i]);
    }
  }
  cout << ans;
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
    cout << "\n";
  }
  return 0;
}
