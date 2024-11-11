#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  vector<string> v;
  int i;
  string s1("");
  for (i = 0; i <= s.size(); i++) {
    if (s[i] == '.' || i == s.size()) {
      v.push_back(s1);
      s1.clear();
    } else {
      s1.push_back(s[i]);
    }
  }
  if (v[0].size() > 11 || v.size() == 1 || s[0] == '.' ||
      s[s.size() - 1] == '.' || v[v.size() - 1].size() > 3) {
    printf("NO\n");
    return 0;
  }
  i = 1;
  vector<string> ans;
  string s2 = v[0];
  while (i < v.size()) {
    s2 += ".";
    int idx;
    if (v[i].size() > 11 && v[i].size() < 2) {
      printf("NO\n");
      return 0;
    }
    if (i != v.size() - 1) {
      for (idx = 1; idx <= 3; idx++) {
        if (v[i].size() - idx >= 1 && v[i].size() - idx <= 8) {
          goto p1;
        }
      }
    } else {
      idx = v[i].size();
      goto p1;
    }
    printf("NO\n");
    return 0;
  p1 : {}
    string p = v[i];
    s2 += p.substr(0, idx);
    ans.push_back(s2);
    s2 = p.substr(idx, p.size() - idx);
    i++;
  }
  printf("YES\n");
  for (i = 0; i < ans.size(); i++) cout << ans[i] << endl;
  return 0;
}
