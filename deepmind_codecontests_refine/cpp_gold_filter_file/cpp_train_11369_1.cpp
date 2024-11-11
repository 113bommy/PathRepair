#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:60000000")
using namespace std;
int main() {
  string s;
  cin >> s;
  stack<char> st;
  int i = 0;
  int h = 0;
  bool flag = true;
  while (i < s.size()) {
    if (s[i + 1] != '/') {
      for (int i = 1; i <= 2 * h; i++) {
        cout << " ";
      }
      cout << "<" << s[i + 1] << ">" << endl;
      i += 3;
      h++;
    } else {
      h--;
      for (int i = 1; i <= 2 * h; i++) {
        cout << " ";
      }
      cout << "<"
           << "/" << s[i + 2] << ">" << endl;
      i += 4;
    }
  }
  return 0;
}
