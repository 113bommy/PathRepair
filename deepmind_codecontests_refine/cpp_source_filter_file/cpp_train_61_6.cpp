#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, c1 = 0, c2 = 0;
  bool b = 0, b1 = 0, b2 = 0;
  string s;
  cin >> s >> a;
  string ss, ss1 = s;
  reverse(ss1.begin(), ss1.end());
  for (int i = 0; i < a; ++i) {
    cin >> ss;
    if (ss == s, ss == ss1) {
      b = 1;
    }
    if (ss[1] == s[0]) {
      b1 = 1;
    }
    if (ss[0] == s[1]) {
      b2 = 1;
    }
  }
  if (b == 1) {
    cout << "YES\n";
  } else if (b1 == 1 && b2 == 1) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
}
