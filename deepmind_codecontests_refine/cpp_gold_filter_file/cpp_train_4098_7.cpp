#include <bits/stdc++.h>
using namespace std;
int main() {
  int i = 0, c = 0, t;
  string s;
  cin >> s;
  while (s[i] != '@') {
    if ((i < 32) &&
        ((s[i] >= 65 && s[i] <= 90) || (s[i] == 95) ||
         (s[i] >= 48 && s[i] <= 57) || (s[i] >= 97 && s[i] <= 122))) {
      i++;
    } else {
      cout << "NO";
      return 0;
    }
  }
  if (i == 0) {
    cout << "NO";
    return 0;
  }
  i++;
  t = 0;
  while (s[i] != '/' && s[i] != '\0') {
    if (s[i] == '.' && (t < 32)) {
      if (c > 0 && c <= 16) {
        c = 0;
      } else {
        cout << "NO";
        return 0;
      }
    } else {
      if ((t < 32) &&
          ((s[i] >= 65 && s[i] <= 90) || (s[i] == 95) ||
           (s[i] >= 48 && s[i] <= 57) || (s[i] >= 97 && s[i] <= 122))) {
        c++;
      } else {
        cout << "NO";
        return 0;
      }
    }
    i++;
    t++;
  }
  if (c == 0) {
    cout << "NO";
    return 0;
  }
  if (s[i] == '/') {
    i++;
    t = 0;
    while (s[i] != '\0') {
      if ((t < 16) &&
          ((s[i] >= 65 && s[i] <= 90) || (s[i] == 95) ||
           (s[i] >= 48 && s[i] <= 57) || (s[i] >= 97 && s[i] <= 122))) {
        i++;
        t++;
      } else {
        cout << "NO";
        return 0;
      }
    }
  }
  if (t == 0) {
    cout << "NO";
    return 0;
  }
  if (s[i] == '\0') cout << "YES";
  return 0;
}
