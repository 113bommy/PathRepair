#include <bits/stdc++.h>
using namespace std;
int main() {
  int t1, t2;
  cin >> t2;
  string s[103];
  int slen = 1;
  int u[103];
  bool flag[103];
  s[0] = "void";
  flag[0] = 1;
  u[0] = 0;
  string s1, s2, s3, s4;
  int i, j, k, t4, u1;
  bool add;
  bool flag1;
  for (t1 = 0; t1 < t2; t1++) {
    cin >> s1;
    add = 0;
    if (s1 == "typedef") {
      cin >> s2 >> s3;
      for (t4 = 0; t4 < slen; t4++) {
        if (s[t4] == s3) {
          break;
        }
      }
      if (t4 == slen) {
        s[t4] = s3;
        add = 1;
      }
      u1 = 0;
      i = 0;
      while (s2[i] == '&') {
        i++;
      }
      j = s2.length() - 1;
      while (s2[j] == '*') {
        j--;
      }
      s4 = "";
      u1 = (s2.length() - 1 - j) - i;
      while (i <= j) {
        s4 += s2[i];
        i++;
      }
      for (k = 0; k < slen; k++) {
        if (s[k] == s4) {
          break;
        }
      }
      if (k < slen) {
        u[t4] = u1 + u[k];
        flag[t4] = flag[k];
        if (flag[t4] == 1 && u[t4] < 0) {
          flag[t4] = 0;
        }
      } else {
        flag[t4] = 0;
      }
      if (add) {
        slen++;
      }
    }
    if (s1 == "typeof") {
      cin >> s2;
      u1 = 0;
      i = 0;
      while (s2[i] == '&') {
        i++;
      }
      j = s2.length() - 1;
      while (s2[j] == '*') {
        j--;
      }
      s4 = "";
      u1 = (s2.length() - 1 - j) - i;
      while (i <= j) {
        s4 += s2[i];
        i++;
      }
      for (k = 0; k < slen; k++) {
        if (s[k] == s4) {
          break;
        }
      }
      if (k < slen) {
        u1 = u1 + u[k];
        flag1 = flag[k];
        if (flag1 == 1 && u1 < 0) {
          flag1 = 0;
        }
        if (flag1 == 1) {
          if (u1 < 0) {
            for (i = u1; i < 0; i++) {
              cout << "&";
            }
            cout << "void\n";
          } else {
            cout << "void";
            for (i = 0; i < u1; i++) {
              cout << "*";
            }
            cout << "\n";
          }
        } else {
          cout << "errtype\n";
        }
      } else {
        cout << "errtype1\n";
      }
    }
  }
  return 0;
}
