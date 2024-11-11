#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  vector<set<int>> vt(26);
  for (int i = 0; i < s.length(); i++) {
    vt[s[i] - 'a'].insert(i);
  }
  int q;
  cin >> q;
  while (q--) {
    int type;
    cin >> type;
    if (type == 1) {
      int pos;
      char ch;
      cin >> pos >> ch;
      --pos;
      vt[s[pos] - 'a'].erase(pos);
      s[pos] = ch;
      vt[s[pos] - 'a'].insert(pos);
    } else {
      int l, r;
      cin >> l >> r;
      l--, r--;
      int cnt = 0;
      for (int i = 0; i < 26; i++) {
        auto it = vt[i].lower_bound(l);
        if (it != vt[i].end() && *it <= r) cnt++;
      }
      cout << cnt << endl;
    }
  }
  return 0;
}
