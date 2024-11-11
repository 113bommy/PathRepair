#include <bits/stdc++.h>
using namespace std;
inline int read() {
  char ch = getchar();
  int x = 0, f = 1;
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
char s[100010];
long long a[100], tot;
int main() {
  scanf("%s", s);
  int len = strlen(s);
  long long ans = 0, now = 0;
  int cnt = 0;
  for (int i = (0); i <= (len - 1); i++) {
    if (s[i] >= '0' && s[i] <= '9')
      cnt++, now = now * 10 + s[i] - '0';
    else if (s[i] == '.')
      cnt = 0;
    else {
      if (cnt != 2) now *= 100ll;
      cnt = 10;
      ans += now;
      now = 0;
    }
  }
  if (cnt != 2) now *= 100ll;
  ans += now;
  if (ans < 100) {
    if (ans < 10)
      printf("0.0%I64d\n", ans);
    else
      printf("0.%I64d\n", ans);
  } else {
    long long tt = ans % 100, ff = ans / 100;
    while (ff) {
      a[++tot] = ff % 10;
      ff /= 10;
    }
    for (int i = tot; i >= 1; i--) {
      printf("%I64d", a[i]);
      if ((i - 1) % 3 == 0 && i != 1) {
        printf(".");
      }
    }
    if (tt) printf(".%02I64d\n", tt);
  }
  return 0;
}
