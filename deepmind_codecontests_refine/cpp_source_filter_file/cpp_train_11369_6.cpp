#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  int i, c = 0;
  for (i = 0; i < s.length();) {
    if (s[i + 1] != '/') {
      for (int j = 1; j <= c; j++) cout << " ";
      cout << s[i] << s[i + 1] << s[i + 2] << endl;
      i += 3;
      c++;
    } else {
      c--;
      for (int j = 1; j <= c; j++) cout << " ";
      cout << s[i] << s[i + 1] << s[i + 2] << s[i + 3] << endl;
      i += 4;
    }
  }
  return 0;
}
