#include <bits/stdc++.h>
using namespace std;
const int MAXN = (int)1e5 + 10;
const int MAXM = 70;
bool g[MAXM][MAXN], res[MAXN];
int first[MAXM];
int n, m;
long long a[MAXN], sta;
int main() {
  scanf("%d", &n);
  sta = 0;
  for (int i = 0; i < n; i++) scanf("%d", &a[i]), sta ^= a[i];
  for (int i = 60; i >= 0; i--)
    if (!((sta >> i) & 1)) {
      for (int j = 0; j < n; j++) g[m][j] = (a[j] >> i) & 1;
      g[m][n] = true;
      for (int j = 0; j < m; j++)
        if (g[m][first[j]]) {
          for (int k = 0; k <= n; k++) g[m][k] ^= g[j][k];
        }
      first[m] = -1;
      for (int j = 0; j < n; j++)
        if (g[m][j]) {
          first[m] = j;
          break;
        }
      if (first[m] != -1) m++;
    }
  for (int i = 60; i >= 0; i--)
    if (((sta >> i) & 1)) {
      for (int j = 0; j < n; j++) g[m][j] = (a[j] >> i) & 1;
      g[m][n] = false;
      for (int j = 0; j < m; j++)
        if (g[m][first[j]]) {
          for (int k = 0; k <= n; k++) g[m][k] ^= g[j][k];
        }
      first[m] = -1;
      for (int j = 0; j < n; j++)
        if (g[m][j]) {
          first[m] = j;
          break;
        }
      if (first[m] != -1) m++;
    }
  memset(res, false, sizeof(res));
  for (int k = m - 1; k >= 0; k--) {
    res[first[k]] = g[k][n];
    for (int j = 0; j < n; j++)
      if (j != first[k] && g[k][j]) res[first[k]] ^= res[j];
  }
  for (int i = 0; i < n; i++) printf("%d ", ((res[i]) ? 1 : 2));
  printf("\n");
  return 0;
}
