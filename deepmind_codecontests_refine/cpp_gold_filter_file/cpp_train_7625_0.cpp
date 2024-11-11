#include <bits/stdc++.h>
using namespace std;
int32_t main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    string ans = "";
    int r = 0, p = 0, ss = 0;
    for (auto ch : s) {
      if (ch == 'S')
        ss++;
      else if (ch == 'P')
        p++;
      else
        r++;
    }
    int mx = -1;
    char ch;
    if (mx < r) mx = r, ch = 'P';
    if (mx < p) mx = p, ch = 'S';
    if (mx < ss) mx = ss, ch = 'R';
    for (int i = 0; i < s.length(); i++) ans += ch;
    cout << ans << endl;
  }
  return 0;
}
