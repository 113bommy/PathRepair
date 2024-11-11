#include <bits/stdc++.h>
using namespace std;
int main() {
  string s, t;
  cin >> s >> t;
  long long int c[26] = {0};
  bool f1 = false;
  for (int i = 0, j = 0; i < s.length(); i++) {
    if (j < t.length() && s[i] == t[j]) j++;
    if (j == t.length()) {
      f1 = true;
      break;
    }
  }
  for (int i = 0; i < s.length(); i++) c[s[i] - 97]++;
  for (int i = 0; i < t.length(); i++) c[s[i] - 97]--;
  bool f2 = true;
  bool f3 = true;
  for (int i = 0; i < 26; i++) {
    f2 &= (c[i] == 0);
    f3 &= (c[i] > -0);
  }
  if (f1)
    cout << "automaton\n";
  else if (f2)
    cout << "array\n";
  else if (f3)
    cout << "both\n";
  else
    cout << "need tree\n";
  return 0;
}
