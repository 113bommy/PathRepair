#include <bits/stdc++.h>
int next[2000], ru[2000], cc[2000];
int s[2000], e[2000], d[2000];
bool vis[2000];
int main() {
  int i, j, n, u, v, m, ans, c, minn;
  while (scanf("%d %d", &n, &m) != EOF) {
    ans = 0;
    memset(next, -1, sizeof(next));
    memset(ru, 0, sizeof(ru));
    memset(vis, 0, sizeof(vis));
    for (i = 0; i < m; ++i) {
      scanf("%d %d %d", &u, &v, &c);
      next[u] = v;
      ru[v]++;
      cc[u] = c;
    }
    for (i = 1; i <= n; ++i)
      if (!ru[i]) {
        minn = 99999999;
        u = i;
        s[ans] = i;
        while (next[u] + 1) {
          if (cc[u] < minn) minn = cc[u];
          u = next[u];
        }
        if (u - i) {
          e[ans] = u;
          d[ans++] = minn;
        }
      }
    printf("%d\n", ans);
    for (i = 0; i < ans; ++i) printf("%d %d %d", s[i], e[i], d[i]);
  }
  return 0;
}
