#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int ct = 0;
  char type_ln = s[0];
  for (char c : s) {
    if (c == type_ln)
      ct++;
    else {
      ct = 1;
      type_ln = c;
    }
    if (ct > 6) {
      cout << "YES" << '\n';
      return 0;
    }
  }
  cout << "NO" << '\n';
}
