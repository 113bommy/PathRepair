#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s;
  cin >> s;
  bool same = true;
  if (s.length() == 1) {
    cout << -1 << '\n';
  } else {
    for (int i = 0; i <= s.length() - 2; i++) {
      if (s[i] != s[i + 1]) {
        same = false;
        break;
      }
    }
    if (same)
      cout << -1 << '\n';
    else {
      sort(s.begin(), s.end());
      for (auto i : s) cout << i;
      cout << '\n';
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    solve();
  }
}
