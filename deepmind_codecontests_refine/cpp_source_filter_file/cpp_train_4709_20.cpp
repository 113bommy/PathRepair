#include <bits/stdc++.h>
using namespace std;
int verif1(string s) {
  int r = 0;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == toupper(s[i])) r++;
  }
  if (r == s.size())
    return 1;
  else
    return 0;
}
int verif2(string s) {
  if (s[0] <= 90)
    return 0;
  else {
    int r = 1;
    for (int i = 1; i < s.size(); i++) {
      if ((s[i] >= 65) && (s[i] <= 90)) r++;
    }
    if (r == s.size())
      return 1;
    else
      return 0;
  }
}
int main() {
  string s;
  cin >> s;
  if ((verif1(s) == 0) && (verif2(s) == 0))
    cout << s;
  else if (verif1(s) == 1) {
    for (int i = 1; i < s.size(); i++) s[i] = tolower(s[i]);
    cout << s;
  } else if (verif2(s) == 1) {
    s[0] = toupper(s[0]);
    for (int i = 1; i < s.size(); i++) s[i] = tolower(s[i]);
    cout << s;
  }
}
