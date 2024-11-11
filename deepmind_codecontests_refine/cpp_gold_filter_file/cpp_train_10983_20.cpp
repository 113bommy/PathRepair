#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int upper = 0, lower = 0, a;
  for (int i = 0; i < s.length(); i++) {
    if (int(s[i]) < 97)
      upper += 1;
    else
      lower += 1;
  }
  if (upper > lower) {
    for (int i = 0; i < s.length(); i++) {
      a = s[i];
      if (a >= 97) {
        a = a - 32;
        s[i] = a;
      }
    }
  }
  if (upper <= lower) {
    for (int i = 0; i < s.length(); i++) {
      a = s[i];
      if (a < 97) {
        a = a + 32;
        s[i] = a;
      }
    }
  }
  cout << s;
}
