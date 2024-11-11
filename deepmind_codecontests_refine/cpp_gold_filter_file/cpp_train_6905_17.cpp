#include <bits/stdc++.h>
using namespace std;
const int N = 1e6;
int main() {
  string s;
  int i, flag = 0;
  while (getline(cin, s)) {
    for (i = 0; i < s.size(); i++)
      if (s[i] != ' ') break;
    if (s[i] == '#') {
      if (flag) cout << endl;
      cout << s;
      flag = 1;
    } else {
      if (flag == 1) cout << endl;
      for (int i = 0; i < s.size(); i++)
        if (s[i] != ' ') cout << s[i];
      flag = 2;
    }
  }
  cout << endl;
  return 0;
}
