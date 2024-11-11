#include <bits/stdc++.h>
using namespace std;
string s;
int i, c, k;
int main() {
  int n, l, j;
  cin >> n >> l;
  cin >> s;
  if (l == 2) {
    string t, u;
    for (int i = 0; i < s.size(); ++i) {
      t += char('A' + i % 2);
      u += char('A' + 1 - i % 2);
    }
    int c0 = 0, c1 = 0;
    for (int i = 0; i < s.size(); ++i) {
      c0 += (s[i] != t[i]);
      c1 += (s[i] != u[i]);
    }
    if (c0 < c1) {
      cout << c0 << '\n' << t << endl;
    } else {
      cout << c1 << '\n' << u << endl;
    }
  } else {
    if (s[0] == s[1] && s[1] != s[2]) {
      for (k = 0; k < l; k++)
        if (s[1] != (char)(65 + k)) s[0] = (char)(65 + k);
      c++;
    }
    for (i = 0; i < n - 1; i++) {
      if (s[i] == s[i + 1]) {
        c++;
        {
          for (k = 0; k < l; k++)
            if (s[i] != (char)(65 + k) && s[i + 2] != (char)(65 + k))
              s[i + 1] = (char)(65 + k);
        }
        i++;
      }
    }
    cout << c << endl;
    cout << s;
  }
  return 0;
}
