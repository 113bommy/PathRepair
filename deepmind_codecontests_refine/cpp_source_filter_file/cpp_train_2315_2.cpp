#include <bits/stdc++.h>
using namespace std;
char s[1000100] = {0};
int a[1000100], an;
int b[1000100], bn, n;
int cal(int k) { return n - 1 - k; }
int gao() {
  int i, j;
  n = strlen(s);
  an = bn = 0;
  for (i = n - 1; i >= 0; i--) {
    if (s[i] == '1' && s[i + 1] == '1' && s[i + 2] == '0' && s[i + 3] == '1') {
      a[an++] = cal(i + 2);
      s[i + 2] = '1';
    }
  }
  int pre = -1;
  for (i = n - 1; i >= 0; i--) {
    if (s[i] == '0') {
      if (pre == -1) continue;
      if (pre == i + 1)
        b[bn++] = cal(pre);
      else {
        a[an++] = cal(pre);
        b[bn++] = cal(i);
      }
      pre = -1;
    } else {
      if (pre == -1) pre = i;
    }
  }
  return an + bn;
}
int main() {
  int i, j;
  while (scanf("%s", s + 1) != EOF) {
    s[0] = '0';
    printf("%d\n", gao());
    for (i = 0; i < an; i++) printf("-2^%d\n", a[i]);
    for (i = 0; i < bn; i++) printf("2^%d\n", b[i]);
    memset(s, 0, sizeof(s));
  }
  return 0;
}
