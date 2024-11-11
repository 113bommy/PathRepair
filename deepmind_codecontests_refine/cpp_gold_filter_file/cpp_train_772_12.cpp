#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  int rez, mr;
  rez = 0;
  for (int i = 0; i < k; i++) {
    s += '?';
  }
  for (int i = 1; i <= s.size() / 2; i++) {
    mr = 0;
    for (int j = 0; j < s.size() - i; j++) {
      if ((s[j] == s[j + i]) || (s[j + i] == '?')) {
        mr++;
      } else {
        if (mr * 2 >= 2 * i) {
          rez = max(2 * i, rez);
        }
        mr = 0;
      }
    }
    if (mr * 2 >= 2 * i) {
      rez = max(2 * i, rez);
    }
  }
  cout << rez;
  return 0;
}
