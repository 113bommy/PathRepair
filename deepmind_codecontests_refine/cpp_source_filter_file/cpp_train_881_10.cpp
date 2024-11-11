#include <bits/stdc++.h>
const int p = 1000000007;
int edge[300000], next[300000], ord[300000], first[200000];
int d[200000];
int i, m, n, s, t, x, y, z, sum_edge;
inline void addedge(int x, int y, int z) {
  sum_edge++, edge[sum_edge] = y, next[sum_edge] = first[x], ord[sum_edge] = z,
              first[x] = sum_edge;
  return;
}
inline void dfs(int x) {
  for (int i = first[x]; i != 0; i = next[i])
    if (!(~d[edge[i]])) {
      d[edge[i]] = d[x] ^ ord[i];
      dfs(edge[i]);
    } else if (d[edge[i]] != d[x] ^ ord[i])
      s = 0;
  return;
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d%d", &x, &y, &z);
    addedge(x, y, z), addedge(y, x, z);
  }
  memset(d, 255, sizeof(d));
  s = 1;
  for (i = 1; i <= n; i++)
    if (!(~d[i])) t++, d[i] = 0, dfs(i);
  for (i = 1; i < t; i++) s = s * 2 % p;
  printf("%d", s);
  return 0;
}
