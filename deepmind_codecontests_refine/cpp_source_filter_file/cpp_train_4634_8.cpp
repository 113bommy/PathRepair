#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  string s1 = "hello";
  int j = 0;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == s1[j]) {
      s1[j] = '#';
      j++;
    }
  }
  if (s1 == "#####") {
    cout << "yes";
  } else {
    cout << "no";
  }
  return 0;
}
