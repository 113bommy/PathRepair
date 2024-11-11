#include <bits/stdc++.h>
using namespace std;
int d[101], t, m, c, a, b = 0;
int i, j, k, l;
string s;
int main() {
  cin >> t >> m;
  for (i = 1; i <= t; i++) {
    cin >> s;
    if (s[0] == 'a') {
      cin >> c;
      for (k = 0, j = -1; k < m; k++)
        if (k - j == c && !d[k])
          break;
        else if (d[k])
          j = k;
      if (k - j == c && k < m) {
        cout << ++b << endl;
        for (l = j + 1; l <= k; l++) d[l] = b;
      } else
        cout << "NULL" << endl;
    } else if (s[0] == 'e') {
      cin >> c;
      for (k = 0, j = 0; k < m; k++)
        if (d[k] == 'c' && c != 0) {
          d[k] = 0;
          j = 1;
        }
      if (!j) cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
    } else if (s[0] == 'd') {
      for (k = 0, j = 0; k < m; k++)
        if (d[k]) {
          a = d[j];
          d[j] = d[k];
          d[k] = a;
          j++;
        }
    }
  }
  return 0;
}
