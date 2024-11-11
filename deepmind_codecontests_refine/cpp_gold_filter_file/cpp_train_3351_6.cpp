#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    string s, t;
    set<char> sym;
    cin >> s;
    cin >> t;
    for (int j = 0; j < (int)s.size(); j++) {
      sym.insert(s[j]);
    }
    bool ok = false;
    for (int j = 0; j < (int)s.size(); j++) {
      if (sym.count(t[j]) == 0)
        continue;
      else
        ok = true;
    }
    if (ok)
      cout << "YES\n";
    else
      cout << "NO\n";
  }
}
