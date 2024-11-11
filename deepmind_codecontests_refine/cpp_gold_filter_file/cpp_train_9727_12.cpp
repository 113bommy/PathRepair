#include <bits/stdc++.h>
using namespace std;
int row[1001][3], col[1001][3], mod;
int pw(int n, int k) {
  int ret = 1;
  while (k > 0) {
    if (k & 1) ret = (long long)ret * n % mod;
    k >>= 1;
    n = (long long)n * n % mod;
  }
  return ret;
}
int main() {
  int n, m, k, a, b, c, ret = 1;
  scanf("%d %d %d", &n, &m, &k);
  if ((m & 1) ^ (n & 1)) {
    printf("0");
    return 0;
  }
  while (k--) {
    scanf("%d %d %d", &a, &b, &c);
    row[a][c + 1]++;
    col[b][c + 1]++;
  }
  scanf("%d", &mod);
  for (k = 1; k <= n; k++)
    if (!row[k][0] && !row[k][2]) break;
  if (k <= n) {
    for (a = 1; a <= n; a++)
      if (a != k) {
        b = m - row[a][0] - row[a][2] - 1;
        if (b == -1 && !(row[a][0] & 1)) {
          ret = 0;
          break;
        }
        ret = (long long)ret * pw(2, b) % mod;
      }
  } else {
    for (k = 1; k <= m; k++)
      if (!col[k][0] && !col[k][2]) break;
    for (a = 1; a <= m; a++)
      if (a != k) {
        b = n - col[a][0] - col[a][2] - 1;
        if (b == -1 && !(col[a][0] & 1)) {
          ret = 0;
          break;
        }
        ret = (long long)ret * pw(2, b) % mod;
      }
  }
  printf("%d", ret);
  return 0;
}
