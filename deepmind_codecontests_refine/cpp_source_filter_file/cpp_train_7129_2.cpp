#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
vector<int> g[N];
int comp[N], cur;
int dist[N], q[N], res, last, l, r, color[N];
bool was[N];
void bfs(int v) {
  l = r = 0;
  q[r++] = v;
  dist[v] = 0;
  was[v] = 1;
  while (l < r) {
    int now = q[l++];
    last = now;
    for (int to : g[now]) {
      if (!was[to]) {
        q[r++] = to;
        dist[to] = dist[now] + 1;
        was[to] = 1;
      }
    }
  }
  for (int i = 0; i < r; i++) {
    was[q[i]] = 0;
  }
}
void dfs(int v) {
  comp[v] = cur;
  for (int to : g[v]) {
    if (!comp[to]) {
      color[to] = 1 - color[v];
      dfs(to);
    } else {
      if (color[to] != 1 - color[v]) {
        puts("-1");
        exit(0);
      }
    }
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    g[a].push_back(b);
    g[b].push_back(a);
  }
  for (int i = 1; i <= n; i++) {
    if (!comp[i]) {
      int add = 0;
      cur++;
      dfs(i);
      for (int j = 1; j <= n; j++) {
        if (comp[i] == cur) {
          bfs(i);
          add = max(add, dist[last]);
        }
      }
      res += add;
    }
  }
  printf("%d\n", res);
  return 0;
}
