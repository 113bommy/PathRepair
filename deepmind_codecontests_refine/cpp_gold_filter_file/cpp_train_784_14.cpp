#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m, now;
char s[107], f[3][107];
void check(int &x) {
  x++;
  if (x == now) x++;
  if (x > n) x = 1;
}
int main() {
  scanf("%s", s + 1);
  n = 27;
  m = 13;
  for (int i = 1; i <= n; i++)
    for (int j = i + 2; j <= n; j++) {
      if (s[i] == s[j]) {
        int lastx = m - (j - i - 1) / 2, k = i;
        now = j;
        f[1][lastx] = s[k];
        for (int x = lastx + 1; x <= m; x++) check(k), f[1][x] = s[k];
        for (int x = m; x >= 1; x--) check(k), f[2][x] = s[k];
        for (int x = 1; x <= lastx - 1; x++) check(k), f[1][x] = s[k];
        for (int i = 1; i <= 2; i++) {
          for (int j = 1; j <= m; j++) printf("%c", f[i][j]);
          if (i == 1) printf("\n");
        }
        return 0;
      }
    }
  printf("Impossible\n");
}
