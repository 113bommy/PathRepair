#include <bits/stdc++.h>
using namespace std;
int main() {
  char t, r[] = {'6', '7', '8', '9', 'T', 'j', 'Q', 'k', 'A', '\0'};
  string s1, s2;
  cin >> t >> s1 >> s2;
  if (s1[1] == t && s2[1] != t) {
    cout << "YES";
    return 0;
  }
  if (s1[1] == s2[1]) {
    int i, j;
    for (int ii = 0; ii <= 8; ii++) {
      if (s1[0] == r[ii]) i = ii;
      if (s2[0] == r[ii]) j = ii;
    }
    if (i > j)
      cout << "YES";
    else
      cout << "NO";
    return 0;
  }
  cout << "NO";
  return 0;
}
