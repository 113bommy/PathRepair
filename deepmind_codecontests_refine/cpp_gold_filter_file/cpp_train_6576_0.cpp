#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  for (int f = 0; f < q; f++) {
    string s, t, p;
    cin >> s >> t >> p;
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
      if (s[i] == t[j]) {
        s.erase(i, 1);
        t.erase(j, 1);
      } else
        j++;
    }
    if (s.empty()) {
      float o = true;
      for (int k = 0; k < t.size(); k++) {
        if (p.find(t[k]) >= 0 && p.find(t[k]) < p.size())
          p.erase(p.find(t[k]), 1);
        else {
          cout << "NO" << endl;
          o = false;
          break;
        }
      }
      if (o) cout << "YES" << '\n';
    } else
      cout << "NO" << '\n';
  }
  return 0;
}
