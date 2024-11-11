#include <bits/stdc++.h>
using namespace std;
const int md = 1e6 + 3;
int n, m, a[2005], b[2005], x[2005], y[2005];
int f[2005][2005];
char s[2005];
int main() {
  scanf("%s", s);
  n = strlen(s);
  for (int i = 0; i < n; i++)
    if ((s[i] == '*' || s[i] == '/') &&
        (i == 0 || s[i - 1] < '0' || s[i - 1] > '9')) {
      puts("0");
      return 0;
    }
  a[0] = 1;
  for (int i = 0; i < n; i++)
    if (s[i] < '0' || s[i] > '9')
      a[m]++;
    else if (i == 0 || a[m])
      m++;
  if (a[m]) {
    puts("0");
    return 0;
  }
  n = 0;
  for (int i = 0; i < m; i++) {
    b[i] = n;
    for (int j = a[i] - 1; j >= 0; j--) {
      x[n] = i;
      y[n++] = j;
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    f[i][x[i]] = 1;
    for (int j = x[i] + 1; j < m; j++) {
      if (y[i])
        f[i][j] = f[i + 1][j];
      else
        f[i][j] = 0;
      long long del = 0;
      for (int k = x[i]; k < j; k++) del += 1ll * f[i][k] * f[b[k + 1]][j];
      f[i][j] = (f[i][j] + del) % md;
    }
  }
  printf("%d\n", f[0][m - 1]);
  return 0;
}
