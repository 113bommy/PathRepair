#include <bits/stdc++.h>
int du[100010], fa[100010], s1[100010], s2[100010];
int find(int x) {
  if (x != fa[x]) fa[x] = find(fa[x]);
  return fa[x];
}
int main() {
  int n, m, x, y, i, j, k, sum;
  scanf("%d%d", &n, &m);
  for (i = 1; i <= n; i++) fa[i] = i;
  memset(du, 0, sizeof(du));
  memset(s1, 0, sizeof(s1));
  memset(s2, 0, sizeof(s2));
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &x, &y);
    j = find(x);
    k = find(y);
    du[x]++;
    du[y]++;
    if (j != k) {
      if (j < k)
        fa[k] = j;
      else
        fa[j] = k;
    }
  }
  for (i = 1; i <= n; i++) {
    j = find(i);
    s1[j] = s1[j] + du[i];
    s2[j]++;
  }
  sum = 0;
  for (i = 1; i <= n; i++)
    if (s1[i] != 0) {
      j = s1[i] / 2;
      if (j < s2[i]) sum = sum + s2[i] - j;
    }
  printf("%d\n", sum);
}
