#include <bits/stdc++.h>
using namespace std;
const int MOD(1000000009);
const int INF((1 << 30) - 1);
const int MAXN(100005);
vector<int> g[MAXN], tree[MAXN], cycle;
bool getcycle = 0, heavy[MAXN], iscycle[MAXN];
int par[MAXN], children[MAXN], numcycle, visited[MAXN], color = 1, root[MAXN],
                                                        nxt[MAXN];
int h[MAXN], idx[MAXN];
void dfs(int node) {
  visited[node] = color;
  for (int i = 0; i < g[node].size(); i++) {
    int u = g[node][i];
    if (visited[u] != color) {
      par[u] = node;
      dfs(u);
    } else if (u != par[node] && !getcycle) {
      getcycle = 1;
      int v = node;
      while (v != u) {
        cycle.push_back(v);
        iscycle[v] = 1;
        v = par[v];
      }
      iscycle[u] = 1;
      cycle.push_back(u);
      numcycle = cycle.size();
    }
  }
}
struct segment_tree {
  int n;
  vector<int> val;
  vector<int> toggle;
  segment_tree(int _n) {
    n = _n;
    int k = 0;
    while ((1 << k) < n) k++;
    val.resize(1 << (k + 1), 0);
    toggle.resize(1 << (k + 1), false);
    val[1] = n;
    toggle[1] = 1;
  }
  inline void rev(int i, int f, int l) {
    val[i] = (l - f + 1) - val[i];
    toggle[i] ^= 1;
  }
  void update(int i, int f, int l, int st, int fn) {
    if (st > fn) return;
    if (f == st && l == fn) {
      rev(i, f, l);
      return;
    }
    int m = (f + l) / 2;
    if (toggle[i]) {
      rev(i * 2, f, m);
      rev(i * 2 + 1, m + 1, l);
      toggle[i] = 0;
    }
    if (fn <= m)
      update(i * 2, f, m, st, fn);
    else if (st > m)
      update(i * 2 + 1, m + 1, l, st, fn);
    else {
      update(i * 2, f, m, st, m);
      update(i * 2 + 1, m + 1, l, m + 1, fn);
    }
    val[i] = val[i * 2] + val[i * 2 + 1];
  }
};
vector<segment_tree> t;
stack<int> st;
void dfs2(int node, int r) {
  visited[node] = color;
  root[node] = r;
  children[node] = 1;
  st.push(node);
  for (int i = 0; i < g[node].size(); i++) {
    int u = g[node][i];
    if (visited[u] != color && !iscycle[u]) {
      par[u] = node;
      tree[node].push_back(u);
      dfs2(u, r);
      children[node] += children[u];
    }
  }
  for (int i = 0; i < tree[node].size(); i++) {
    int u = tree[node][i];
    heavy[u] = (children[u] * 2 > children[node]);
  }
}
int removeEdgeTree, removeEdgeCycle;
void modify(int u) {
  while (u != par[u]) {
    removeEdgeTree -= t[idx[u]].val[1];
    t[idx[u]].update(1, 1, t[idx[u]].n, 1, h[u]);
    removeEdgeTree += t[idx[u]].val[1];
    u = par[u];
  }
}
bool chk(int u, int v) {
  if (u < v) {
    int t = u - 1;
    if (t == 0) t = numcycle;
    return cycle[t - 1] < cycle[u];
  } else {
    int t = u + 1;
    if (t > numcycle) t = 1;
    return cycle[t - 1] < cycle[u - 2];
  }
}
int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1);
  color++;
  t.push_back(segment_tree(numcycle));
  removeEdgeCycle = numcycle;
  removeEdgeTree = n - numcycle;
  for (int i = 0; i < numcycle; i++) {
    par[cycle[i]] = cycle[i];
    dfs2(cycle[i], i + 1);
    color++;
    while (!st.empty()) {
      int u = st.top();
      st.pop();
      if (iscycle[u]) break;
      if (nxt[u] != 0) continue;
      vector<int> tmp;
      if (!heavy[u]) {
        if (u != cycle[i]) {
          tmp.push_back(u);
          u = par[u];
        }
      } else {
        while (u != cycle[i] && heavy[u]) {
          tmp.push_back(u);
          u = par[u];
        }
      }
      t.push_back(segment_tree(tmp.size()));
      for (int j = 0; j < tmp.size(); j++) {
        nxt[tmp[j]] = u;
        h[tmp[j]] = (int)(tmp.size()) - j;
        idx[tmp[j]] = (int)(t.size()) - 1;
      }
    }
  }
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    modify(u);
    u = root[u];
    modify(v);
    v = root[v];
    if (u != v) {
      int len1 = abs(v - u);
      int len2 = numcycle - len1;
      if (len2 < len1 || (len2 == len1 && chk(u, v))) {
        if (u > v) swap(u, v);
        removeEdgeCycle -= t[0].val[1];
        t[0].update(1, 1, numcycle, 1, u);
        t[0].update(1, 1, numcycle, v + 1, numcycle);
        removeEdgeCycle += t[0].val[1];
      } else {
        if (u > v) swap(u, v);
        removeEdgeCycle -= t[0].val[1];
        t[0].update(1, 1, numcycle, u + 1, v);
        removeEdgeCycle += t[0].val[1];
      }
    }
    if (removeEdgeCycle <= 1)
      printf("%d\n", removeEdgeTree + 1);
    else
      printf("%d\n", removeEdgeTree + removeEdgeCycle);
  }
}
