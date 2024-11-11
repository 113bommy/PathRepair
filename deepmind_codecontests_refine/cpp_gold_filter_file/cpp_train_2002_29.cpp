#include <bits/stdc++.h>
int qs[501][501];
char st[501][501];
int n, m;
int qsum(int i, int j, int k, int l) {
  return qs[k][l] - qs[k][j - 1] - qs[i - 1][l] + qs[i - 1][j - 1];
}
int main() {
  int i, j, k;
  int l, r, x;
  long long sum = 0;
  int a, b;
  int s;
  scanf("%d %d %d", &n, &m, &s);
  for (i = 0; i < n; i++) {
    scanf("%s", st[i]);
    for (j = 0; j < m; j++) qs[i][j] = 0;
  }
  for (i = 1; i < n - 1; i++)
    for (j = 1; j < m - 1; j++)
      qs[i][j] =
          (st[i][j] == '1' and st[i - 1][j] == '1' and st[i + 1][j] == '1' and
           st[i][j - 1] == '1' and st[i][j + 1] == '1');
  for (i = 0; i < n; i++)
    for (j = 1; j < m; j++) qs[i][j] += qs[i][j - 1];
  for (i = 0; i < m; i++)
    for (j = 1; j < n; j++) qs[j][i] += qs[j - 1][i];
  for (i = 0; i < n - 2; i++)
    for (j = 0; j < m - 2; j++) {
      for (k = i + 2; k < n; k++) {
        for (l = j + 2, r = m - 1; l <= r;) {
          x = (l + r) / 2;
          a = qsum(i + 1, j + 1, k - 1, x - 1);
          if (a >= s and (x == j + 2 or qsum(i + 1, j + 1, k - 1, x - 2) < s))
            break;
          else if (a >= s)
            r = x - 1;
          else
            l = x + 1;
        }
        if (l < m) sum += m - x;
      }
    }
  printf("%I64d\n", sum);
  return 0;
}
