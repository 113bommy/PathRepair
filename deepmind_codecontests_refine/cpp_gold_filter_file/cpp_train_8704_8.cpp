#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int i, j = 0, x, a, temp = 0, k;
  cin >> s;
  if (s.length() == 1)
    cout << "YES" << endl;
  else {
    for (i = 0; s[i]; i++) {
      if (s[i] != '0' && temp == 0) {
        a = i;
        temp = 1;
      }
      if (s[i] != '0') x = i;
    }
    temp = 0;
    if (x != a)
      k = (x - a) / 2;
    else if (x == a) {
      temp = 0;
      k = 0;
    }
    while (0 <= k) {
      if (s[a] != s[x]) {
        temp = 1;
      }
      a++;
      x--;
      k--;
    }
    if (temp == 0) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}
