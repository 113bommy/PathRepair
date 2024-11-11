#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  while (n--) {
    string str;
    cin >> str;
    int len = str.length();
    int r = 0, s = 0, p = 0;
    for (int i = 0; i < len; i++) {
      if (str[i] == 'S')
        s++;
      else if (str[i] == 'R')
        r++;
      else
        p++;
    }
    char ch;
    if (r >= p && r >= s)
      ch = 'P';
    else if (p >= r && p >= s)
      ch = 'S';
    else
      ch = 'R';
    while (len--) cout << ch;
    cout << endl;
  }
}
