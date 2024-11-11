#include <bits/stdc++.h>
using namespace std;
int t[12], n, m, k, ans, x, y, a[12][12], q1[1024 * 1024], q2[1024 * 1024],
    v[1024][1024], i1, i2, f[1024][1024], l = 1, r;
int count(int x) {
  int re = 0;
  for (int i = 0; i < n; i++)
    if (x & t[i]) re++;
  return re;
}
int i, j;
int e[11];
int pd(int k) {
  int ret = 0;
  for (int i = 0; i < n; i++)
    if ((k & e[i]) > 0) ret++;
  return ret;
}
int main() {
  scanf("%d %d %d\n", &n, &m, &k);
  t[0] = 1;
  for (int i = 1; i <= n; i++) t[i] = t[i - 1] * 2;
  for (int i = 1; i <= m; i++) {
    scanf("%d %d\n", &x, &y);
    x--;
    y--;
    a[x][y] = a[y][x] = 1;
  }
  for (int i = 0; i < n - 1; i++)
    for (int j = i + 1; j < n; j++)
      if (a[i][j]) {
        q1[++r] = t[i] + t[j];
        q2[r] = t[i] + t[j];
        f[q1[r]][q2[r]] = 1;
        v[q1[r]][q2[r]] = 1;
      }
  while (l <= r) {
    for (int i = 0; i < n; i++)
      if (q1[l] & t[i] > 0) {
        for (int j = n - 1; j >= 0; j--) {
          if ((q1[l] & t[j]) == 0 && a[i][j]) {
            if ((q2[l] & t[i]) > 0)
              x = t[i];
            else
              x = 0;
            i1 = (q1[l] | t[j]);
            i2 = (q2[l] | t[j]) ^ x;
            f[i1][i2] += f[q1[l]][q2[l]];
            if (!v[i1][i2]) q1[++r] = i1, q2[r] = i2, v[i1][i2] = 1;
          }
          if (i != j && (q2[l] & t[j])) break;
        }
      }
    l++;
  }
  for (int i = 0; i < t[n]; i++)
    if (count(i) == k) ans += f[t[n] - 1][i];
  printf("%d\n", ans);
  return 0;
}
