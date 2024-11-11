#include <bits/stdc++.h>
using namespace std;
char c[505];
int a[505][505], f[250005], g[250005], h[250005], s;
bool v[505][505];
int find(int x) {
  if (f[x] == x)
    return x;
  else
    return f[x] = find(f[x]);
}
void merge(int x) {
  x = find(x);
  if (!g[x]) s += h[x];
  g[x]++;
}
void del(int x) {
  x = find(x);
  g[x]--;
  if (!g[x]) s -= h[x];
}
int main() {
  int n, k, i, j, l, p, u, z, ans = 0;
  scanf("%d%d", &n, &k);
  memset(v, 1, sizeof(v));
  for (i = 1; i <= n; i++) {
    scanf("%s", c + 1);
    for (j = 1; j <= n; j++) {
      a[i][j] = (i - 1) * n + j;
      if (c[j] == '.') {
        v[i][j] = false;
        f[a[i][j]] = a[i][j];
        h[a[i][j]] = 1;
      }
    }
  }
  for (i = 1; i <= n; i++) {
    for (j = 1; j < n; j++) {
      if (!v[i][j] && !v[i][j + 1]) {
        u = find(a[i][j]);
        z = find(a[i][j + 1]);
        if (u != z) {
          f[u] = z;
          h[z] += h[u];
        }
      }
    }
  }
  for (i = 1; i < n; i++) {
    for (j = 1; j <= n; j++) {
      if (!v[i][j] && !v[i + 1][j]) {
        u = find(a[i][j]);
        z = find(a[i + 1][j]);
        if (u != z) {
          f[u] = z;
          h[z] += h[u];
        }
      }
    }
  }
  for (l = 1; l <= n - k + 1; l++) {
    memset(g, 0, sizeof(g));
    s = 0;
    for (i = l; i <= l + k - 1; i++) {
      for (j = 1; j <= k; j++) {
        if (v[i][j])
          s++;
        else
          merge(a[i][j]);
      }
    }
    for (i = 1; i <= k; i++) {
      if (!v[l - 1][i]) merge(a[l - 1][i]);
      if (!v[l + k][i]) merge(a[l + k][i]);
      if (!v[l + i - 1][0]) merge(a[l + i - 1][0]);
      if (!v[l + i - 1][k + 1]) merge(a[l + i - 1][k + 1]);
    }
    ans = max(ans, s);
    for (p = 2; p < n - k + 1; p++) {
      for (i = 1; i <= k; i++) {
        if (!v[l + i - 1][p - 2]) del(a[l + i - 1][p - 2]);
        if (v[l + i - 1][p - 1]) s--;
        if (v[l + i - 1][p + k - 1]) s++;
        if (!v[l + i - 1][p + k]) merge(a[l + i - 1][p + k]);
      }
      if (!v[l - 1][p - 1]) del(a[l - 1][p - 1]);
      if (!v[l + k][p - 1]) del(a[l + k][p - 1]);
      if (!v[l - 1][p + k - 1]) merge(a[l - 1][p + k - 1]);
      if (!v[l + k][p + k - 1]) merge(a[l + k][p + k - 1]);
      ans = max(ans, s);
    }
  }
  printf("%d\n", ans);
  return 0;
}
