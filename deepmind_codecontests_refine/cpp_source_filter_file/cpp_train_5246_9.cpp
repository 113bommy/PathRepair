#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, s, t;
  bool chks = false, chkt = false;
  string str = "";
  cin >> n;
  cin >> str;
  int i = 0;
  while (i < str.length()) {
    if (!chks && str[i] == 'R') {
      s = i + 1;
      while (!chkt && i < str.length()) {
        if (str[i] == 'L' || str[i] == '.') {
          t = i;
          if (str[i] == '.') t++;
          chkt = true;
          chks = true;
        }
        i++;
      }
    }
    i++;
  }
  i = 0;
  while (!chks && i < str.length()) {
    if (str[i] == 'L') {
      t = i;
      while (!chks && i < str.length()) {
        if (str[i] == '.') {
          s = i - 2;
          chks = true;
          chkt = true;
        }
        i++;
      }
    }
    i++;
  }
  cout << s << " " << t << endl;
  return 0;
}
