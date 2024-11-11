#include <bits/stdc++.h>
using namespace std;
int cond = 1;
char s[113][113];
int main() {
  int n, m, a, b, c;
  scanf("%d %d %d %d %d", &n, &m, &a, &b, &c);
  int nn = n, mm = m;
  if (n % 2 && m % 2) {
    puts("IMPOSSIBLE");
    return 0;
  }
  if (n % 2) {
    if (a + a < m) {
      puts("IMPOSSIBLE");
      return 0;
    }
    a -= m / 2;
    n--;
    for (int i = 0; i < (mm); i++) s[n][i] = 'a' + (i % 4 > 2);
  }
  if (m % 2) {
    if (b + b < n) {
      puts("IMPOSSIBLE");
      return 0;
    }
    b -= n / 2;
    m--;
    for (int i = 0; i < (nn); i++) s[i][m] = 'a' + (i % 4 > 2);
  }
  if (a / 2 + b / 2 + c < (n / 2) * (m / 2)) {
    puts("IMPOSSIBLE");
    return 0;
  }
  for (int i = 0; i < n; i += 2)
    for (int j = 0; j < m; j += 2)
      if (c) {
        c--;
        s[i][j] = s[i + 1][j] = s[i][j + 1] = s[i + 1][j + 1] =
            'c' + i % 4 + j % 4;
      } else if (b > 1) {
        b -= 2;
        s[i][j] = s[i + 1][j] = 'j' + i % 4 + j % 4;
        s[i][j + 1] = s[i + 1][j + 1] = 'c' + i % 4 + j % 4;
      } else {
        a -= 2;
        s[i + 1][j + 1] = s[i + 1][j] = 'j' + i % 4 + j % 4;
        s[i][j + 1] = s[i][j] = 'c' + i % 4 + j % 4;
      }
  for (int i = 0; i < (nn); i++) {
    s[i][mm] = 0;
    puts(s[i]);
  }
  return 0;
}
