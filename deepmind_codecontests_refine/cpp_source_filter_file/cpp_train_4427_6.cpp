#include <bits/stdc++.h>
using namespace std;
const int N6 = 1000 * 1000 + 20;
const int N = 100 * 1000 + 50;
const int N3 = 5000 + 20;
const long long mod = 1000 * 1000 * 1000 + 7;
const long long inf = LLONG_MAX / 10;
long long a[N], b[N], cnt[N], af[N], par[N][30], sz[N], h[N], value[N][30],
    vl[N], col[N], parr[N], rnk[N], vis[N];
pair<int, int> ee[N];
long long u, r, ans = 0;
long long n, m, rad, mx;
vector<pair<int, pair<int, int> > > edj;
vector<pair<int, int> > e[N];
bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
  if (vl[a.first] != vl[b.first]) {
    return (vl[a.first] < vl[b.first]);
  }
  return (a < b);
}
int get_par(int v, int h) {
  for (int i = 0; i < 30; i++)
    if (h & (1 << i)) v = par[v][i];
  return v;
}
int lca(int v, int u) {
  if (h[v] < h[u]) swap(v, u);
  v = get_par(v, h[v] - h[u]);
  if (v == u) return v;
  for (int i = 29; i > -1; i--) {
    if (par[v][i] != par[u][i] and par[v][i] != -1 and par[u][i] != -1) {
      v = par[v][i];
      u = par[u][i];
    }
  }
  return par[v][0];
}
int get_par_max(int v, int h) {
  for (int i = 0; i < 30; i++)
    if (h & (1 << i)) {
      mx = max(value[v][i], mx);
      v = par[v][i];
    }
  return v;
}
int lca_max(int v, int u) {
  if (h[v] < h[u]) swap(v, u);
  mx = 0;
  v = get_par_max(v, h[v] - h[u]);
  if (v == u) return mx;
  for (int i = 29; i > -1; i--) {
    if (par[v][i] != par[u][i] and par[v][i] != -1 and par[u][i] != -1) {
      mx = max(mx, value[v][i]);
      mx = max(mx, value[u][i]);
      v = par[v][i];
      u = par[u][i];
    }
  }
  return (max(mx, max(value[v][0], value[u][0])));
}
void dfs(int v, int p, int dadyedj) {
  vis[v] = 1;
  par[v][0] = p;
  value[v][0] = dadyedj;
  for (int i = 1; par[v][i - 1] != -1 and i < 30; i++) {
    par[v][i] = par[par[v][i - 1]][i - 1];
    value[v][i] = max(value[v][i - 1], value[par[v][i - 1]][i - 1]);
  }
  for (auto [u, a] : e[v]) {
    if (vis[u] == 0) {
      h[u] = h[v] + 1;
      dfs(u, v, a);
    }
  }
}
int find_root(int v) {
  if (parr[v] == -1) {
    return v;
  }
  return parr[v] = find_root(parr[v]);
}
void _merge(int a, int b) {
  int r_a = find_root(a);
  int r_b = find_root(b);
  if (rnk[r_a] > rnk[r_b]) {
    swap(r_a, r_b);
  }
  parr[r_a] = r_b;
  if (rnk[r_a] == rnk[r_b]) {
    rnk[r_b]++;
  }
  return;
}
long long solve(int ind) {
  if (col[ind] == 1) {
    return ans;
  }
  return (ans - lca_max(ee[ind].first, ee[ind].second) + vl[ind]);
}
int main() {
  cin >> n >> m;
  fill(parr, parr + n + 1, -1);
  for (int i = 0; i <= n; i++) {
    fill(par[i], par[i] + 30, -1);
  }
  for (int i = 0; i < m; i++) {
    long long a, b, val;
    cin >> a >> b >> val;
    vl[i] = val;
    ee[i].first = a;
    ee[i].second = b;
    edj.push_back({i, {a, b}});
  }
  sort((edj).begin(), (edj).end(), cmp);
  for (auto x : edj) {
    int v = x.second.first, u = x.second.second;
    if (find_root(v) != find_root(u)) {
      col[x.first] = 1;
      e[v].push_back({u, vl[x.first]});
      e[u].push_back({v, vl[x.first]});
      _merge(v, u);
      ans += vl[x.first];
    }
  }
  dfs(1, -1, 0);
  for (int i = 0; i < m; i++) {
    cout << solve(i) << "\n";
  }
}
