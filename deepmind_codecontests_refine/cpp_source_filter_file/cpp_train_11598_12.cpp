#include <bits/stdc++.h>
using namespace std;
bool f(string s) {
  bool ans = false;
  if (s.size() == 0) {
    return false;
  }
  if (s == "1" or s == "14" or s == "144") {
    return true;
  }
  if (s.size() >= 1 && s[s.size() - 1] == '1')
    ans = (ans or f(s.substr(0, s.size() - 1)));
  if (s.size() >= 2 && s[s.size() - 1] == '4' && s[s.size() - 2] == '1')
    ans = (ans or f(s.substr(0, s.size() - 2)));
  if (s.size() >= 3 && s[s.size() - 3] == '4' && s[s.size() - 2] == '4' &&
      s[s.size() - 1] == '1')
    ans = (ans or f(s.substr(0, s.size() - 3)));
  return ans;
}
int main() {
  string s;
  cin >> s;
  if (f(s)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  return 0;
}
