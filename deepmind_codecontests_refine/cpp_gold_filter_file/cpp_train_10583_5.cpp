#include <bits/stdc++.h>
typedef char mystr[102];
mystr s[100], w;
int chg[102];
int main() {
  int n;
  char letter;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }
  scanf("%s\n", w);
  scanf("%c", &letter);
  letter -= 'a';
  int len_w = strlen(w);
  for (int i = 0; i < 102; i++) {
    chg[i] = 0;
  }
  int len_s;
  for (int i = 0; i < n; i++) {
    len_s = strlen(s[i]);
    for (int j = 0; j < len_w - len_s + 1; j++) {
      int k, c1, c2;
      for (k = 0; k < len_s; k++) {
        c1 = w[j + k];
        c2 = s[i][k];
        if (c1 >= 'a')
          c1 -= 'a';
        else
          c1 -= 'A';
        if (c2 >= 'a')
          c2 -= 'a';
        else
          c2 -= 'A';
        if (c1 != c2) break;
      }
      if (k == len_s) {
        for (k = 0; k < len_s; k++) {
          chg[j + k] = 1;
        }
      }
    }
  }
  for (int i = 0; i < len_w; i++) {
    if (chg[i] > 0) {
      if (w[i] >= 'a') {
        if (w[i] != 'a' + letter) {
          w[i] = 'a' + letter;
        } else {
          if (letter > 0) {
            w[i] = 'a';
          } else {
            w[i] = 'b';
          }
        }
      } else {
        if (w[i] != 'A' + letter) {
          w[i] = 'A' + letter;
        } else {
          if (letter > 0) {
            w[i] = 'A';
          } else {
            w[i] = 'B';
          }
        }
      }
    }
  }
  printf("%s\n", w);
  return 0;
}
