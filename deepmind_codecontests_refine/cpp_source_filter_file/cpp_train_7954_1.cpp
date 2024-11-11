#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int right = 0, left = 0;
  int r = 1;
  size_t ful;
  ful = s.find("^");
  for (int i = 0; i < s.length(); i++) {
    if (s[i] >= 48 && s[i] <= 57) {
      if (i < ful) {
        right += ((ful - i) * (s[i] - 48));
      } else {
        left += ((i - ful) * (s[i] - 48));
      }
    }
  }
  if (right == left) {
    cout << "balance";
  } else {
    (right > left) ? cout << "left" : cout << "right";
  }
  return 0;
}
