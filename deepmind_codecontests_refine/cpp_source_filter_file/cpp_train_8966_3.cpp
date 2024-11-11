#include <bits/stdc++.h>
using namespace std;
const int maxn = 100001;
const int maxd = 50;
const int inf = 1e9;
char str[maxd + 2];
bool open[maxn][maxd];
vector<int> adj[maxn];
int prv[maxn], low[maxn];
int bel[maxn];
vector<int> s[maxn];
int g[maxn];
bool t[maxn][maxd];
int val[maxn][maxd];
int f[maxn][maxd];
int st[maxn][maxd], en[maxn][maxd];
int n, m, d, cnt;
void scc(int u);
void cal(int c);
void topo_sort();
int main() {
  scanf("%d%d%d", &n, &m, &d);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
  }
  for (int u = 1; u <= n; u++) {
    scanf("%s", str + 1);
    for (int i = 1; i <= d; i++) {
      open[u][i % d] = str[i] == '1';
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!prv[i]) scc(i);
  }
  for (int i = 1; i <= cnt; i++) {
    cal(i);
  }
  topo_sort();
  int ans = 0;
  for (int u = 1; u <= n; u++) {
    for (int i = 0; i < d; i++) {
      ans = max(ans, en[u][i]);
    }
  }
  printf("%d", ans);
  return 0;
}
int stk[maxn];
bool in_stk[maxn];
int top;
void scc(int u) {
  static int t = 0;
  low[u] = prv[u] = ++t;
  stk[++top] = u;
  in_stk[u] = 1;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (!prv[v]) {
      scc(v);
      low[u] = min(low[u], low[v]);
    } else if (in_stk[v])
      low[u] = min(low[u], prv[v]);
  }
  if (low[u] >= prv[u]) {
    cnt++;
    g[cnt] = u;
    while (stk[top] != u) {
      in_stk[stk[top]] = 0;
      bel[stk[top]] = cnt;
      s[cnt].push_back(stk[top]);
      top--;
    }
    in_stk[u] = 0;
    bel[u] = cnt;
    s[cnt].push_back(u);
    top--;
  }
}
void dfs(int u, int i) {
  t[u][i] = 1;
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (bel[v] != bel[u]) continue;
    if (t[v][(i + 1) % d]) continue;
    dfs(v, (i + 1) % d);
  }
}
void cal(int c) {
  dfs(g[c], 0);
  for (int i = 0; i < d; i++) {
    for (int _ = 0; _ < s[c].size(); _++) {
      int u = s[c][_];
      bool cur = 0;
      for (int j = 0; j < d; j++) {
        cur |= t[u][j] & open[u][(i + j) % d];
      }
      val[c][i] += cur;
    }
  }
}
void topo_sort() {
  static int ind[maxn];
  for (int u = 1; u <= n; u++) {
    for (int i = 0; i < d; i++) {
      st[u][i] = en[u][i] = -inf;
    }
  }
  for (int c = 1; c <= cnt; c++) {
    for (int i = 0; i < d; i++) {
      f[c][i] = -inf;
    }
  }
  st[1][1 % d] = 0;
  for (int u = 1; u <= n; u++) {
    for (int i = 0; i < adj[u].size(); i++) {
      int v = adj[u][i];
      if (bel[u] != bel[v]) ind[bel[v]]++;
    }
  }
  queue<int> q;
  for (int i = 1; i <= cnt; i++) {
    if (!ind[i]) q.push(i);
  }
  while (!q.empty()) {
    int c = q.front();
    q.pop();
    for (int i = 0; i < d; i++) {
      for (int _ = 0; _ < s[c].size(); _++) {
        int u = s[c][_];
        for (int j = 0; j < d; j++) {
          if (t[u][j]) f[c][i] = max(f[c][i], st[u][(i + j) % d]);
        }
      }
    }
    for (int _ = 0; _ < s[c].size(); _++) {
      int u = s[c][_];
      for (int i = 0; i < d; i++) {
        if (!t[u][i]) continue;
        for (int j = 0; j < d; j++) {
          en[u][(i + j) % d] = max(en[u][(i + j) % d], f[c][j] + val[c][j]);
        }
      }
      for (int __ = 0; __ < adj[u].size(); __++) {
        int v = adj[u][__];
        if (bel[u] == bel[v]) continue;
        ind[bel[v]]--;
        if (!ind[bel[v]]) q.push(bel[v]);
        for (int i = 0; i < d; i++) {
          st[v][(i + 1) % d] = max(st[v][(i + 1) % d], en[u][i]);
        }
      }
    }
  }
}
