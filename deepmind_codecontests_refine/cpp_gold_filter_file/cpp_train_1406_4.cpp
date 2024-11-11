#include <bits/stdc++.h>
using namespace std;
int n;
vector<vector<int> > g, G;
short dp[5000][2501][3][2];
int in[5000];
int last[5000], u[5000], v[5000], nxt[5000], e;
void addEdge(int a, int b) {
  u[e] = a;
  v[e] = b;
  nxt[e] = last[a];
  last[a] = e;
  ++e;
}
int DFS(int u, int p) {
  int ret = 0, me = 1;
  for (int i = 0; i < g[u].size(); ++i)
    if (g[u][i] != p) {
      addEdge(u, g[u][i]);
      ret += DFS(g[u][i], u);
      me = 0;
    }
  return in[u] = ret + me;
}
short calc(int e, int rem, char l, bool me) {
  if (e == -1) {
    if (me) return rem ? 10000 : 0;
    if (rem) return l != 2 && l != 1;
    return l != 2 && l != 0;
  }
  short &ret = dp[e][rem][l][me];
  if (ret != -1) return ret;
  ret = 10000;
  if (!me)
    ret = min((l != 2 && l != 0) + calc(e, rem, 0, true),
              (l != 2 && l != 1) + calc(e, rem, 1, true));
  else {
    for (int take = 0; take <= rem && take <= in[v[e]]; ++take)
      ret = min((int)ret, calc(last[v[e]], take, l, false) +
                              calc(nxt[e], rem - take, l, me));
  }
  return ret;
}
int main() {
  scanf("%d", &n);
  g.resize(n);
  if (n == 2) {
    puts("1");
    return 0;
  }
  for (int i = 1, a, b; i < n; ++i) {
    scanf("%d%d", &a, &b);
    --a;
    --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  int leaf = 0, root;
  for (int i = 0; i < n; ++i)
    if (g[i].size() == 1)
      ++leaf;
    else
      root = i;
  assert(leaf % 2 == 0);
  memset(last, -1, sizeof(last));
  DFS(root, -1);
  memset(dp, -1, sizeof(dp));
  printf("%d\n", (int)calc(last[root], leaf / 2, 2, false));
  return 0;
}
