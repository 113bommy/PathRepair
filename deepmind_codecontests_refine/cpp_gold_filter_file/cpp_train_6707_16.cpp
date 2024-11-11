#include <bits/stdc++.h>
using namespace std;
int main() {
  int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
  string s;
  cin >> s;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'n') {
      c1++;
    } else if (s[i] == 'e') {
      c2++;
    } else if (s[i] == 'i') {
      c3++;
    } else if (s[i] == 't') {
      c4++;
    }
  }
  int a, b;
  a = (c1 - 1) / 2;
  b = c2 / 3;
  cout << min(c4, min(c3, min(a, b)));
  return 0;
}
