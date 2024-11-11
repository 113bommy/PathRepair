#include <bits/stdc++.h>
using namespace std;
void solve() {
  string s, t;
  cin >> s;
  cin >> t;
  int ans = 1;
  for (int i = 0, j = 0; i < s.length(), j < t.length();) {
    if (s[i] == t[i]) {
      ans++;
      i++;
      j++;
    } else
      j++;
  }
  cout << ans << endl;
}
int main() {
  int t = 1;
  while (t--) {
    solve();
  }
}
