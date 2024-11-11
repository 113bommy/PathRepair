#include <bits/stdc++.h>
using namespace std;
int main() {
  char s[100], b[100];
  int len, i, k, ctr, pos;
  char a;
  scanf("%s", s);
  len = strlen(s);
  ctr = 0;
  if (len % 2 == 0) {
    for (i = 0; i < len / 2 + 1; i++) {
      if (s[i] != s[len + ctr - 1 - i]) {
        pos = i;
        ctr++;
      }
    }
    if (ctr == 1) {
      for (i = 0; i < len / 2 + 1; i++) {
        b[i] = s[i];
        cout << s[i];
      }
      k = len / 2 + 1;
      for (i = len / 2 - 1; i >= 0; i--) {
        b[k] = s[i];
        cout << s[i];
        k++;
      }
    } else if (ctr == 0) {
      for (i = 0; i < len / 2 + 1; i++) cout << s[i];
      for (i = len / 2 - 1; i >= 0; i--) cout << s[i];
    } else {
      ctr = 0;
      for (i = 0; i < len / 2 + 1; i++) {
        if (s[i - ctr] != s[len - 1 - i]) {
          pos = i;
          ctr++;
        }
      }
      if (ctr == 1) {
        for (i = len - 1; i >= len / 2 - 1; i--) cout << s[i];
        k = len / 2 + 1;
        for (i = len / 2; i < len; i++) {
          cout << s[i];
        }
        cout << endl;
      } else if (ctr == 0) {
        for (i = 0; i < len / 2 + 1; i++) cout << s[i];
        for (i = len / 2 - 1; i >= 0; i--) cout << s[i];
      } else
        cout << "NA" << endl;
    }
  }
  if (len % 2 == 1) {
    for (i = 0; i < len / 2 + 1; i++) {
      if (s[i] != s[len + ctr - 1 - i]) {
        pos = i;
        ctr++;
      }
    }
    if (ctr == 1) {
      for (i = 0; i < len / 2 + 1; i++) cout << s[i];
      k = len / 2 + 1;
      for (i = len / 2; i >= 0; i--) {
        cout << s[i];
        k++;
      }
      cout << endl;
    } else if (ctr == 0) {
      for (i = 0; i < len / 2 + 1; i++) cout << s[i];
      for (i = len / 2; i >= 0; i--) cout << s[i];
    } else {
      ctr = 0;
      for (i = 0; i < len / 2 + 1; i++) {
        if (s[i - ctr] != s[len - 1 - i]) {
          pos = i;
          ctr++;
        }
      }
      if (ctr == 1) {
        for (i = len - 1; i >= len / 2; i--) cout << s[i];
        k = len / 2 + 1;
        for (i = len / 2; i < len; i++) {
          cout << s[i];
        }
        cout << endl;
      } else if (ctr == 0) {
        for (i = 0; i < len / 2 + 1; i++) cout << s[i];
        for (i = len / 2 - 1; i >= 0; i--) cout << s[i];
      } else
        cout << "NA" << endl;
    }
  }
  return 0;
}
