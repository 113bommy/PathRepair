#include <bits/stdc++.h>
using namespace std;
int main() {
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    string s, t, p;
    cin >> s >> t >> p;
    int k = 0, j = 0;
    string ss = s;
    while (ss.length() != 0 && j < t.length()) {
      if (ss[k] == t[j]) ss.erase(k, 1);
      j++;
    }
    if (ss.length() == 0) {
      int z = 0;
      while (z < t.length()) {
        if (s[z] != t[z]) {
          int index = p.find(t[z]);
          if (index >= 0 && index < p.length()) {
            string m(1, p[index]);
            s.insert(z, m);
            p.erase(index, 1);
          } else {
            cout << "NO" << endl;
            break;
          }
        }
        z++;
      }
      if (s == t) cout << "YES" << endl;
    } else
      cout << "NO" << endl;
  }
}
