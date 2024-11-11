#include <bits/stdc++.h>
using namespace std;
bool big(char c) { return (c >= 'A' && c <= 'Z'); }
signed main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int mx = 0;
  for (int i = 0; i < n; ++i) {
    if (big(s[i])) continue;
    bool used[27];
    for (int j = 0; j < 27; ++j) used[j] = false;
    int cnt = 0;
    for (int j = i; j < n; ++j) {
      if (big(s[j])) break;
      if (!used[s[j] - 'a']) {
        ++cnt;
        used[s[j] - 'a'] = true;
      }
      mx = max(mx, cnt);
    }
  }
  cout << mx << endl;
  return 0;
}
