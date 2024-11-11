#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e4 + 100;
int par[maxn], sz[maxn], ans[maxn], comp;
pair<int, int> e[maxn];
vector<pair<int, int> > que[maxn];
int root(int v) { return (par[v] == -1 ? v : par[v] = root(par[v])); }
void add(int edg) {
  int v = e[edg].first, u = e[edg].second;
  v = root(v), u = root(u);
  if (v == u) return;
  if (sz[v] < sz[u]) swap(v, u);
  comp--;
  par[u] = v;
  sz[v] += sz[u];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int v, u;
    cin >> v >> u;
    v--, u--;
    e[i] = make_pair(v, u);
  }
  int K;
  cin >> K;
  for (int i = 0; i < K; i++) {
    int l, r;
    cin >> l >> r;
    l--;
    que[l].push_back(make_pair(r, i));
  }
  for (int i = 0; i < m; i++) {
    sort(que[i].begin(), que[i].end());
    reverse(que[i].begin(), que[i].end());
  }
  for (int i = 0; i < m; i++) {
    comp = n;
    memset(par, -1, sizeof par);
    memset(sz, 0, sizeof sz);
    int cnt = 0;
    for (int j = 0; j < i; j++) add(j);
    int last = m;
    for (int j = 0; j < que[i].size(); j++) {
      int r = que[i][j].first;
      int idx = que[i][j].second;
      for (int k = r; k < last; k++) add(k);
      ans[idx] = comp;
      last = r;
    }
  }
  for (int i = 0; i < K; i++) cout << ans[i] << '\n';
  cout << endl;
  return 0;
}
