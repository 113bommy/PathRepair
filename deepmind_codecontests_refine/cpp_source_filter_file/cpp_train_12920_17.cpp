#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    char s[101];
    cin >> s;
    int a = -1, b = -1, c = -1;
    for (int i = 0; i < strlen(s); i++) {
      if (a == -1 && s[i] >= 'a' && s[i] <= 'z') a = i;
      if (b == -1 && s[i] >= 'A' && s[i] <= 'Z') b = i;
      if (c == -1 && s[i] >= '0' && s[i] <= '9') c = i;
    }
    if (a == -1) {
      for (int i = 0; i < strlen(s); i++) {
        if (i != b && i != c) {
          s[i] = 'a';
          a = i;
          break;
        }
      }
    }
    if (b == -1) {
      for (int i = 0; i < strlen(s); i++) {
        if (i != a && i != c) {
          s[i] = 'A';
          b = i;
          break;
        }
      }
    }
    if (c == -1) {
      for (int i = 0; i < strlen(s); i++) {
        if (i != a && i != b) {
          s[i] = '0';
          c = i;
          break;
        }
      }
    }
    cout << s;
  }
  return 0;
}
