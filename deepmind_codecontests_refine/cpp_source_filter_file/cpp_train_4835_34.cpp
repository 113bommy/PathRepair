#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int a[101][101], b[101][101], cp[101];
int main() {
  int n, m, p;
  memset(cp, 0, sizeof(cp));
  scanf("%d %d %d", &n, &m, &p);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j) scanf("%d", &b[i][j]);
  if (n > m) {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) a[j][i] = b[i][j];
    swap(n, m);
  } else {
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j) a[i][j] = b[i][j];
  }
  if (n == 1) {
    printf("0\n");
    return 0;
  }
  if (m <= 20) {
    int ans = 1e9;
    for (int i = 0; i < (1 << (n)); ++i) {
      int c = 0;
      for (int k = 0; k < m; ++k) {
        int q = 0;
        for (int j = 0; j < n; ++j)
          if (a[j][k] ^ ((i >> (j)) & 1) == 1) q++;
        c += min(q, n - (q));
        if (c > p) break;
      }
      ans = min(ans, c);
    }
    if (ans > p)
      printf("-1\n");
    else
      printf("%d\n", ans);
    return 0;
  }
  for (int i = 1; i < n; ++i) {
    int c = 0;
    for (int j = 0; j < m; ++j)
      if (a[0][j] == a[i][j]) c++;
    if (c > p && m - c > p) {
      printf("-1\n");
      return 0;
    } else if (c <= p) {
      cp[i] = 1;
    }
  }
  int c = 0;
  for (int k = 0; k < m; ++k) {
    int q = 0;
    for (int j = 0; j < n; ++j)
      if (a[j][k] ^ cp[j] == 0) q++;
    c = min(q, n - q);
    if (c > p) break;
  }
  if (c > p)
    printf("-1\n");
  else
    printf("%d\n", c);
  return 0;
}
