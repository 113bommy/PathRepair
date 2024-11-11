#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
const int maxn = 1000010;
int n, m, r, h = 1;
char mp[1010][1010];
bool vis[2020];
int pre[2020], deg[2020], q[2020], val[1000010];
int head[2020], tot = 0;
struct node {
  int v, next, w;
  node(int _v = 0, int _next = 0, int _w = 0) : v(_v), next(_next), w(_w) {}
} edge[maxn];
inline void add(int u, int v) {
  edge[++tot].v = v;
  edge[tot].next = head[u];
  head[u] = tot;
  deg[v]++;
}
int Find(int x) { return x == pre[x] ? x : pre[x] = Find(pre[x]); }
void join(int x, int y) { pre[Find(x)] = Find(y); }
int main() {
  cin >> n >> m;
  for (int i = 1; i <= n; ++i) scanf("%s", mp[i] + 1);
  for (int i = 1; i < 2005; ++i) pre[i] = i;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (mp[i][j] == '=') join(i, j + n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (mp[i][j] == '<') add(Find(i), Find(j + n));
      if (mp[i][j] == '>') add(Find(j + n), Find(i));
    }
  }
  for (int i = 1; i <= n + m; ++i)
    if (i == Find(i) && !deg[i]) q[++r] = i, val[i] = 1, vis[i] = 1;
  while (h <= r) {
    int u = q[h++];
    for (int i = head[u]; i; i = edge[i].next) {
      int v = edge[i].v;
      if (vis[v]) continue;
      deg[v]--;
      if (!deg[v]) {
        vis[v] = 1;
        val[v] = val[u] + 1;
        q[++r] = v;
      }
    }
  }
  for (int i = 1; i <= n + m; ++i) {
    if (i == Find(i) && !vis[i]) {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  for (int i = 1; i <= n; i++) cout << val[Find(i)] << " ";
  cout << endl;
  for (int i = 1; i <= m; i++) cout << val[Find(i + n)] << " ";
  cout << endl;
  return 0;
}
