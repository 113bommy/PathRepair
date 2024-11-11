#include <bits/stdc++.h>
using namespace std;
ifstream fin("in.in");
ofstream fout("out.out");
const int N = 1e5 + 10, L = 17;
int n, q, st[N], ft[N], node[N << 2], h[N], par[N][L + 10], size;
vector<int> adj[N];
pair<int, int> edge[N];
bool mark[N];
void DFS(int u) {
  mark[u] = true;
  st[u] = size++;
  for (int i = 0; i < adj[u].size(); i++)
    if (!mark[adj[u][i]]) {
      h[adj[u][i]] = h[u] + 1;
      par[adj[u][i]][0] = u;
      DFS(adj[u][i]);
    }
  ft[u] = size;
}
int LCA(int x, int y) {
  if (h[x] < h[y]) swap(x, y);
  for (int i = L; i >= 0; i--)
    if (h[par[x][i]] >= h[y]) x = par[x][i];
  if (x == y) return x;
  for (int i = L; i >= 0; i--)
    if (par[x][i] != par[y][i]) {
      x = par[x][i];
      y = par[y][i];
    }
  return par[x][0];
}
void update(int s, int e, int tag, int l, int r, int val) {
  if (l >= r || s >= r || e <= l) return;
  if (s >= l && e <= r) {
    node[tag] += val;
    return;
  }
  int mid = (s + e) >> 1;
  update(s, mid, tag * 2, l, r, val);
  update(mid, e, tag * 2 + 1, l, r, val);
}
int getVal(int s, int e, int tag, int pos) {
  if (s + 1 == e) return node[tag];
  int mid = (s + e) >> 1;
  ;
  if (pos < mid) return node[tag] + getVal(s, mid, tag * 2, pos);
  return node[tag] + getVal(mid, e, tag * 2 + 1, pos);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  fin >> n;
  for (int i = 1; i < n; i++) {
    int x, y;
    fin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
    edge[i] = make_pair(x, y);
  }
  h[0] = -1;
  DFS(1);
  for (int j = 1; j <= L; j++)
    for (int i = 1; i <= n; i++) par[i][j] = par[par[i][j - 1]][j - 1];
  cin >> q;
  for (; q; q--) {
    int t;
    cin >> t;
    if (t == 3) {
      int u, v;
      cin >> u >> v;
      int x = LCA(u, v);
      int d = h[u] + h[v] - 2 * h[x];
      int res = getVal(0, n, 1, st[u]) + getVal(0, n, 1, st[v]) -
                2 * getVal(0, n, 1, st[x]);
      if (!res)
        cout << d << endl;
      else
        cout << -1 << endl;
    } else {
      int i;
      cin >> i;
      int x = (h[edge[i].first] > h[edge[i].second]) ? edge[i].first
                                                     : edge[i].second;
      int val = (t == 1) ? -1 : 1;
      update(0, n, 1, st[x], ft[x] + 1, val);
    }
  }
  return 0;
}
