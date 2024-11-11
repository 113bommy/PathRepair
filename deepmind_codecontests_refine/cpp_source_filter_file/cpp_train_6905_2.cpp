#include <bits/stdc++.h>
const int maxn = 2e6;
char a[maxn];
char str[maxn];
int main() {
  int sum = 0;
  int k = 0;
  while (gets(a)) {
    int flag = 2, j = 0;
    int num = 0;
    int g;
    int n = strlen(a);
    for (g = 0; g < n; g++) {
      if (a[g] != ' ') break;
    }
    if (g == n || a[g] != '#') {
      flag = 1;
    } else {
      flag = 0;
    }
    for (int i = 0; i < n; i++) {
      if (flag == 0) {
        str[j++] = a[i];
      } else {
        if (a[i] != ' ') {
          str[j++] = a[i];
        }
      }
    }
    if (flag == 0) {
      if (k == 1) puts("");
      k = 2;
    }
    if (flag == 1) {
      if (k == 2) {
        puts("");
      }
      k = 1;
    }
    for (int i = 0; i < j; i++) {
      printf("%c", str[i]);
    }
  }
  puts("");
  return 0;
}
