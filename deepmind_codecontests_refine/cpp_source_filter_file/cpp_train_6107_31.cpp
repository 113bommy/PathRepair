#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int ca = 0, cb = 0, id = 0, i;
  for (i = 0; s[i] != '\0'; i++) {
    if (s[i] == '0') {
      cb = 0;
      ca++;
      if (ca == 7) {
        id = 1;
        break;
      }
    } else {
      ca = 0;
      cb++;
      if (cb = 7) {
        id = 1;
        break;
      }
    }
  }
  if (id == 1)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
