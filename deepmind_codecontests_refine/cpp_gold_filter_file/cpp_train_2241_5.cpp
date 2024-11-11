#include <bits/stdc++.h>
using namespace std;
int dx[] = {-1, 0, 0, +1, -1, -1, +1, +1};
int dy[] = {0, -1, +1, 0, -1, +1, -1, +1};
int main() {
  int a, b, c, d, n, x[28], v = 0, p = 1;
  char w[51][101], now = 97;
  scanf("%d %d %d %d %d", &a, &b, &c, &d, &n);
  for (int i = 1; i <= n; i++) scanf("%d", &x[i]);
  for (int i = 2; i <= n; i++) x[i] = x[i - 1] + x[i];
  for (int i = 1; i <= max(b, d); i++)
    for (int j = 1; j <= a + c; j++) w[i][j] = '.';
  printf("YES\n");
  if (a % 2 == 0) {
    for (int j = 1; j <= a; j++) {
      if (j % 2 == 1)
        for (int i = 1; i <= b; i++, v++) {
          if (v == x[p]) {
            p++;
            now++;
          }
          w[i][j] = char(now);
        }
      else
        for (int i = b; i >= 1; i--, v++) {
          if (v == x[p]) {
            p++;
            now++;
          }
          w[i][j] = char(now);
        }
    }
  } else {
    for (int j = 1; j <= a; j++) {
      if (j % 2 == 0)
        for (int i = 1; i <= b; i++, v++) {
          if (v == x[p]) {
            p++;
            now++;
          }
          w[i][j] = char(now);
        }
      else
        for (int i = b; i >= 1; i--, v++) {
          if (v == x[p]) {
            p++;
            now++;
          }
          w[i][j] = char(now);
        }
    }
  }
  for (int j = a + 1; j <= a + c; j++) {
    if ((j - a) % 2 == 1)
      for (int i = 1; i <= d; i++, v++) {
        if (v == x[p]) {
          p++;
          now++;
        }
        w[i][j] = now;
      }
    else
      for (int i = d; i >= 1; i--, v++) {
        if (v == x[p]) {
          p++;
          now++;
        }
        w[i][j] = now;
      }
  }
  for (int i = 1; i <= max(b, d); i++) {
    for (int j = 1; j <= a + c; j++) printf("%c", w[i][j]);
    printf("\n");
  }
  return 0;
}
