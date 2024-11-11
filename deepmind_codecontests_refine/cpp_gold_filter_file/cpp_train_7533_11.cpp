#include <bits/stdc++.h>
using namespace std;
char f[110][110];
int n, m, a, b, c;
void func();
int main() {
  scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
  getchar();
  if ((n * m) % 2 == 1)
    printf("IMPOSSIBLE\n");
  else {
    if (4 * c + 2 * (a + b) < n * m)
      printf("IMPOSSIBLE\n");
    else
      func();
  }
  return 0;
}
void func() {
  int i, j;
  char ch;
  if (n % 2) a -= m / 2;
  if (m % 2) b -= n / 2;
  for (i = 1; i - 1 < n; i += 2)
    for (j = 1, ch = i / 2 % 2 + 'a'; j - 1 < m; j += 2) {
      f[i][j] = f[i + 1][j] = f[i][j + 1] = f[i + 1][j + 1] = ch;
      if (ch == 'a')
        ch++;
      else
        ch--;
    }
  c -= (n / 2) * (m / 2);
  for (i = 1; i - 1 < n - n % 2; i += 2)
    for (j = 1; j - 1 < m - m % 2; j += 2) {
      if (c < 0 && a >= 2) {
        f[i][j] = f[i][j + 1] = f[i][j + 1] + 2;
        a -= 2;
        c++;
      } else if (c < 0 && b >= 2) {
        f[i][j] = f[i + 1][j] = f[i + 1][j] + 2;
        b -= 2;
        c++;
      }
    }
  if (c < 0 || a < 0 || b < 0)
    printf("IMPOSSIBLE\n");
  else {
    for (i = 1; i <= n; i++) {
      for (j = 1; j <= m; j++) printf("%c", f[i][j]);
      printf("\n");
    }
  }
  return;
}
