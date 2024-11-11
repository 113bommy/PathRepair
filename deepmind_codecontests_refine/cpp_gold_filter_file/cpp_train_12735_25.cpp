#include <bits/stdc++.h>
using namespace std;
vector<int> adj[101000], costs[101000], indexx[101000];
int baseArray[101000], ptr;
int chainNo, chainInd[101000], chainHead[101000], posInBase[101000];
int depth[101000], pa[17][101000], otherEnd[101000], subsize[101000];
int st[101000 * 6], qt[101000 * 6];
void make_tree(int cur, int s, int e) {
  if (s == e - 1) {
    st[cur] = baseArray[s];
    return;
  }
  int c1 = (cur << 1), c2 = c1 | 1, m = (s + e) >> 1;
  make_tree(c1, s, m);
  make_tree(c2, m, e);
  st[cur] = st[c1] + st[c2];
}
void update_tree(int cur, int s, int e, int x) {
  if (s > x || e <= x) return;
  if (s == x && s == e - 1) {
    st[cur] = 1 - st[cur];
    return;
  }
  int c1 = (cur << 1), c2 = c1 | 1, m = (s + e) >> 1;
  update_tree(c1, s, m, x);
  update_tree(c2, m, e, x);
  st[cur] = st[c1] + st[c2];
}
void query_tree(int cur, int s, int e, int S, int E) {
  if (s >= E || e <= S) {
    qt[cur] = 0;
    return;
  }
  if (s >= S && e <= E) {
    qt[cur] = st[cur];
    return;
  }
  int c1 = (cur << 1), c2 = c1 | 1, m = (s + e) >> 1;
  query_tree(c1, s, m, S, E);
  query_tree(c2, m, e, S, E);
  qt[cur] = qt[c1] + qt[c2];
}
int query_up(int u, int v) {
  if (u == v) return 0;
  int uchain, vchain = chainInd[v], ans = 0;
  while (1) {
    uchain = chainInd[u];
    if (uchain == vchain) {
      if (u == v) break;
      query_tree(1, 0, ptr, posInBase[v] + 1, posInBase[u] + 1);
      ans += qt[1];
      break;
    }
    query_tree(1, 0, ptr, posInBase[chainHead[uchain]], posInBase[u] + 1);
    ans += qt[1];
    u = chainHead[uchain];
    u = pa[0][u];
  }
  return ans;
}
int LCA(int u, int v) {
  if (depth[u] < depth[v]) swap(u, v);
  int diff = depth[u] - depth[v];
  for (int i = 0; i < 17; i++)
    if ((diff >> i) & 1) u = pa[i][u];
  if (u == v) return u;
  for (int i = 17 - 1; i >= 0; i--)
    if (pa[i][u] != pa[i][v]) {
      u = pa[i][u];
      v = pa[i][v];
    }
  return pa[0][u];
}
void query(int u, int v) {
  int lca = LCA(u, v);
  int d1 = query_up(u, lca);
  int d2 = query_up(v, lca);
  int a1 = d1 + d2;
  int D1 = depth[u] - depth[lca];
  int D2 = depth[v] - depth[lca];
  int a2 = D1 + D2;
  if (a1 == a2)
    printf("%d\n", a1);
  else
    printf("-1\n");
}
void change(int i) {
  int u = otherEnd[i];
  update_tree(1, 0, ptr, posInBase[u]);
}
void HLD(int curNode, int cost, int prev) {
  if (chainHead[chainNo] == -1) {
    chainHead[chainNo] = curNode;
  }
  chainInd[curNode] = chainNo;
  posInBase[curNode] = ptr;
  baseArray[ptr++] = cost;
  int sc = -1, ncost;
  for (int i = 0; i < adj[curNode].size(); i++)
    if (adj[curNode][i] != prev) {
      if (sc == -1 || subsize[sc] < subsize[adj[curNode][i]]) {
        sc = adj[curNode][i];
        ncost = costs[curNode][i];
      }
    }
  if (sc != -1) {
    HLD(sc, ncost, curNode);
  }
  for (int i = 0; i < adj[curNode].size(); i++)
    if (adj[curNode][i] != prev) {
      if (sc != adj[curNode][i]) {
        chainNo++;
        HLD(adj[curNode][i], costs[curNode][i], curNode);
      }
    }
}
void dfs(int cur, int prev, int _depth = 0) {
  pa[0][cur] = prev;
  depth[cur] = _depth;
  subsize[cur] = 1;
  for (int i = 0; i < adj[cur].size(); i++)
    if (adj[cur][i] != prev) {
      otherEnd[indexx[cur][i]] = adj[cur][i];
      dfs(adj[cur][i], cur, _depth + 1);
      subsize[cur] += subsize[adj[cur][i]];
    }
}
int main() {
  {
    ptr = 0;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
      adj[i].clear();
      costs[i].clear();
      indexx[i].clear();
      chainHead[i] = -1;
      for (int j = 0; j < 17; j++) pa[j][i] = -1;
    }
    for (int i = 1; i < n; i++) {
      int u, v, c = 1;
      scanf("%d %d", &u, &v);
      u--;
      v--;
      adj[u].push_back(v);
      costs[u].push_back(c);
      indexx[u].push_back(i - 1);
      adj[v].push_back(u);
      costs[v].push_back(c);
      indexx[v].push_back(i - 1);
    }
    chainNo = 0;
    dfs(0, -1);
    HLD(0, 0, -1);
    make_tree(1, 0, ptr);
    for (int i = 1; i < 17; i++)
      for (int j = 0; j < n; j++)
        if (pa[i - 1][j] != -1) pa[i][j] = pa[i - 1][pa[i - 1][j]];
    int q;
    scanf("%d", &q);
    while (q--) {
      int a, b;
      int typ;
      scanf("%d", &typ);
      if (typ == 3) {
        scanf("%d %d", &a, &b);
        query(a - 1, b - 1);
      } else if (typ == 2) {
        scanf("%d", &a);
        change(a - 1);
      } else if (typ == 1) {
        scanf("%d", &a);
        change(a - 1);
      }
    }
  }
  return 0;
}
