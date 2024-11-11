#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> v;
  int c, x, t, y;
  string s, cc;
  cin >> c >> s;
  if (c == 1) {
    cout << s << endl;
  } else {
    y = (c / 2);
    v.push_back(c);
    for (int i = y; i > 0; i--) {
      if (c % i == 0) {
        v.push_back(i);
      }
    }
    x = v.size() - 2;
    while (x >= 0) {
      cc = "";
      for (int i = 0; i < v[x]; i++) {
        cc = s[i] + cc;
      }
      t = c - v[x];
      cc = cc + s.substr(v[x], t);
      x--;
      s = cc;
    }
    cout << cc << endl;
  }
  return 0;
}
