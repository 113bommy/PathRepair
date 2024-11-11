#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
const int MAXN = 100005;
const long long mod = 1e9 + 7;
const int inf = 0x3f3f3f3f;
int n;
vector<int> G[MAXN];
int sz[MAXN];
int rt = 1;
int minNode = inf;
int book[MAXN];
int dep[MAXN];
int vis[MAXN];
void dfs(int u, int f) {
  sz[u] = 1;
  int maxn = 0;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == f) continue;
    dfs(v, u);
    maxn = max(maxn, sz[v]);
    sz[u] += sz[v];
  }
  maxn = max(maxn, n - sz[u]);
  if (minNode > maxn) {
    rt = u;
    minNode = maxn;
  }
}
bool dfs1(int u, int f, int d) {
  if (book[d] == -1)
    book[d] = G[u].size();
  else {
    if (book[d] != G[u].size()) {
      return false;
    }
  }
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i];
    if (v == f) continue;
    bool flag = dfs1(v, u, d + 1);
    if (flag == false) return false;
  }
  return true;
}
bool judge(int rt) {
  for (int i = 0; i <= n; i++) {
    book[i] = -1;
  }
  return dfs1(rt, -1, 0);
}
int line(int u, int f, int d) {
  if (u == rt) return d;
  if (G[u].size() > 2) return -1;
  return line(G[u][G[u][0] == f], u, d + 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n - 1; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 0);
  if (judge(rt)) {
    return printf("%d\n", rt), 0;
  }
  for (int i = 1; i <= n; i++) {
    if (G[i].size() == 1) {
      int d = line(i, -1, 0);
      if (d == -1 || vis[d]) continue;
      vis[d] = 1;
      if (judge(i)) {
        return printf("%d\n", i), 0;
      }
    }
  }
  printf("-1\n");
  return 0;
}
