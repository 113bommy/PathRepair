#include <bits/stdc++.h>
using namespace std;
int f[50][100][100];
int func(int x, int n) {
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (x % 2 == 0) res++;
    x /= 2;
  }
  return res;
}
int main() {
  int m, n, s, l, i, j, k, p, ans;
  scanf("%d%d", &m, &n);
  if (m < n) {
    int t = m;
    m = n;
    n = t;
  }
  s = 1 << n;
  memset(f, -1, sizeof(f));
  for (i = 0; i < s; i++) f[1][0][i] = func(i, n);
  for (l = 2; l <= m + 1; l++)
    for (i = 0; i < s; i++)
      for (j = 0; j < s; j++)
        if (f[l - 1][i][j] != -1)
          for (k = 0; k < s; k++) {
            for (p = 0; p < n; p++)
              if ((j & (1 << p)) == 0)
                if (p == 0 || (j & (1 << (p - 1))) == 0)
                  if (p == n - 1 || (j & (1 << (p + 1))) == 0)
                    if ((i & (1 << p)) == 0 && (k & (1 << p)) == 0) break;
            if (p == n)
              f[l][j][k] = max(f[l][j][k], f[l - 1][i][j] + func(k, n));
          }
  ans = -1;
  for (i = 0; i < s; i++) ans = max(ans, f[m + 1][i][0] - n);
  printf("%d\n", ans);
}
