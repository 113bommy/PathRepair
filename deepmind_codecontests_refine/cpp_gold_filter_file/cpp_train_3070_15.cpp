#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  int n = s.size();
  int d = 0, x = 0, y = 0, u = 0, v = 0;
  string r = s;
  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) d++;
  }
  if (d % 2 != 0)
    cout << "impossible";
  else {
    for (int i = 0; i < n; i++) {
      if (s[i] != t[i]) {
        if (x == 0) {
          r[i] = t[i];
          y = 0;
          x++;
          u++;
        } else {
          r[i] = s[i];
          x = 0;
          y++;
          v++;
        }
      }
    }
    cout << r;
  }
  return 0;
}
