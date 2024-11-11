#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int i = 0;
  int count = 0;
  while (i < s.length()) {
    if (s[i] == '/') {
      ++count;
    }
    ++i;
  }
  i = 0;
  int j = 0;
  while (i < s.length()) {
    if (s[i] == '<' && s[i + 1] != '/') {
      ++j;
      int k = 1;
      while (k < j) {
        cout << " ";
        ++k;
      }
    } else if (s[i] == '<' && s[i + 1] == '/') {
      int k = 1;
      while (k < j) {
        cout << " ";
        ++k;
      }
      --j;
    }
    cout << s[i];
    if (s[i] == '>') {
      if (j < 0) {
        break;
      }
      cout << endl;
    }
    ++i;
  }
  return 0;
}
