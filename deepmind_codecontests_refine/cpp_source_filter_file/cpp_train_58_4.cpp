#include <bits/stdc++.h>
using namespace std;
string s;
int d[111], t, m, c, b = 0, i, j, k, l;
int main() {
  cin >> t >> m;
  for (int k = 0; k < t; k++) {
    cin >> s;
    if (s == "alloc") {
      cin >> c;
      for (i = 0, j = -1; i < m; i++)
        if (i - j == c && !d[i])
          break;
        else if (d[i])
          j = i;
      if (i - j == c && i < m) {
        cout << ++b << endl;
        for (l = j + 1; l <= i; l++) d[l] = b;
      } else
        cout << "NULL" << endl;
    } else if (s == "erase") {
      cin >> c;
      for (i = 0, j = 0; i < m; i++)
        if (d[i] == c && c != 0) d[i] = 0, j = 1;
      if (!j) cout << "ILLEGAL_ERASE_ARGUMENT" << endl;
    } else if (s == "defragment") {
      for (i = 0, j = 0; i < m; i++)
        if (d[i]) {
          l = d[j];
          d[j] = d[i];
          d[i] = 1;
          j++;
        }
    }
  }
  return 0;
}
