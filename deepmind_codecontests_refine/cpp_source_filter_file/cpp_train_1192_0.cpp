#include <bits/stdc++.h>
using namespace std;
int main() {
  char ch;
  char s1[100] = "qwertyuiop";
  char s2[100] = "asdfghjkl;";
  char s3[100] = "zxcvbnm,./";
  char s4[100];
  cin >> ch;
  cin >> s4;
  int l = strlen(s4);
  if (ch == 'R') {
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < 10; j++) {
        if (s1[j] == s4[i]) {
          s4[i] = s1[j - 1];
          break;
        } else if (s2[j] == s4[i]) {
          s4[i] = s2[j - 1];
          break;
        } else if (s3[j] == s4[i]) {
          s4[i] = s3[j - 1];
          break;
        }
      }
    }
  } else if (ch == 'L') {
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < 10; j++) {
        if (s1[j] == s4[i]) {
          s4[i] = s1[j - 1];
          break;
        } else if (s2[j] == s4[i]) {
          s4[i] = s2[j - 1];
          break;
        } else if (s3[j] == s4[i]) {
          s4[i] = s3[j - 1];
          break;
        }
      }
    }
  }
  cout << s4;
}
