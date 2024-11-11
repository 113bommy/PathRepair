#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int l, U;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] > 91)
      l++;
    else
      U++;
  }
  if (l >= U) {
    for (int i = 0; i < s.length(); i++) {
      putchar(tolower(s[i]));
    }
  } else {
    for (int i = 0; i < s.length(); i++) {
      putchar(toupper(s[i]));
    }
  }
}
