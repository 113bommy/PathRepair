#include <bits/stdc++.h>
using namespace std;
const int N = 100001;
const int maxn = N << 1;
const int maxm = maxn << 2;
int n, id;
int bf[N], gf[N];
int head[maxn], c[maxn];
struct Edge {
  int to, next;
};
Edge e[maxm];
inline void _addEdge(const int x, const int y) {
  e[++id].next = head[x];
  head[x] = id;
  e[id].to = y;
}
inline void addEdge2(const int x, const int y) {
  _addEdge(x, y);
  _addEdge(y, x);
}
void dfs(int u, int color) {
  c[u] = color;
  for (int i = head[u]; i != -1; i = e[i].next)
    if (!c[e[i].to]) dfs(e[i].to, 3 - color);
}
int main() {
  int i;
  scanf("%d", &n);
  memset(head, -1, sizeof head);
  for (i = 1; i <= n; ++i) {
    scanf("%d%d", &bf[i], &gf[i]);
    addEdge2(bf[i], gf[i]);
  }
  for (i = 1; i < n; ++i) addEdge2(i << 1, i << 1 | 1);
  addEdge2(n << 1, 1);
  for (i = 1; i <= n; ++i)
    if (!c[i]) dfs(i, 1);
  for (i = 1; i <= n; ++i) printf("%d %d\n", c[bf[i]], c[gf[i]]);
  return 0;
}
