#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 100, MAXB = 18;
int h[MAXN], p[MAXN][MAXB];
vector<pair<int, int> > G[MAXN];
void makeroot(int u, int par) {
  h[u] = (par == -1 ? 0 : h[par] + 1);
  p[u][0] = par;
  for (int i = 1; i < MAXB; i++)
    if (p[u][i - 1] != -1)
      p[u][i] = p[p[u][i - 1]][i - 1];
    else
      p[u][i] = -1;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i].first;
    if (par != v) makeroot(v, u);
  }
}
int lca(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  for (int i = 0; i < MAXB; i++)
    if ((h[u] - h[v]) >> i & 1) u = p[u][i];
  if (u == v) return u;
  for (int i = MAXB - 1; i >= 0; i--)
    if (p[u][i] != p[v][i]) u = p[u][i], v = p[v][i];
  return p[u][0];
}
pair<int, int> down[MAXN];
inline pair<int, int> mrg(pair<int, int> a, pair<int, int> b, int u) {
  if (a.first < 0) return b;
  if (b.first < 0) return a;
  if (a.first == b.first)
    return pair<int, int>(a.first, u);
  else
    return max(a, b);
}
bitset<MAXN> chosen;
void dfsdown(int u, int par) {
  if (chosen[u])
    down[u] = pair<int, int>(0, u);
  else
    down[u] = pair<int, int>(-1e9, -1);
  int cnt = 0;
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i].first, w = G[u][i].second;
    if (v == par) continue;
    dfsdown(v, u);
    down[u] =
        mrg(down[u], pair<int, int>(down[v].first + w, down[v].second), u);
  }
}
pair<int, int> ans[MAXN];
int counter[MAXN];
vector<pair<int, int> > ch[MAXN];
void dfsup(int u, int par, pair<int, int> up) {
  ans[u] = mrg(up, down[u], u);
  if (chosen[u]) {
    int v = ans[u].second;
    assert(v != -1);
    int l = lca(u, v);
    counter[u]++;
    counter[v]++;
    counter[l]--;
    l = p[l][0];
    if (l != -1) counter[l]--;
  }
  pair<int, int> tmp =
      (chosen[u] ? pair<int, int>(u, 0) : pair<int, int>(-1e9, -1));
  vector<pair<int, int> > pre;
  for (int i = 0; i < G[u].size(); i++)
    if (G[u][i].first != par) ch[u].push_back(G[u][i]);
  for (int i = 0; i < ch[u].size(); i++) {
    int v = ch[u][i].first, w = ch[u][i].second;
    pre.push_back(tmp);
    tmp = mrg(tmp, pair<int, int>(down[v].first + w, down[v].second), u);
  }
  for (int i = int(ch[u].size()) - 1; i >= 0; i--) {
    int v = ch[u][i].first, w = ch[u][i].second;
    pair<int, int> pass = mrg(up, pre[i], u);
    pass.first += w;
    dfsup(v, u, pass);
    up = mrg(up, pair<int, int>(down[v].first + w, down[v].second), u);
  }
}
void get(int u, int par) {
  for (int i = 0; i < G[u].size(); i++) {
    int v = G[u][i].first;
    if (v == par) continue;
    get(v, u);
  }
  if (par != -1) counter[par] += counter[u];
}
int main() {
  ios::sync_with_stdio(false);
  cout.tie(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u;
    cin >> u;
    u--;
    chosen[u] = true;
  }
  for (int i = 0; i < n - 1; i++) {
    int u, v, w;
    cin >> u >> v >> w;
    u--;
    v--;
    G[u].push_back(pair<int, int>(v, w));
    G[v].push_back(pair<int, int>(u, w));
  }
  makeroot(0, -1);
  dfsdown(0, -1);
  dfsup(0, -1, pair<int, int>(-1e9, -1));
  get(0, -1);
  int mx = 0, cnt = 0;
  for (int i = 0; i < n; i++)
    if (!chosen[i]) {
      if (counter[i] == mx)
        cnt++;
      else if (counter[i] > mx)
        cnt = 1, mx = counter[i];
    }
  cout << mx << " " << cnt << endl;
}
