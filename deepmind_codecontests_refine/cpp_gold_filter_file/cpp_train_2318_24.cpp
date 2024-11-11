#include <bits/stdc++.h>
using namespace std;
int read();
long long readll();
int n, m, lim, a[1200009], b[1200009], f[21][1200009], g[1200009], p[21];
char s1[21], s2[21];
int calc(int x) {
  int i, y = 0;
  for (i = 0; i < m; i++)
    if (x >> i & 1) y |= 1 << p[i];
  return y;
}
int main() {
  scanf("%d%d%d%s%s", &n, &lim, &m, s1, s2);
  int i, j, k;
  for (i = 1; i <= n; i++) {
    a[i] = read() - 1;
    b[i] = read() - 1;
  }
  int A = 0, B = 0;
  for (i = 0; i < m; i++) {
    if (s1[i] == '1') A |= 1 << i;
    if (s2[i] == '1') B |= 1 << i;
  }
  memset(f, 60, sizeof(f));
  f[0][A] = g[B] = n + 1;
  for (i = 0; i < m; i++) p[i] = i;
  for (i = n; i; i--) {
    swap(p[a[i]], p[b[i]]);
    (f[0][calc(A)] > (i) ? f[0][calc(A)] = (i) : 0);
    (g[calc(B)] < (i) ? g[calc(B)] = (i) : 0);
  }
  for (i = 0; i < (1 << m); i++)
    if (g[i] - f[0][i] >= lim) {
      printf("%d\n%d %d\n", m, f[0][i], g[i] - 1);
      exit(0);
    }
  for (i = 1; i <= m; i++)
    for (j = 0; j < (1 << m); j++) {
      for (k = i - 1; k < m; k++)
        (f[i][j] > (f[i - 1][j ^ 1 << k]) ? f[i][j] = (f[i - 1][j ^ 1 << k])
                                          : 0);
      if (g[j] - f[i][j] >= lim) {
        printf("%d\n%d %d\n", m - i, f[i][j], g[j] - 1);
        exit(0);
      }
    }
  return 0;
}
int read() {
  int x = 0;
  char ch = getchar();
  bool flag = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return flag ? -x : x;
}
long long readll() {
  long long x = 0;
  char ch = getchar();
  bool flag = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') flag = 1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return flag ? -x : x;
}
