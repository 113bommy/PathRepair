#include <bits/stdc++.h>
using namespace std;
int main() {
  int i, j = 0, m = 0, z = 0;
  string s;
  cin >> s;
  for (i = 0; i < s.length(); i++) {
    while (s[j] == 'c') {
      j++;
      m++;
      if (m == 5 || s[j] != 'c' && m < 5) {
        z++;
        m = 0;
      }
    }
    while (s[j] == 'p') {
      j++;
      m++;
      if (m == 5 || s[j] != 'p' && m < 5) {
        z++;
        m = 0;
      }
    }
  }
  cout << z;
  return 0;
}
