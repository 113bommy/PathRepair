#include <bits/stdc++.h>
using namespace std;
int change(char *s, int r) {
  int j, c;
  bool flag = true;
  j = r + 1;
  while (s[j] == s[r]) {
    if (flag) {
      if (r) {
        s[j] = s[r - 1];
      } else {
        c = s[j];
        if (c > 97)
          c--;
        else
          c++;
        s[j] = c;
      }
      flag = false;
    } else
      flag = true;
    j++;
  }
  if (s[j - 1] == s[j] && s[j] != '\0') {
    c = s[j];
    if (c > 97) {
      c--;
      if (c == s[j - 2]) {
        if (c > 97)
          c--;
        else
          c += 4;
      }
    } else
      c += 4;
    s[j - 1] = c;
  }
  return j - r;
}
int main() {
  char s[200001];
  cin >> s;
  int i = 0;
  while (s[i] != '\0') {
    if (s[i] == s[i + 1])
      i += change(s, i);
    else
      i++;
  }
  i = 0;
  while (s[i] != '\0') {
    cout << s[i];
    i++;
  }
  return 0;
}
