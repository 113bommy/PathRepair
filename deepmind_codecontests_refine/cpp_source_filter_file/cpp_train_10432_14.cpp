#include <bits/stdc++.h>
const int mxn = 2005;
int n, ans = 0;
bool r[mxn], u[mxn], l[mxn], d[mxn], a[mxn][mxn];
int main() {
  int i, j, k;
  char ss[mxn];
  memset(r, 0, sizeof(r));
  memset(u, 0, sizeof(u));
  memset(l, 0, sizeof(l));
  memset(d, 0, sizeof(d));
  scanf("%d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%s", ss);
    for (j = 1; j <= n; j++)
      if (ss[j - 1] == '0')
        a[i][j] = 0;
      else
        a[i][j] = 1;
  }
  for (k = n - 1; k > 0; k--) {
    for (i = 1; i + k <= n; i++) {
      j = i + k;
      if (a[i][j] ^ r[i] ^ u[j]) {
        ans++;
        r[i] ^= 1;
        u[j] ^= 1;
      }
    }
    for (i = 5; i - k >= 1; i--) {
      j = i - k;
      if (a[i][j] ^ l[i] ^ d[j]) {
        ans++;
        l[i] ^= 1;
        d[j] ^= 1;
      }
    }
  }
  for (i = 1; i <= n; i++)
    if (a[i][i] ^ r[i] ^ l[i] ^ u[i] ^ d[i]) ans++;
  printf("%d\n", ans);
  return 0;
}
