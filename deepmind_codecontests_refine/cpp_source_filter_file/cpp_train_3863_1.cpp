#include <bits/stdc++.h>
const int mod = 1000000007;
int i, j, k, l, m, n, a[100000];
int c[1000000];
int d[100001][2];
int e[100001][2];
long long f[1000001];
int h[1000001];
int g[1000001][3], pg;
int o[100001][2];
long long s[1000001];
void qsort(int x, int y) {
  int l = x, r = y, m = g[(x + y) / 2][0], t;
  do {
    while (g[l][0] < m) l++;
    while (g[r][0] > m) r--;
    if (!(l > r)) {
      t = g[l][0];
      g[l][0] = g[r][0];
      g[r][0] = t;
      t = g[l][1];
      g[l][1] = g[r][1];
      g[r][1] = t;
      t = g[l][2];
      g[l][2] = g[r][2];
      g[r][2] = t;
      l++;
      r--;
    }
  } while (!(l > r));
  if (l < y) qsort(l, y);
  if (x < r) qsort(x, r);
}
void chuli(int x, int y) {
  int i, j, k, l;
  for (i = x; i <= y; i++) {
    o[g[i][1]][g[i][2]] = x;
    if (g[i][2] == 1) {
      f[x] = (f[x] + s[x - 1] - s[o[g[i][1]][0] - 1]) % mod;
    }
  }
  s[x] = (s[x - 1] + f[x]) % mod;
  for (i = x + 1; i <= y; i++) {
    s[i] = s[i - 1];
  }
}
int main() {
  scanf("%d%d", &n, &m);
  n++;
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &e[i][0], &e[i][1]);
    e[i][0]++;
    e[i][1]++;
    pg++;
    g[pg][0] = e[i][0];
    g[pg][1] = i;
    g[pg][2] = 0;
    pg++;
    g[pg][0] = e[i][1];
    g[pg][1] = i;
    g[pg][2] = 1;
  }
  i++;
  e[i][0] = n;
  e[i][1] = n + 1;
  pg++;
  g[pg][0] = e[i][0];
  g[pg][1] = i;
  g[pg][2] = 0;
  pg++;
  g[pg][0] = e[i][1];
  g[pg][1] = i;
  g[pg][2] = 1;
  i++;
  e[i][0] = 0;
  e[i][1] = 1;
  pg++;
  g[pg][0] = e[i][0];
  g[pg][1] = i;
  g[pg][2] = 0;
  pg++;
  g[pg][0] = e[i][1];
  g[pg][1] = i;
  g[pg][2] = 1;
  m++;
  m++;
  n++;
  memcpy(d, e, sizeof(e));
  qsort(1, pg);
  f[1] = 1;
  s[1] = 1;
  for (i = 1; i <= pg;) {
    for (j = i;; j++) {
      if (g[j][0] != g[i][0]) break;
    }
    if (j > pg) k = i;
    chuli(i, j - 1);
    i = j;
  }
  k = (f[k] + mod) % mod;
  printf("%d\n", k);
  return 0;
}
