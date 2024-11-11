#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  bool complex = true;
  if (s.size() < 5) complex = complex && false;
  int uc = 0, lc = 0, dc = 0;
  for (int i = 0; i < s.size(); i++) {
    if ('A' >= s[i] && s[i] <= 'Z') uc++;
    if ('a' >= s[i] && s[i] <= 'z') lc++;
    if ('0' >= s[i] && s[i] <= '9') dc++;
  }
  if (uc == 0) complex = complex && false;
  if (lc == 0) complex = complex && false;
  if (dc == 0) complex = complex && false;
  cout << (complex ? "Correct" : "Too Weak");
  return 0;
}
