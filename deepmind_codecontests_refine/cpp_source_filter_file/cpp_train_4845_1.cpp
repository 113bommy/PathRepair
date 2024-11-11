#include <bits/stdc++.h>
using namespace std;
const int N = 10010;
int i, j, k, t, n;
char s[N];
int f[5][N];
int main() {
  for (i = 1989; i < 10000; i++) {
    if (!f[1][i % 10])
      f[1][i % 10] = i;
    else {
      if (!f[2][i % 100])
        f[2][i % 100] = i;
      else {
        if (!f[3][i % 1000])
          f[3][i % 1000] = i;
        else
          f[4][i] = i;
      }
    }
  }
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    i = 5;
    while (i + 4 <= n && s[i] == '1') i++;
    if (i + 4 <= n) {
      if (s[5] == '0') putchar('1');
      printf("%s\n", s + 5);
    } else {
      j = k = 0;
      while (i <= n) j = j * 10 + s[i] - '0', k++, i++;
      if (f[k][j]) {
        if (n <= 9)
          printf("%d\n", f[k][j]);
        else
          printf("%s\n", s + 5);
      } else {
        putchar('1');
        printf("%s\n", s + 5);
      }
    }
  }
}
