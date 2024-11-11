#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 9;
bool check(string &s, string lan) {
  if (s.size() >= lan.size()) {
    if (s.substr(s.size() - lan.size(), lan.size()) == lan) return 1;
  }
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s, c;
    cin >> s >> c;
    int n = s.size(), m = c.size();
    bool can = (s < c);
    if (!can) {
      for (int i = (int)(0); i < (int)(n); ++i) {
        int ind = 0;
        char mc = (char)('z' + 1);
        for (int j = (int)(i + 1); j < (int)(n); ++j) {
          if (s[j] <= mc) {
            mc = s[j];
            ind = j;
          }
        }
        if (mc != (char)('z' + 1)) {
          swap(s[i], s[ind]);
          if (s < c) {
            can = 1;
            break;
          }
          swap(s[i], s[ind]);
        }
      }
    }
    if (s < c)
      cout << s << '\n';
    else
      cout << "---" << '\n';
  }
  return 0;
}
