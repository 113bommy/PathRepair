#include <bits/stdc++.h>
using namespace std;
int n, m, s[200005], last[200005], ecnt = 1, ans[200005];
struct edge {
  int next, to;
} e[200005 << 1];
void addedge(int a, int b) {
  e[++ecnt] = (edge){last[a], b};
  last[a] = ecnt;
}
int vis[200005];
void dfs(int x, int fa) {
  vis[x] = 1;
  for (int i = last[x]; i; i = e[i].next) {
    int y = e[i].to;
    if (y == fa) continue;
    if (!vis[y]) {
      dfs(y, x);
      ans[i >> 1] = s[y] * ((i & 1) ? -1 : 1);
      s[x] += s[y];
    }
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &s[i]);
  scanf("%d", &m);
  for (int i = 1; i <= m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    addedge(a, b);
    addedge(b, a);
  }
  dfs(1, 0);
  if (s[1] == 0) {
    puts("Possible");
    for (int i = 1; i <= m; i++) printf("%d\n", ans[i]);
  } else
    puts("Impossible");
}
