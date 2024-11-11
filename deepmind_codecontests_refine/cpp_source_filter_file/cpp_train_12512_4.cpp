#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int q;
  cin >> q;
  vector<set<char>> v(26);
  for (int i = 0; i < (int)s.length(); i++) v[s[i] - 'a'].insert(i + 1);
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int pos;
      char c;
      cin >> pos >> c;
      v[s[pos - 1] - 'a'].erase(pos);
      v[c - 'a'].insert(pos);
      s[pos - 1] = c;
    } else {
      int ans = 0, l, r;
      cin >> l >> r;
      for (int i = 0; i < 26; i++) {
        auto iter = v[i].lower_bound(l);
        if (iter != v[i].end() && *iter <= r) ans++;
      }
      cout << ans << endl;
    }
  }
  return 0;
}
