#include <bits/stdc++.h>
using namespace std;
bool isValid(string s) {
  bool f1 = false, f2 = false, f3 = false;
  for (int i = 0; i < s.length(); i++) {
    if (islower(s[i]))
      f1 = true;
    else if (isupper(s[i]))
      f2 = true;
    else if (isdigit(s[i]))
      f3 = true;
  }
  return f1 && f2 && f3;
}
void solve(string s) {
  if (isValid(s)) {
    cout << s << endl;
    return;
  }
  for (int i = 0; i < s.length(); i++) {
    string tmp = s;
    tmp[0] = '0';
    if (isValid(tmp)) {
      cout << tmp << endl;
      return;
    }
    tmp[0] = 'a';
    if (isValid(tmp)) {
      cout << tmp << endl;
      return;
    }
    tmp[0] = 'A';
    if (isValid(tmp)) {
      cout << tmp << endl;
      return;
    }
  }
  if (isupper(s[0])) {
    s[1] = 'a';
    s[2] = '0';
    cout << s << endl;
  } else if (islower(s[0])) {
    s[1] = 'A';
    s[2] = '0';
    cout << s << endl;
  } else if (isdigit(s[0])) {
    s[1] = 'a';
    s[2] = 'A';
    cout << s << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    solve(s);
  }
  return 0;
}
