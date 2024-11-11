#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  int i, a = 0, b = 0, c = 0;
  getline(cin, s);
  if (s.length() < 5) {
    cout << "Too weak";
    return 0;
  }
  for (i = 0; i < s.length(); i++) {
    if (s[i] >= '0' && s[i] <= '9') a = 1;
    if (s[i] >= 'A' && s[i] <= 'Z') b = 1;
    if (s[i] >= 'a' && s[i] <= 'z') c = 1;
  }
  if (a == 1 && b == 1 && c == 1) {
    cout << "Correct";
    return 0;
  }
  cout << "Too weak";
  return 0;
}
