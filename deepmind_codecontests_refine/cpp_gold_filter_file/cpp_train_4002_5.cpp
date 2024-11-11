#include <bits/stdc++.h>
using namespace std;
inline bool check(const string &s) {
  if (s.length() < 5) return 0;
  bool hasUpperCase = 0;
  bool hasLowerCase = 0;
  bool hasDigit = 0;
  for (int i = 0, size = s.length(); i < size; ++i) {
    hasUpperCase |= isupper(s[i]);
    hasLowerCase |= islower(s[i]);
    hasDigit |= isdigit(s[i]);
  }
  return hasDigit && hasUpperCase && hasLowerCase;
}
int run() {
  string s;
  while (cin >> s) cout << (check(s) ? "Correct" : "Too weak") << endl;
  return 0;
}
int main() {
  ios::sync_with_stdio(0);
  return run();
}
