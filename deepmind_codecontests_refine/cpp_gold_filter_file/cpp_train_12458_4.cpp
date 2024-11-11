#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[2][1000];
  cin >> s[0] >> s[1];
  int n = strlen(s[0]), ct = 0;
  for (int i = 0; i < n - 1;) {
    if (s[0][i] == '0' && s[1][i] == '0' && s[0][i + 2] == '0' &&
        s[0][i + 1] == '0' && s[1][i + 1] == '0' && s[1][i + 2] == '0' &&
        i < n - 2) {
      ct += 2;
      i += 3;
    } else if (s[0][i] == '0' && s[1][i] == '0' && s[0][i + 1] == '0') {
      ct++;
      i += 2;
    } else if (s[0][i] == '0' && s[1][i] == '0' && s[1][i + 1] == '0') {
      ct++;
      i += 2;
    } else if (s[0][i] == '0' && s[1][i + 1] == '0' && s[0][i + 1] == '0') {
      ct++;
      i += 2;
    } else if (s[1][i] == '0' && s[0][i + 1] == '0' && s[1][i + 1] == '0') {
      ct++;
      i += 2;
    } else {
      i++;
    }
  }
  cout << ct;
}
