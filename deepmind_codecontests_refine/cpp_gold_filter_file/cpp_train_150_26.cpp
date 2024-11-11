#include <bits/stdc++.h>
using namespace std;
int main() {
  int l;
  cin >> l;
  string s;
  cin >> s;
  int count = 1;
  for (int j = 0; j < l; j++) {
    for (int i = 0; i < l; i++) {
      if ((count * 4) - 1 > l) break;
      if (s[i] == '*' && s[i] == s[i + count] &&
          s[i + count] == s[i + count * 2] &&
          s[i + count * 2] == s[i + count * 3] &&
          s[i + count * 3] == s[i + count * 4]) {
        cout << "yes" << endl;
        return 0;
      }
    }
    count++;
  }
  cout << "no" << endl;
  return 0;
}
