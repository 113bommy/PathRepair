#include <bits/stdc++.h>
using namespace std;
bool huiwen(string s) {
  for (int i = 0; 2 * i < s.size() - 1; i++) {
    if (s[i] != s[s.size() - 1 - i]) {
      return false;
    }
  }
  return true;
}
int main(int, char**) {
  string s;
  cin >> s;
  int right = s.size() - 1;
  int left = 0;
  if (huiwen(s)) {
    if (s == string(s.size(), s[0])) {
      cout << 0 << endl;
    } else {
      cout << s.size() << endl;
    }
  } else {
    cout << s.size() << endl;
  }
  return 0;
}
