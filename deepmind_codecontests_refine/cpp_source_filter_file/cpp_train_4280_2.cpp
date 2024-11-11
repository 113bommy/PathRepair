#include <bits/stdc++.h>
int fa[1010];
int find(int x) {
  if (x != fa[x]) fa[x] = find(fa[x]);
  return fa[x];
}
int main() {
  int n, m;
  while (~scanf("%d%d", &n, &m)) {
    for (int i = 1; i <= n; i++) fa[i] = i;
    int flag, a, b, num, flag2;
    flag = num = flag2 = 0;
    for (int i = 0; i < m; i++) {
      scanf("%d%d", &a, &b);
      if (flag2) continue;
      int px = find(a), py = find(b);
      if (px != py) {
        num++;
        fa[px] = py;
      } else {
        if (!flag) {
          num++;
          flag = 1;
        } else
          flag2 = 1;
      }
    }
    if (!flag2 && flag && num == n)
      printf("FHTAGH!\n");
    else
      printf("NO\n");
  }
  return 0;
}
