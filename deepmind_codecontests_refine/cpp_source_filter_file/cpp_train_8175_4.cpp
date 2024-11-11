#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, i, j, k, f;
  string s;
  char cap[15] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V',
                  'W', 'X', 'Y', 'o', 'v', 'w', 'x'};
  cin >> s;
  i = 0;
  j = s.length() - 1;
  while (i <= j) {
    if (s[i] == s[j]) {
      for (k = 0; k < 15; k++) {
        if (s[i] == cap[k]) break;
      }
      if (k >= 15) {
        break;
      }
    } else {
      if ((s[i] == 'b' && s[j] == 'd') || (s[i] == 'd' && s[j] == 'b'))
        ;
      else if ((s[i] == 'p' && s[j] == 'q') || (s[i] == 'q' && s[j] == 'p'))
        ;
      else
        break;
    }
    i++;
    j--;
  }
  if (i <= j)
    cout << "NTE\n";
  else
    cout << "TAK\n";
  return 0;
}
