#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int cn = 0, ci = 0, ce = 0, ct = 0, count = 0, x = 0;
  for (int i = 0; s[i] != '\0'; i++) {
    if (s[i] == 'n')
      cn++;
    else if (s[i] == 'i')
      ci++;
    else if (s[i] == 'e')
      ce++;
    else if (s[i] == 't')
      ct++;
    else if (s[i] == 'n' && s[i + 1] == 'i' && s[i + 2] == 'n' &&
             s[i + 3] == 'e' && s[i + 4] == 't' && s[i + 5] == 'e' &&
             s[i + 6] == 'e' && s[i + 7] == 'n')
      x++;
  }
  if (cn % 2 != 0) {
    while (cn >= 2 && ci >= 1 && ce >= 3 && ct >= 1) {
      if (cn >= 2 && ci >= 1 && ce >= 3 && ct >= 1) count++;
      cn = cn - 2;
      ci = ci - 1;
      ce = ce - 3;
      ct = ct - 1;
    }
  } else if (cn % 2 == 0) {
    while (cn >= 3 && ci >= 1 && ce >= 3 && ct >= 1) {
      if (cn >= 3 && ci >= 1 && ce >= 3 && ct >= 1) count++;
      cn = cn - 3;
      ci = ci - 1;
      ce = ce - 3;
      ct = ct - 1;
    }
  }
  cout << count;
}
