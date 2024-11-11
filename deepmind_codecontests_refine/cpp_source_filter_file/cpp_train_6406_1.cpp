#include <bits/stdc++.h>
using namespace std;
bool two[10005] = {0};
bool three[10005] = {0};
int main() {
  string s;
  cin >> s;
  set<string> ans;
  two[s.size()] = three[s.size()] = 1;
  for (int i = s.size() - 2; i >= 5; i--) {
    string p = string(1, s[i]) + string(1, s[i + 1]);
    if (three[i + 2]) {
      ans.insert(p);
      two[i] = 1;
    } else if (two[i + 2] && p != string(1, s[i + 2]) + string(1, s[i + 3])) {
      ans.insert(p);
      two[i] = 1;
    }
    p = string(1, s[i]) + string(1, s[i + 1]) + string(1, s[i + 2]);
    if (two[i + 3]) {
      ans.insert(p);
      three[i] = 1;
    } else if (three[i + 3] && p != string(1, s[i + 3]) + string(1, s[i + 4]) +
                                        string(i, s[1 + 5])) {
      three[i] = 1;
      ans.insert(p);
    }
  }
  cout << ans.size() << '\n';
  for (string s : ans) cout << s << '\n';
}
