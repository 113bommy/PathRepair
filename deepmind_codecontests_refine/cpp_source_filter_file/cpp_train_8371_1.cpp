#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int ct = 1, even = 0;
  char c = s[0];
  for (int i = 1; i < s.size(); i++) {
    if (c == s[i]) {
      ct++;
    } else {
      if (ct % 2 == 0) {
        even++;
      }
      ct = 1;
      c = s[i];
    }
  }
  cout << even << endl;
}
