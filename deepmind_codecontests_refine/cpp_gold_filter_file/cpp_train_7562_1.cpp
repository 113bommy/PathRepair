#include <bits/stdc++.h>
using namespace std;
long long int n, m, h, val[100005], vis[100005], par[100005], sz[100005],
    ch[100005], jok;
vector<vector<long long int>> g(100005), gr(100005);
vector<long long int> order, comp;
void dfs1(long long int v) {
  vis[v] = 1;
  for (long long int i = 0; i < g[v].size(); i++)
    if (!vis[g[v][i]]) dfs1(g[v][i]);
  order.push_back(v);
}
void dfs2(long long int v) {
  vis[v] = 1;
  par[v] = jok;
  sz[jok]++;
  for (long long int i = 0; i < gr[v].size(); i++)
    if (!vis[gr[v][i]]) dfs2(gr[v][i]);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> m >> h;
  for (long long int i = 1; i <= n; i++) cin >> val[i];
  vector<pair<long long int, long long int>> edg;
  for (long long int i = 0; i < m; i++) {
    long long int a, b;
    cin >> a >> b;
    if (val[b] == (val[a] + 1) % h) {
      g[a].push_back(b);
      edg.push_back({a, b});
      gr[b].push_back(a);
    }
    if (val[a] == (val[b] + 1) % h) {
      g[b].push_back(a);
      edg.push_back({b, a});
      gr[a].push_back(b);
    }
  }
  for (long long int i = 1; i <= n; i++)
    if (!vis[i]) dfs1(i);
  for (long long int i = 1; i <= n; i++) vis[i] = 0;
  for (long long int i = 1; i <= n; i++) {
    long long int v = order[n - i];
    if (!vis[v]) {
      jok = v;
      dfs2(v);
    }
  }
  for (long long int i = 0; i < edg.size(); i++) {
    long long int a = edg[i].first, b = edg[i].second;
    if (par[a] != par[b]) ch[par[a]] = 1;
  }
  long long int hi = 100005, a = 0;
  for (long long int i = 1; i <= n; i++)
    if ((par[i] == i) && (ch[i] == 0) && (hi > sz[i])) {
      hi = sz[i];
      a = i;
    }
  cout << sz[a] << endl;
  for (long long int i = 1; i <= n; i++)
    if (par[i] == a) cout << i << " ";
}
