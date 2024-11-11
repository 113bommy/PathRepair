#include <bits/stdc++.h>
using namespace std;
using LL = long long;
char s[10];
int f[600];
int main() {
  int n;
  scanf("%d", &n);
  int a = 1, b = 1, x = n, y = n;
  for (int i = 0; i < n - 1; i++) {
    printf("? %d %d %d %d\n", b, a, y - 1, x);
    fflush(stdout);
    scanf("%s", s);
    if (s[0] == 'B')
      while (1)
        ;
    if (s[0] == 'Y') {
      y--;
    } else
      x--;
    if (s[0] == 'Y')
      f[x + y] = 1;
    else
      f[x + y] = 0;
  }
  a = 1, b = 1, x = n, y = n;
  for (int i = 0; i < n - 1; i++) {
    printf("? %d %d %d %d\n", b, a + 1, y, x);
    fflush(stdout);
    scanf("%s", s);
    if (s[0] == 'B')
      while (1)
        ;
    if (s[0] == 'Y')
      f[a + b] = 0;
    else
      f[a + b] = 1;
    if (s[0] == 'Y') {
      a++;
    } else
      b++;
  }
  printf("! ");
  for (int i = 2; i < 2 * n; i++) {
    printf("%c", "RD"[f[i]]);
  }
  printf("\n");
  fflush(stdout);
}
