#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void solve() {
  string s;
  cin >> s;
  string t = s;
  reverse(t.begin(), t.end());
  if (s == t) {
    cout << int(s.size()) - 1;
  } else {
    while (s.size()) {
      s.erase(int(s.size()) - 1, 1);
      t = s;
      reverse(t.begin(), t.end());
      if (s != t) {
        cout << int(s.size());
        return;
      }
    }
    cout << 0;
  }
}
signed main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  while (t--) {
    solve();
  }
}
