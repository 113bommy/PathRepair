#include <bits/stdc++.h>
inline int F() {
  register int aa, bb, ch;
  while (ch = getchar(), (ch < '0' || ch > '9') && ch != '-')
    ;
  ch == '-' ? aa = bb = 0 : (aa = ch - '0', bb = 1);
  while (ch = getchar(), ch >= '0' && ch <= '9') aa = aa * 10 + ch - '0';
  return bb ? aa : -aa;
}
int a[7], b[7], d[7], c[100010];
char s[11];
int get() {
  int flag = 0;
  scanf("%s", s + 1);
  int len = strlen(s + 1);
  for (int i = 1; i <= len; ++i)
    if (s[i] == ',') flag = i;
  if (flag) {
    if (s[1] == 'S') return 7;
    if (s[1] == 'M') return 8;
    if (s[1] == 'L') return 9;
    if (s[2] == 'L') return 10;
    if (s[3] == 'L') return 11;
  } else {
    if (s[1] == 'S') return 1;
    if (s[1] == 'M') return 2;
    if (s[1] == 'L') return 3;
    if (s[2] == 'L') return 4;
    if (s[3] == 'L') return 5;
    if (s[4] == 'L') return 6;
  }
  return 0;
}
int main() {
  for (int i = 1; i <= 6; ++i) a[i] = F();
  int n = F(), now;
  for (int i = 1; i <= n; ++i) {
    now = c[i] = get();
    if (now <= 6)
      --a[now];
    else
      ++b[now - 6];
  }
  bool flag = 1;
  for (int i = 1; i <= 5; ++i) {
    if (a[i] < 0 || a[i + 1] < 0) flag = 0;
    int now = a[i] - d[i];
    if (now >= b[i])
      d[i + 1] = 0;
    else
      d[i + 1] = b[i] - now;
    if (a[i + 1] - d[i + 1] < 0) flag = 0;
  }
  if (!flag) {
    puts("NO");
  } else {
    puts("YES");
    for (int i = 1; i <= n; ++i)
      if (c[i] <= 6) {
        if (c[i] == 1) puts("S");
        if (c[i] == 2) puts("M");
        if (c[i] == 3) puts("L");
        if (c[i] == 4) puts("XL");
        if (c[i] == 5) puts("XXL");
        if (c[i] == 6) puts("XXXL");
      } else {
        if (c[i] == 7)
          if (d[2]) {
            --d[2], puts("M");
          } else
            puts("S");
        if (c[i] == 8)
          if (d[3]) {
            --d[3], puts("L");
          } else
            puts("M");
        if (c[i] == 9)
          if (d[4]) {
            --d[4], puts("XL");
          } else
            puts("L");
        if (c[i] == 10)
          if (d[5]) {
            --d[5], puts("XXL");
          } else
            puts("XL");
        if (c[i] == 11)
          if (d[6]) {
            --d[6], puts("XXXL");
          } else
            puts("XXL");
      }
  }
}
