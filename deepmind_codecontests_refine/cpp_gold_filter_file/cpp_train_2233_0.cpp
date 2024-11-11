#include <bits/stdc++.h>
int dp, pre[1000010], p[1000010], tt[1000010], ans[1000010], vis[1000010], tot,
    s[1000010], f[1000010], n, m;
int i, a, b, d;
void link(int x, int y) {
  dp++;
  pre[dp] = p[x];
  p[x] = dp;
  tt[dp] = y;
}
void dfs(int x) {
  int i = p[x];
  vis[x] = 1;
  tot++;
  ans[tot] = x;
  s[x]++;
  while (i) {
    if (vis[tt[i]] == 0) {
      dfs(tt[i]);
      tot++;
      ans[tot] = x;
      s[x]++;
      if (s[tt[i]] % 2 != f[tt[i]]) {
        tot++;
        ans[tot] = tt[i];
        s[tt[i]]++;
        tot++;
        ans[tot] = x;
        s[x]++;
      }
    }
    i = pre[i];
  }
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &a, &b);
    link(a, b);
    link(b, a);
  }
  for (i = 1; i <= n; i++) {
    scanf("%d", &f[i]);
    if (f[i] == 1) d = i;
  }
  dfs(d);
  if (s[d] % 2 != f[d]) {
    tot--;
    s[d]--;
  }
  for (i = 1; i <= n; i++)
    if (s[i] % 2 != f[i]) {
      printf("-1");
      return 0;
    }
  printf("%d\n", tot);
  for (i = 1; i <= tot; i++) printf("%d ", ans[i]);
}
