#include <bits/stdc++.h>
inline int read() {
  register int x = 0;
  register int y = 1;
  register char c = std::getchar();
  while (c < '0' || c > '9') {
    if (c == '-') y = 0;
    c = std::getchar();
  }
  while (c >= '0' && c <= '9') {
    x = x * 10 + (c ^ 48);
    c = std::getchar();
  }
  return y ? x : -x;
}
int a[100004];
int main() {
  int n = read();
  for (register int i = 1; i <= n; i++) a[i] = read();
  if (n == 1) {
    puts(a[1] ? "NO" : "YES");
    if (!a[1]) printf("%d", a[1]);
  } else {
    a[0] = 1;
    if (a[n])
      puts("NO");
    else if (!a[n] && !a[n - 1] && a[n - 2]) {
      for (register int i = n - 2; i; i--) {
        if (!a[i]) {
          puts("YES");
          register int j;
          for (j = 1; j < i; j++) printf("%d->", a[j]);
          printf("(0->(");
          j++;
          while (a[j]) printf("1->"), j++;
          printf("0))->0");
          return 0;
        }
      }
      puts("NO");
    } else {
      puts("YES");
      if (a[n - 1]) {
        for (register int i = 1; i < n; i++) printf("%d->", a[i]);
        printf("%d", a[n]);
      } else {
        for (register int i = 1; i <= n - 3; i++) printf("%d->", a[i]);
        printf("(%d->%d)->%d", a[n - 2], a[n - 1], a[n]);
      }
    }
  }
  return 0;
}
