#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int n;
  string s;
  cin >> s;
  n = (int)s.size();
  vector<int> R(26, -1);
  for (int i = 0; i < n; i++) {
    R[s[i] - 'a'] = max(R[s[i] - 'a'], i);
  }
  string t, u;
  int cur = 0;
  for (int i = 0; i < 26; i++) {
    while (!t.empty() && t.back() - 'a' <= i) {
      u.push_back(t.back());
      t.pop_back();
    }
    for (int j = cur; j <= R[i]; j++) {
      if (s[j] - 'a' == i) {
        u.push_back(s[j]);
      } else {
        t.push_back(s[j]);
      }
    }
    cur = max(cur, R[i] + 1);
  }
  while (!t.empty()) {
    u.push_back(t.back());
    t.pop_back();
  }
  cout << u;
  return 0;
}
