#include <bits/stdc++.h>
using namespace std;
int a, i;
string s, ss, q;
int main() {
  cin >> a >> s;
  for (i = a; i <= 1000010; ++i) {
    int j = i;
    ss = q;
    while (j) {
      if (j % 10 == 4 || j % 10 == 7) {
        if (ss.size() == 0) {
          ss = char(j % 10 + 48);
        } else
          ss += char(j % 10 + 48);
      }
      j /= 10;
    }
    reverse(ss.begin(), ss.end());
    if (ss == s) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
