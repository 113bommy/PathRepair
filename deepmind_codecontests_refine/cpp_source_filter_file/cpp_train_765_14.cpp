#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, a[30];
  int n;
  cin >> n;
  int i, j, k;
  int pos;
  char buff[3] = {0};
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 0; i < 26; i++) {
    buff[0] = char('a' + i);
    for (j = 0; j < n; j++) {
      pos = a[j].find(buff);
      if (pos != a[j].npos) break;
    }
    if (j == n) break;
  }
  if (i == 26) {
    for (i = 0; i < 26; i++) {
      buff[0] = char('a' + i);
      for (j = 0; j < 26; j++) {
        buff[1] = char('a' + j);
        for (k = 0; k < n; k++) {
          pos = a[k].find(buff);
          if (pos != a[k].npos) break;
        }
        if (k == n) break;
      }
      if (i != 26) break;
    }
  }
  cout << buff;
  return 0;
}
