#include <bits/stdc++.h>
using namespace std;
int i, j, k, n, m, ch, ff, ans;
void R(int &x) {
  x = ff = 0;
  ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') ff = 1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  if (ff) x = -x;
}
void R(long long &x) {
  x = ff = 0;
  ch = getchar();
  while (ch < '0' || '9' < ch) {
    if (ch == '-') ff = 1;
    ch = getchar();
  }
  while ('0' <= ch && ch <= '9') x = x * 10 + ch - '0', ch = getchar();
  if (ff) x = -x;
}
void W(int x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) W(x / 10);
  putchar(x % 10 + '0');
}
void W(long long x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) W(x / 10);
  putchar(x % 10 + '0');
}
int main() {
  R(n);
  if (n % 2 == 1) {
    ans = 2;
    for (i = 4; i <= n; i += 2) {
      ans += 2;
      for (j = 2; j < i; j += 2) ans += 2;
    }
  } else {
    ans = 3;
    for (i = 5; i <= n; i += 2) {
      ans += 3;
      for (j = 3; j < i; j += 2) ans += 2;
    }
  }
  printf("%d\n", ans);
  if (n % 2 == 1) {
    puts("3 1 2 3");
    puts("3 1 2 3");
    for (i = 4; i <= n; i += 2) {
      printf("3 %d %d %d\n", 1, i, i + 1);
      printf("3 %d %d %d\n", 1, i, i + 1);
      for (j = 2; j < i; j += 2) {
        printf("4 %d %d %d %d\n", i, j, i + 1, j + 1);
        printf("4 %d %d %d %d\n", i, j, i + 1, j + 1);
      }
    }
    return 0;
  } else {
    puts("4 1 2 3 4");
    puts("4 1 3 4 2");
    puts("4 1 2 4 3");
    for (i = 5; i <= n; i += 2) {
      printf("3 %d %d %d\n", 1, i, i + 1);
      printf("3 %d %d %d\n", 2, i, i + 1);
      printf("4 %d %d %d %d\n", 1, i, 2, i + 1);
      for (j = 3; j < i; j += 2) {
        printf("4 %d %d %d %d\n", i, j, i + 1, j + 1);
        printf("4 %d %d %d %d\n", i, j, i + 1, j + 1);
      }
    }
  }
}
