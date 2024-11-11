#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int c1 = 0, c2 = 0, x = 0;
  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '|') {
      x = 1;
      continue;
    }
    if (x == 0)
      c1++;
    else
      c2++;
  }
  string s2;
  cin >> s2;
  if ((c1 + c2 + s2.length()) % 2 == 1) {
  } else if (c1 < c2) {
    if (c1 + s2.length() >= c2) {
      int i;
      for (i = 0; i < ((c1 + c2 + s2.length()) / 2 - c1); ++i) cout << s2[i];
      cout << s;
      for (; i < s2.length(); ++i) cout << s2[i];
      return 0;
    }
  } else if (c1 > c2)
    if ((c2 + s2.length()) >= c1) {
      int i;
      for (i = ((c1 + c2 + s2.length()) / 2 - c2); i < s2.length(); ++i)
        cout << s2[i];
      cout << s;
      for (i = 0; i < ((c1 + c2 + s2.length()) / 2 - c2); ++i) cout << s2[i];
      return 0;
    }
  cout << "Impossible";
}
