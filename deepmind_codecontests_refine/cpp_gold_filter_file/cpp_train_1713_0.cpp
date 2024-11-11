#include <bits/stdc++.h>
int edge[200000], ord[200000], next[200000], first[200000];
int g[200000], h[200000], q[200000], w[200000];
int i, j, m, n, t, x, y, l, r, mid, sum_edge;
inline void addedge(int x, int y, int z) {
  sum_edge++, edge[sum_edge] = y, ord[sum_edge] = z, next[sum_edge] = first[x],
              first[x] = sum_edge;
  return;
}
inline double slope(int x, int y) {
  return 1.0 * ((x * g[x] - h[x - 1]) - (y * g[y] - h[y - 1])) / (g[x] - g[y]);
}
int main() {
  scanf("%d", &n);
  for (i = 1; i <= n; i++) scanf("%d", &g[i]), h[i] = h[i - 1] + g[i];
  scanf("%d", &m);
  for (i = 1; i <= m; i++) scanf("%d%d", &x, &y), addedge(y, x, i);
  for (i = 1; i <= n; i++) {
    for (; (t > 0) && (g[q[t]] >= g[i]); t--)
      ;
    for (; (t > 1) && (slope(q[t - 1], q[t]) > slope(q[t], i)); t--)
      ;
    t++, q[t] = i;
    for (j = first[i]; j != 0; j = next[j]) {
      x = edge[j], y = ord[j];
      l = 1, r = t;
      while (l < r) {
        mid = (l + r) / 2;
        if (i - q[mid] < x)
          r = mid;
        else
          l = mid + 1;
      }
      r = t;
      while (l < r) {
        mid = (l + r) / 2;
        if (slope(q[mid], q[mid + 1]) >= i - x + 1)
          r = mid;
        else
          l = mid + 1;
      }
      w[y] = h[i] - h[q[l] - 1] + (x - i + q[l] - 1) * g[q[l]];
    }
  }
  for (i = 1; i <= m; i++) printf("%d\n", w[i]);
  return 0;
}
