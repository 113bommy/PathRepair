#include <bits/stdc++.h>
using namespace std;
int n, m, x[500010], y[500010];
bitset<4005> a[2005];
int gi() {
  int w = 0;
  char ch = getchar();
  while ((ch < '0') || ('9' < ch)) ch = getchar();
  while (('0' <= ch) && (ch <= '9')) w = w * 10 + ch - '0', ch = getchar();
  return w;
}
void gauss() {
  for (int i = 1; i <= n; i++) {
    if (!a[i][i]) {
      for (int j = i + 1; j <= n; j++)
        if (a[j][i]) {
          swap(a[i], a[j]);
          break;
        }
    }
    for (int j = i + 1; j <= n; j++)
      if (a[j][i]) a[j] ^= a[i];
  }
  for (int i = n; i; i--)
    for (int j = i + 1; j <= n; j++)
      if (a[i][j]) a[i] ^= a[j];
}
void work() {
  n = gi(), m = gi();
  for (int i = 1; i <= m; i++) x[i] = gi(), y[i] = gi(), a[x[i]][y[i]] = 1;
  for (int i = 1; i <= n; i++) a[i][i + n] = 1;
  gauss();
  for (int i = 1; i <= m; i++) puts(a[x[i]][y[i] + n] ? "NO" : "YES");
}
int main() {
  work();
  return 0;
}
