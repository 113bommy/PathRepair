#include <bits/stdc++.h>
using namespace std;
const int NR = 1005;
void Min(int& x, int y) { x = min(x, y); }
void Max(int& x, int y) { x = max(x, y); }
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n, m, k;
int a[NR][NR];
char s[NR][NR], t[NR][NR];
int main() {
  n = read(), m = read(), k = read();
  for (int i = 1; i < n; i++) scanf("%s%s", s[i] + 1, t[i] + 1);
  scanf("%s", s[n] + 1);
  if (k == 1) {
    int cnt = 0;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= m; j++) a[i][j] = 1;
    for (int i = 1; i <= n; i++)
      for (int j = 1; j < m; j++)
        if ((a[i][j] ^ a[i][j + 1]) ^ (s[i][j] == 'E')) cnt++;
    for (int i = 1; i < n; i++)
      for (int j = 1; j <= m; j++)
        if ((a[i][j] ^ a[i + 1][j]) ^ (t[i][j] == 'E')) cnt++;
    if (cnt >= (((n - 1) * m + (m - 1) * n) * 3 + 3) / 4) {
      puts("YES");
      for (int i = 1; i <= n; i++, puts(""))
        for (int j = 1; j <= m; j++) printf("1 ");
    } else
      puts("NO");
    return 0;
  }
  if (n <= m) {
    for (int i = 1; i <= n; i++) {
      a[i][1] = 0;
      for (int j = 1; j < m; j++) {
        if (s[i][j] == 'E')
          a[i][j + 1] = a[i][j];
        else
          a[i][j + 1] = (a[i][j] ^ 1);
      }
    }
    for (int i = 2; i <= n; i++) {
      int cnt = 0;
      for (int j = 1; j <= m; j++)
        if ((a[i][j] ^ a[i - 1][j]) ^ (t[i - 1][j] == 'E')) cnt++;
      if (cnt <= m / 2)
        for (int j = 1; j <= m; j++) a[i][j] ^= 1;
    }
    puts("YES");
    for (int i = 1; i <= n; i++, puts(""))
      for (int j = 1; j <= m; j++) printf("%d ", a[i][j] + 1);
  } else {
    for (int j = 1; j <= m; j++) {
      a[1][j] = 1;
      for (int i = 1; i < n; i++) {
        if (t[i][j] == 'E')
          a[i + 1][j] = a[i][j];
        else
          a[i + 1][j] = (a[i][j] ^ 1);
      }
    }
    for (int j = 2; j <= m; j++) {
      int cnt = 0;
      for (int i = 1; i <= n; i++)
        if (a[i][j] ^ a[i][j - 1] ^ (s[i][j - 1] == 'E')) cnt++;
      if (cnt <= n / 2)
        for (int i = 1; i <= n; i++) a[i][j] ^= 1;
    }
    puts("YES");
    for (int i = 1; i <= n; i++, puts(""))
      for (int j = 1; j <= m; j++) printf("%d ", a[i][j] + 1);
  }
  return 0;
}
