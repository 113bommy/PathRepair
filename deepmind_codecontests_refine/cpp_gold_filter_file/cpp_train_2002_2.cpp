#include <bits/stdc++.h>
using namespace std;
int i, j, t, m, n, k, sum, p;
long long result, h;
char b[512][512];
int a[512][512], c[512][512];
bool kt;
int main() {
  scanf("%d%d%d\n", &m, &n, &k);
  memset(c, 0, sizeof(c));
  memset(a, 0, sizeof(a));
  for (i = 0; i < m; ++i) scanf("%s\n", &b[i]);
  for (i = 1; i < m - 1; ++i)
    for (j = 1; j < n - 1; ++j)
      if (b[i][j] == '1' && b[i - 1][j] == '1' && b[i][j - 1] == '1' &&
          b[i + 1][j] == '1' && b[i][j + 1] == '1') {
        c[i][j] = 1;
      }
  for (i = 1; i < m - 1; ++i)
    for (j = 1; j < n - 1; ++j) a[i][j] = a[i][j - 1] + c[i][j];
  result = 0;
  for (j = 1; j < n - 1; ++j)
    for (i = 1; i <= j; ++i) {
      h = 1;
      sum = 0;
      for (p = 1; p < m - 1; ++p) {
        sum += a[p][j] - a[p][i - 1];
        do {
          kt = false;
          t = a[h][j] - a[h][i - 1];
          if (sum - t >= k && h < p) {
            sum -= t;
            ++h;
            kt = true;
          }
        } while ((sum - t >= k && !kt) || (sum >= k && kt) && h < p);
        if (sum >= k) result += h;
      }
    }
  cout << result;
  return 0;
}
