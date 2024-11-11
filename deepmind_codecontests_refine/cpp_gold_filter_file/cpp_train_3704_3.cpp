#include <bits/stdc++.h>
using namespace std;
bool f(string s) {
  int r = s.length();
  char x = 'a' - 1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == x + 1)
      x++;
    else if (s[i] > x + 1)
      return false;
  }
  return true;
}
int main() {
  string s;
  cin >> s;
  cout << (f(s) ? "YES" : "NO") << "\n";
  return 0;
}
