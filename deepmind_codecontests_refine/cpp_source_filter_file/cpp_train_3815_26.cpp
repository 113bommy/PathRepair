#include <bits/stdc++.h>
int n, m;
int edg[2][100010];
int fat[100010], dep[100010], ans[100010];
int fa(int i) {
  if (fat[i] == i) return i;
  fat[i] = fa(fat[i]);
  return fat[i];
}
void uni(int aa, int bb) {
  int a = fa(aa), b = fa(bb);
  if (dep[a] > dep[b])
    fat[b] = a;
  else if (dep[a] < dep[b])
    fat[a] = b;
  else
    ++dep[a], fat[b] = a;
}
int main(void) {
  for (int i = 0; i < 100010; ++i) fat[i] = i;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) scanf("%d%d", &edg[0][i], &edg[1][i]);
  int all = 0;
  for (int i = 0; i < m; ++i) {
    int a = edg[0][i], b = edg[1][i];
    if (fa(a) != fa(b))
      uni(a, b), printf("%d\n", all);
    else {
      uni(a, b);
      int t = fa(a);
      all += ans[t] + 1, ans[t] += ans[t] + 1;
      if (ans[t] > 1000000009) ans[t] -= 1000000009;
      if (all > 1000000009) all -= 1000000009;
      printf("%d\n", all);
    }
  }
  return 0;
}
