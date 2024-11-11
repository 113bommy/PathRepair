#include <bits/stdc++.h>
using namespace std;
const int N = 1000009;
int head[N], cnt, n, m, dep[N], K, id[N], flag, F[N], vis[N], ans1[N], ans2[N];
struct Edge {
  int nxt, to;
} g[N * 2];
void add(int from, int to) {
  g[++cnt].nxt = head[from];
  g[cnt].to = to;
  head[from] = cnt;
}
void init() {
  scanf("%d %d", &n, &m);
  K = n + 1 >> 1;
  cnt = 0;
  for (int i = 1; i <= n; i++) F[i] = dep[i] = head[i] = vis[i] = 0;
  for (int x, y, i = 1; i <= m; i++)
    scanf("%d %d", &x, &y), add(x, y), add(y, x);
}
void dfs(int x, int fa) {
  if (flag) return;
  vis[x] = 1;
  for (int i = head[x]; i; i = g[i].nxt) {
    int v = g[i].to;
    if (v == fa || vis[v]) continue;
    dep[v] = dep[x] + 1, F[v] = x;
    if (!flag && dep[v] >= K - 1) {
      puts("PATH");
      printf("%d\n", K);
      while (v) printf("%d ", v), v = F[v];
      puts("");
      flag = 1;
    }
    dfs(v, x);
  }
}
bool cmp(int a, int b) { return dep[a] < dep[b]; }
void work() {
  int T;
  scanf("%d", &T);
  while (T--) {
    init();
    flag = 0;
    dfs(1, -1);
    if (!flag) {
      puts("PAIRING");
      int tot = 0;
      for (int i = 1; i <= n; i++) id[i] = i;
      sort(id + 1, id + 1 + n, cmp);
      for (int i = 1; i <= n; i++)
        if (dep[id[i]] == dep[id[i + 1]])
          ans1[++tot] = id[i], ans2[tot] = id[i + 1], i++;
      printf("%d\n", tot);
      for (int i = 1; i <= tot; i++) printf("%d %d\n", ans1[i], ans2[i]);
    }
  }
}
int main() {
  work();
  return 0;
}
