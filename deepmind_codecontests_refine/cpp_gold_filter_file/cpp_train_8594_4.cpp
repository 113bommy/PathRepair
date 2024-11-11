#include <bits/stdc++.h>
const int MAXN = 1100000;
char a[MAXN];
int c[2][MAXN];
long long s[2][MAXN];
int main() {
  int n;
  scanf("%d%s", &n, a + 2);
  n += 2;
  a[1] = 'U', a[n] = 'D';
  for (int i = 1; i <= n; i++) {
    c[0][i] = c[0][i - 1] + (a[i] == 'U');
    c[1][i] = c[1][i - 1] + (a[i] == 'D');
    s[0][i] = s[0][i - 1] + (a[i] == 'U') * i;
    s[1][i] = s[1][i - 1] + (a[i] == 'D') * i;
  }
  for (int i = 2; i <= n - 1; i++) {
    int c0 = c[0][i - 1], c1 = c[1][n] - c[1][i];
    if (a[i] == 'U' && c0 < c1) {
      int l = i + 1, r = n;
      while (l < r) {
        int mid = l + r >> 1;
        if (c[1][mid] - c[1][i] >= c0)
          r = mid;
        else
          l = mid + 1;
      }
      printf("%lld ", 2 * ((s[1][l] - s[1][i]) - s[0][i - 1]) - i + 1);
    } else if (a[i] == 'D' && c0 > c1) {
      int l = 1, r = i - 1;
      while (l < r) {
        int mid = l + r + 1 >> 1;
        if (c[0][i - 1] - c[0][mid - 1] >= c1)
          l = mid;
        else
          r = mid - 1;
      }
      printf("%lld ",
             2 * ((s[1][n] - s[1][i]) - (s[0][i - 1] - s[0][l - 1])) + i - n);
    } else if (a[i] == 'U') {
      int l = 1, r = i;
      while (l < r) {
        int mid = l + r + 1 >> 1;
        if (c[0][i - 1] - c[0][mid - 1] >= c1 - 1)
          l = mid;
        else
          r = mid - 1;
      }
      printf("%lld ",
             2 * ((s[1][n] - s[1][i]) - (s[0][i - 1] - s[0][l - 1])) - i - n);
    } else {
      int l = i, r = n;
      while (l < r) {
        int mid = l + r >> 1;
        if (c[1][mid] - c[1][i] >= c0 - 1)
          r = mid;
        else
          l = mid + 1;
      }
      printf("%lld ", 2 * ((s[1][l] - s[1][i]) - s[0][i - 1]) + i + 1);
    }
  }
  putchar('\n');
  return 0;
}
