#include <bits/stdc++.h>
using namespace std;
char s[1003][1003];
int len[1003];
int n = 0, maxl = 0;
int main() {
  for (int i = 0; i < 1003; i++) len[i] = 0;
  while (gets(s[n])) {
    len[n] = strlen(s[n]);
    maxl = max(maxl, len[n]);
    n++;
  }
  for (int i = 0; i < maxl + 2; i++) printf("*");
  printf("\n");
  bool flag = 0;
  for (int i = 0; i <= n; i++) {
    printf("*");
    int dif = maxl - len[i];
    if (dif % 2 == 0) {
      dif /= 2;
      for (int j = 0; j < dif; j++) printf(" ");
      for (int j = 0; j < len[i]; j++) cout << s[i][j];
      for (int j = 0; j < dif; j++) printf(" ");
    } else {
      dif /= 2;
      if (flag) {
        for (int j = 0; j <= dif; j++) printf(" ");
        for (int j = 0; j < len[i]; j++) cout << s[i][j];
        for (int j = 0; j < dif; j++) printf(" ");
      } else {
        for (int j = 0; j < dif; j++) printf(" ");
        for (int j = 0; j < len[i]; j++) cout << s[i][j];
        for (int j = 0; j <= dif; j++) printf(" ");
      }
      flag = !flag;
    }
    printf("*\n");
  }
  for (int i = 0; i < maxl + 2; i++) printf("*");
  return 0;
}
