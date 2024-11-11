#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s, a, b;
  cin >> s >> a >> b;
  auto check = [&](string s) {
    int sz_a = (int)a.size();
    for (int i = 0; i < (int)s.size() - sz_a; ++i) {
      string t(s.begin() + i, s.begin() + i + sz_a);
      if (a == t) {
        string ss(s.begin() + i + sz_a, s.end());
        if (ss.find(b) != string::npos) {
          return true;
        }
      }
    }
    return false;
  };
  pair<int, int> ans;
  ans.first = check(s);
  reverse(s.begin(), s.end());
  ans.second = check(s);
  if (ans.first && ans.second) {
    cout << "both" << '\n';
  } else if (!ans.first && !ans.second) {
    cout << "fantasy" << '\n';
  } else {
    cout << (ans.first ? "forward" : "backward") << '\n';
  }
  return 0;
}
