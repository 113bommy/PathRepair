#include <bits/stdc++.h>
using namespace std;
int n, m, ans, h[200000], a[200000], d[200000], f[200000][18];
long long k, s[200000], w[200000][18];
int main() {
  scanf("%d%d%I64d", &n, &m, &k);
  f[1][0] = 1;
  for (int i = (1); i <= (n); i++) {
    scanf("%d", &s[i]);
    if (s[i] > k) {
      printf("-1");
      return 0;
    }
  }
  for (int i = (2); i <= (n); i++) {
    scanf("%d", &f[i][0]);
    w[i][0] = s[f[i][0]];
    h[i] = h[f[i][0]] + 1;
  }
  for (int j = (1); j <= (17); j++)
    for (int i = (1); i <= (n); i++) {
      f[i][j] = f[f[i][j - 1]][j - 1];
      w[i][j] = w[i][j - 1] + w[f[i][j - 1]][j - 1];
    }
  for (int i = (1); i <= (n); i++) {
    int x = i, y = m - 1;
    long long z = k - s[i];
    for (int j = (17); j >= (0); j--)
      if ((y >= (1 << j)) && (z >= w[x][j])) {
        y -= 1 << j;
        z -= w[x][j];
        x = f[x][j];
      }
    d[i] = x;
  }
  for (int i = (n); i >= (1); i--) {
    if ((!a[i]) || (h[a[i]] > h[i])) a[i] = d[i], ans++;
    if ((i > 1) && ((!a[f[i][0]]) || (h[a[i]] < h[a[f[i][0]]])))
      a[f[i][0]] = a[i];
  }
  printf("%d", ans);
}
