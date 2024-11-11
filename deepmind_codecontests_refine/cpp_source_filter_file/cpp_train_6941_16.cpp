#include <bits/stdc++.h>
using namespace std;
template <typename T>
void out(T x) {
  cout << x << endl;
  exit(0);
}
using ll = long long;
struct dsu0 {
  vector<int> par, siz;
  int n;
  int cc;
  int largest;
  void init(int n) {
    assert(n > 0);
    this->n = n;
    cc = n;
    par.resize(n + 10);
    siz.resize(n + 10);
    for (int i = 0; i < n; i++) par[i] = i, siz[i] = 1;
    largest = 1;
  }
  int parent(int x) {
    assert(x >= 0 && x < n);
    return par[x] == x ? x : par[x] = parent(par[x]);
  }
  bool join(int x, int y) {
    x = parent(x);
    y = parent(y);
    if (x == y) return false;
    cc--;
    if (siz[x] < siz[y]) swap(x, y);
    siz[x] += siz[y];
    par[y] = x;
    largest = max(largest, siz[x]);
    return true;
  }
};
const int maxn = 2e5 + 5;
int n, m;
ll a[maxn];
bool act[maxn];
int u[maxn], v[maxn];
ll sum[maxn];
int dep[maxn];
vector<int> g[maxn];
void dfs(int at, int p) {
  sum[at] = a[at];
  for (int to : g[at]) {
    if (to == p) continue;
    dep[to] = 1 + dep[at];
    dfs(to, at);
    sum[at] += sum[to];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  ll tot = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    tot += a[i];
  }
  if (tot != 0) {
    out("Impossible");
  }
  dsu0 dsu;
  dsu.init(n);
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> u[i] >> v[i];
    u[i]--;
    v[i]--;
    if (dsu.join(u[i], v[i])) {
      g[u[i]].push_back(v[i]);
      g[v[i]].push_back(u[i]);
      act[i] = true;
    }
  }
  dfs(0, -1);
  cout << "Possible\n";
  for (int i = 0; i < m; i++) {
    ll cur = 0;
    if (act[i]) {
      int x = u[i];
      int y = v[i];
      cur = dep[y] > dep[x] ? sum[y] : -sum[y];
    }
    cout << cur << "\n";
  }
  return 0;
}
