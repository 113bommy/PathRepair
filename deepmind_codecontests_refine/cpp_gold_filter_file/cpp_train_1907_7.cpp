#include <bits/stdc++.h>
using namespace std;
int n;
int a[200];
int f[200][200][200], g[200][200];
char s[200];
int t[200];
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch > '9' || ch < '0') {
    if (ch == '-') f = -1;
    ch = getchar();
    if (ch == -1) return 0;
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
inline void write(int x) {
  if (x < 0) {
    putchar('-');
    x = -x;
  }
  if (x >= 10) write(x / 10);
  putchar(x % 10 + '0');
}
int main() {
  n = read();
  for (int i = 1; i <= n; i++) a[i] = read();
  for (int i = 1; i <= n; i++)
    if (a[i] == -1) a[i] = -0x3f3f3f3f;
  scanf("%s", s + 1), memset(f, -0x3f, sizeof(f)), memset(g, -0x3f, sizeof(g));
  for (int i = 1; i <= n + 1; i++) g[i][i - 1] = 0;
  for (int i = n; i >= 1; i--)
    for (int j = i; j <= n; j++)
      for (int k = 1; k <= j - i + 1; k++) {
        if (s[i] == s[j])
          if (k == 1)
            f[i][j][k] = max(g[i][j - 1], g[i + 1][j]);
          else if (k == 2)
            f[i][j][k] = max(f[i][j][k], g[i + 1][j - 1]);
          else
            f[i][j][k] = max(f[i][j][k], f[i + 1][j - 1][k - 2]);
        for (int l = i; l < j; l++)
          f[i][j][k] = max(f[i][j][k], max(f[i][l][k] + g[l + 1][j],
                                           f[l + 1][j][k] + g[i][l]));
        g[i][j] = max(g[i][j], f[i][j][k] + a[k]);
      }
  for (int i = 1; i <= n; i++) {
    t[i] = t[i - 1];
    for (int j = 0; j < i; j++) t[i] = max(t[i], t[j] + g[j + 1][i]);
  }
  cout << t[n] << endl;
  return 0;
}
