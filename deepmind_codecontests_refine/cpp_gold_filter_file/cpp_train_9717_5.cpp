#include <bits/stdc++.h>
#pragma comment(linker, "/stack:64000000")
using namespace std;
const int MAXN = 100000 + 10;
vector<int> g[MAXN];
bool used[MAXN];
int timer, tin[MAXN], fup[MAXN], color[MAXN];
int n, cnt = 0;
set<pair<int, int> > bridges;
void IS_BRIDGE(int a, int b) {
  bridges.insert(make_pair(min(a, b), max(a, b)));
}
void dfs(int v, int p = -1) {
  used[v] = true;
  tin[v] = fup[v] = timer++;
  for (size_t i = 0; i < g[v].size(); ++i) {
    int to = g[v][i];
    if (to == p) continue;
    if (used[to])
      fup[v] = min(fup[v], tin[to]);
    else {
      dfs(to, v);
      fup[v] = min(fup[v], fup[to]);
      if (fup[to] > tin[v]) IS_BRIDGE(v, to);
    }
  }
}
void find_bridges() {
  timer = 0;
  for (int i = 0; i < n; ++i) used[i] = false;
  for (int i = 0; i < n; ++i)
    if (!used[i]) dfs(i);
}
void dfs2(int x) {
  color[x] = cnt;
  for (int(i) = 0; (i) < ((int)(g[x]).size()); (i)++) {
    int to = g[x][i];
    if (color[to] == -1 && !bridges.count(make_pair(min(x, to), max(x, to)))) {
      dfs2(to);
    }
  }
}
vector<vector<int> > v;
int l;
vector<int> TIN, TOUT;
vector<vector<int> > up;
vector<int> dp;
void dfs4(int x) {
  used[x] = true;
  for (int(i) = 0; (i) < ((int)(v[x]).size()); (i)++) {
    int to = v[x][i];
    if (!used[to]) {
      dp[to] = dp[x] + 1;
      dfs4(to);
    }
  }
}
void dfs3(int V, int p = 0) {
  TIN[V] = ++timer;
  up[V][0] = p;
  for (int i = 1; i <= l; ++i) up[V][i] = up[up[V][i - 1]][i - 1];
  for (size_t i = 0; i < v[V].size(); ++i) {
    int to = v[V][i];
    if (to != p) dfs3(to, V);
  }
  TOUT[V] = ++timer;
}
bool upper(int a, int b) { return TIN[a] <= TIN[b] && TOUT[a] >= TOUT[b]; }
int lca(int a, int b) {
  if (upper(a, b)) return a;
  if (upper(b, a)) return b;
  for (int i = l; i >= 0; --i)
    if (!upper(up[a][i], b)) a = up[a][i];
  return up[a][0];
}
int main() {
  int m, a, b;
  scanf("%d %d", &n, &m);
  for (int(i) = 0; (i) < (m); (i)++) {
    scanf("%d %d", &a, &b);
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  find_bridges();
  memset(color, -1, sizeof(color));
  for (int(i) = 0; (i) < (n); (i)++) {
    if (color[i] == -1) {
      dfs2(i);
      cnt++;
    }
  }
  set<pair<int, int> > gr;
  for (int(i) = 0; (i) < (n); (i)++) {
    for (int(j) = 0; (j) < ((int)(g[i]).size()); (j)++) {
      if (color[i] != color[g[i][j]]) {
        gr.insert(make_pair(min(color[i], color[g[i][j]]),
                            max(color[i], color[g[i][j]])));
      }
    }
  }
  v.resize(cnt);
  for (set<pair<int, int> >::iterator it = gr.begin(); it != gr.end(); ++it) {
    v[it->first].push_back(it->second);
    v[it->second].push_back(it->first);
  }
  dp.resize(cnt);
  memset(used, 0, sizeof(used));
  dp[0] = 0;
  dfs4(0);
  TIN.resize(cnt), TOUT.resize(cnt), up.resize(cnt);
  l = 1;
  while ((1 << l) <= cnt) ++l;
  for (int i = 0; i < cnt; ++i) up[i].resize(l + 1);
  dfs3(0);
  int q;
  scanf("%d", &q);
  for (int(_) = 0; (_) < (q); (_)++) {
    int src, dst;
    scanf("%d %d", &src, &dst);
    src = color[src - 1];
    dst = color[dst - 1];
    memset(used, 0, sizeof(used));
    int t = lca(src, dst);
    int res = (dp[src] - dp[t]) + (dp[dst] - dp[t]);
    printf("%d\n", res);
  }
  return 0;
}
