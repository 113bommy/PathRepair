#include <bits/stdc++.h>
int n, m, i, a[300010], b[300010], dp, p[300010], pre[300010], num[300010],
    tt[300010], flag[300010];
int ans, l[300010], r[300010];
void link(int x, int y, int z) {
  dp++;
  pre[dp] = p[x];
  p[x] = dp;
  tt[dp] = y;
  num[dp] = z;
}
int dfs(int x) {
  int i, z, tmp;
  tmp = 0;
  i = p[x];
  while (i) {
    if (flag[num[i]] == 0) {
      flag[num[i]] = 1;
      z = dfs(tt[i]);
      if (z) {
        ans++;
        l[ans] = z;
        r[ans] = num[i];
      } else {
        if (tmp == 0)
          tmp = num[i];
        else {
          ans++;
          l[ans] = tmp;
          r[ans] = num[i];
          tmp = 0;
        }
      }
    }
    i = pre[i];
  }
  return tmp;
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &a[i], &b[i]);
    link(a[i], b[i], i);
    link(b[i], a[i], i);
  }
  if (m % 2 == 1) {
    printf("No solution");
    return 0;
  } else {
    int u, v, uu, vv;
    dfs(1);
    for (i = 1; i <= ans; i++) {
      u = a[l[i]];
      v = b[l[i]];
      uu = a[r[i]];
      vv = b[r[i]];
      if (u == uu)
        printf("%d %d %d\n", v, u, vv);
      else if (u == vv)
        printf("%d %d %d\n", v, u, uu);
      else if (v == uu)
        printf("%d %d %d\n", u, v, vv);
      else if (v == vv)
        printf("%d %d %d\n", u, v, uu);
    }
  }
}
