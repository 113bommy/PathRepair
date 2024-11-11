#include <bits/stdc++.h>
using namespace std;
inline int in() {
  int x;
  scanf("%d", &x);
  return x;
}
const int INF = 1e9 + 10;
const long long LINF = 1000ll * 1000 * 1000 * 1000 * 1000 * 1000 + 100;
const int MN = 1e5 + 10;
int n;
int es[MN], ee[MN], el[MN];
int par[MN], Sz[MN];
set<pair<long long, int>, greater<pair<long long, int> > > ans;
vector<int> adj[MN];
int rt[MN], h[MN], sz[MN];
bool mk[MN];
pair<int, int> edge[MN];
int root(int a) {
  if (par[a] == a) return a;
  par[a] = root(par[a]);
  return par[a];
}
void Union(int a, int b) {
  a = root(a), b = root(b);
  if (a == b) return;
  if (Sz[a] > Sz[b]) swap(a, b);
  par[a] = b, Sz[b] += Sz[a];
}
void input() {
  cin >> n;
  for (int i = 0; i < n - 1; ++i) {
    cin >> es[i] >> ee[i] >> el[i];
    --es[i], --ee[i];
    edge[i] = pair<int, int>(el[i], i);
  }
  sort(edge, edge + n - 1);
  for (int i = 0; i < n; ++i) par[i] = i, Sz[i] = 1;
}
void dfs(int s, int r) {
  rt[s] = r, mk[s] = true, sz[s] = Sz[root(s)];
  for (int i = 0; i < ((int)(adj[s]).size()); ++i) {
    int v = adj[s][i];
    if (mk[v]) continue;
    h[v] = h[s] + 1;
    dfs(v, r);
    sz[s] += sz[v];
  }
}
void cal(int l, int r) {
  vector<int> tmp;
  for (int i = l; i <= r; ++i) tmp.push_back(edge[i].second);
  for (int i = 0; i < ((int)(tmp).size()); ++i) {
    int a = es[tmp[i]], b = ee[tmp[i]];
    a = root(a), b = root(b);
    adj[a].push_back(b), adj[b].push_back(a);
  }
  for (int i = 0; i < ((int)(tmp).size()); ++i)
    if (!mk[root(es[tmp[i]])]) dfs(root(es[tmp[i]]), root(es[tmp[i]]));
  for (int i = 0; i < ((int)(tmp).size()); ++i) {
    int a = root(es[tmp[i]]), b = root(ee[tmp[i]]);
    if (h[a] > h[b]) swap(a, b);
    long long val = 2ll * sz[b] * (sz[rt[b]] - sz[b]);
    ans.insert(pair<int, int>(val, tmp[i]));
  }
  for (int i = 0; i < ((int)(tmp).size()); ++i) {
    int a = root(es[tmp[i]]), b = root(ee[tmp[i]]);
    adj[a].clear(), adj[b].clear(), mk[a] = mk[b] = false;
    sz[a] = sz[b] = 0, h[a] = h[b] = 0, rt[a] = rt[b] = 0;
  }
  for (int i = l; i <= r; ++i) Union(es[edge[i].second], ee[edge[i].second]);
}
void solve() {
  int p = 0;
  while (p < n - 1) {
    int l = p;
    while (p < n - 2 && edge[p].first == edge[p + 1].first) ++p;
    int r = p;
    cal(l, r);
    ++p;
  }
  vector<int> res;
  long long cur = -1;
  for (set<pair<long long, int>, greater<pair<long long, int> > >::iterator it =
           ans.begin();
       it != ans.end(); ++it) {
    if (cur == -1)
      cur = it->first, res.push_back(it->second);
    else {
      if (it->first != cur) break;
      res.push_back(it->second);
    }
  }
  sort(res.begin(), res.end());
  cout << cur << ' ' << ((int)(res).size()) << '\n';
  for (int i = 0; i < ((int)(res).size()); ++i) cout << res[i] + 1 << ' ';
  cout << '\n';
}
int main() {
  ios_base ::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  input();
  solve();
  return 0;
}
