#include <bits/stdc++.h>
using namespace std;
const int N = 100001, L = 20;
int n;
int dis[N], tin[N], tout[N], tree[N];
int anc[L][N];
vector<int> adj[N];
pair<int, int> e[N];
void dfs(int u, int p, int time) {
  tin[u] = time++;
  for (auto v : adj[u]) {
    if (v == p) continue;
    anc[0][v] = u;
    dis[v] = dis[u] + 1;
    for (int i = 1; i < L; i++) {
      anc[i][v] = anc[i - 1][anc[i - 1][v]];
    }
    dfs(v, u, time);
    time = tout[v] + 1;
  }
  tout[u] = --time;
}
int lca(int u, int v) {
  if (dis[u] > dis[v]) swap(u, v);
  for (int i = L - 1; i >= 0; i--) {
    if (dis[v] - dis[u] >= (1 << i)) v = anc[i][v];
  }
  if (u == v) return u;
  for (int i = L - 1; i >= 0; i--) {
    if (anc[i][u] != anc[i][v]) {
      u = anc[i][u];
      v = anc[i][v];
    }
  }
  return anc[0][u];
}
int query(int x) {
  int s = 0;
  while (x > 0) {
    s += tree[x];
    x -= (x & -x);
  }
  return s;
}
void update(int x, int v) {
  while (x <= N) {
    tree[x] += v;
    x += (x & -x);
  }
}
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < (n - 1); i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    u--, v--;
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
    e[i] = {u, v};
  }
  memset(anc, -1, sizeof(anc));
  dfs(0, -1, 1);
  int q;
  scanf("%d", &q);
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 3) {
      int u, v;
      scanf("%d %d", &u, &v);
      u--, v--;
      int x = lca(u, v);
      int a = query(tin[x] - 1), b = query(tin[u] - 1), c = query(tin[v] - 1);
      if (a == b and a == c) {
        int res = dis[u] + dis[v] - (2 * dis[x]);
        printf("%d", res);
      } else {
        printf("-1");
      }
    } else {
      int i;
      scanf("%d", &i);
      i--;
      int u = e[i].first, v = e[i].second;
      if (tout[u] - tin[u] < tout[v] - tin[v]) swap(u, v);
      update(tout[v], ((t == 1) ? -1 : 1));
      update(tin[v] - 1, ((t == 1) ? 1 : -1));
    }
  }
}
