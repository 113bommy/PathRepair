#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  while (cin >> s) {
    int len = s.size();
    int t = 0;
    for (int i = 0; i < len; i++) {
      if (s[i] == '0') {
        t = i;
        break;
      }
    }
    for (int i = 0; i < len; i++) {
      if (i == t) continue;
      cout << s[i];
    }
    cout << endl;
  }
  return 0;
}
