#include <bits/stdc++.h>
const int maxn = 1e7;
char a[maxn];
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
      if (k == 2) puts("");
      for (int i = 0; i < n; i++) {
        if (a[i] != ' ') printf("%c", a[i]);
      }
      k = 1;
    } else {
      if (k == 1) {
        puts("");
      }
      printf("%s", a);
      k = 2;
    }
  }
  puts("");
  return 0;
}
