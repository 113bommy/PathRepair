#include <bits/stdc++.h>
using namespace std;
int main() {
  string s1, s2;
  string a1, a2;
  int c1 = 0, c2 = 0;
  cin >> s1;
  cin >> s2;
  if (s1[0] == '|') {
    for (int i = 1; i < s1.length(); i++) {
      a2 += s1[i];
    }
  } else {
    for (int i = 0; i < s1.length(); i++) {
      if (s1[i] == '|') {
        break;
      }
      c1++;
      a1 += s1[i];
    }
    for (int i = c1 + 1; i < s1.length(); i++) {
      a2 += s1[i];
    }
  }
  for (int i = 0; i < s2.length(); i++) {
    if (a1.length() <= a2.length()) {
      a1 += s2[i];
    } else {
      a2 += s2[i];
    }
  }
  if (a1.length() == a2.length()) {
    cout << a1 << "|" << a2;
  } else
    cout << "Impossible";
  return 0;
}
