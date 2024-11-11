#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 100;
int t;
int dep[maxn];
int f[maxn], vis[maxn];
struct edge {
  int next, to;
} a[maxn << 1];
int head[maxn], cnt;
inline void add(int u, int v) {
  a[++cnt].to = v;
  a[cnt].next = head[u];
  head[u] = cnt;
}
vector<int> g[maxn];
void dfs(int u, int fa) {
  g[dep[u] % (t - 1)].push_back(u);
  for (int i = head[u]; i; i = a[i].next) {
    int v = a[i].to;
    if (v == fa) continue;
    if (!dep[v]) {
      dep[v] = dep[u] + 1;
      f[v] = u;
      dfs(v, u);
    } else {
      if (dep[v] - dep[u] + 1 >= t) {
        printf("2\n");
        int len = dep[v] - dep[u] + 1;
        printf("%d\n", len);
        int cnt = 0;
        while (v) {
          if (cnt == len) break;
          cnt++;
          printf("%d ", v);
          v = f[v];
        }
        exit(0);
      }
    }
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  t = ceil(sqrt(n));
  for (int i = 1; i <= m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    add(x, y);
    add(y, x);
  }
  dep[1] = 1;
  dfs(1, 0);
  printf("1\n");
  for (int i = 0; i < t; ++i)
    if (g[i].size() >= t) {
      for (int j = 0, sz = g[i].size(); j < sz && j < t; ++j)
        printf("%d ", g[i][j]);
      return puts(""), 0;
    }
}
