#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  getline(cin, s);
  sort(s.begin(), s.end());
  int i = 0, j = 1, c = 1;
  while (j < s.length() + 1) {
    if (s[i] == s[j]) {
      j++;
    } else {
      i = j;
      j++;
      c++;
    }
  }
  if (c % 2 == 0) {
    cout << "CHAT WITH HER!";
  } else {
    cout << "IGNORE HIM!";
  }
  return 0;
}
