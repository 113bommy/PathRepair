#include <bits/stdc++.h>
using namespace std;
int main() {
  string str, str1;
  long long int i, j;
  cin >> str;
  if (str[0] == 'h') {
    for (i = 0; i < 4; i++) {
      str1 += str[i];
    }
    str1 += "://";
    while (1) {
      if (str[i] == 'r' && str[i + 1] == 'u' && i != 4) {
        str1 += ".ru";
        break;
      } else {
        str1 += str[i];
      }
      i++;
    }
    i += 2;
    if (i <= str.size()) {
      str1 += '/';
      while (i < str.size()) {
        str1 += str[i];
        i++;
      }
    }
  } else {
    for (i = 0; i < 3; i++) {
      str1 += str[i];
    }
    str1 += "://";
    while (1) {
      if (str[i] == 'r' && str[i + 1] == 'u' && i != 3) {
        str1 += ".ru";
        break;
      } else {
        str1 += str[i];
      }
      i++;
    }
    i += 2;
    if (i <= str.size()) {
      str1 += '/';
      while (i < str.size()) {
        str1 += str[i];
        i++;
      }
    }
  }
  cout << str1;
  return 0;
}
