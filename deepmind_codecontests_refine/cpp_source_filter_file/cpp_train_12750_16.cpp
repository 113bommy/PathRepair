#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch <= '9' && ch >= '0') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n;
char s[100];
int a[100], b[100];
int main() {
  while (scanf("%d", &n) > 0) {
    scanf("%s", s);
    int len = strlen(s), i = 0, t = 1;
    while (s[i] == '0') i++;
    for (; i < len; i++) {
      a[t++] = s[i] - '0';
    }
    memset(b, 0, sizeof(b));
    for (int i = 1; i < t; i++) {
      if (a[i] <= 1) continue;
      if (a[i] == 2) {
        b[2]++;
      }
      if (a[i] == 3) {
        b[3]++;
      }
      if (a[i] == 4) {
        b[2] += 1;
        b[3]++;
      }
      if (a[i] == 5) {
        b[5]++;
      }
      if (a[i] == 6) {
        b[3] += 1;
        b[5]++;
      }
      if (a[i] == 7) {
        b[7]++;
      }
      if (a[i] == 8) {
        b[2] += 3;
        b[7]++;
      }
      if (a[i] == 9) {
        b[2] += 1;
        b[3] += 2;
        b[7]++;
      }
    }
    for (int i = 9; i >= 2; i--) {
      if (b[i]) {
        while (b[i]--) printf("%d", i);
      }
    }
    puts("");
  }
}
