#include <bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int maxn = 1e3 + 5, maxm = 1e5 + 5;
struct DSU {
  vector<int> par, sz;
  int cc;
  void init(int n) {
    cc = n;
    par.resize(n + 5), sz.resize(n + 5);
    for (int i = 1; i <= n; ++i) {
      par[i] = i;
      sz[i] = 1;
    }
  }
  int finds(int u) {
    if (par[u] == u) return u;
    return par[u] = finds(par[u]);
  }
  bool merges(int u, int v) {
    u = finds(u);
    v = finds(v);
    if (u == v) return false;
    if (sz[u] < sz[v]) swap(u, v);
    sz[u] += sz[v];
    par[v] = u;
    --cc;
    return true;
  }
};
vector<int> re, bl;
int N, U[maxm], V[maxm], M;
signed main(void) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    cin >> U[i] >> V[i];
    char col;
    cin >> col;
    if (col == 'S')
      re.emplace_back(i);
    else
      bl.emplace_back(i);
  }
  if (N % 2 == 0) {
    cout << -1;
    return 0;
  }
  DSU dsu;
  dsu.init(N);
  for (auto& i : re) dsu.merges(U[i], V[i]);
  vector<int> need;
  for (auto& i : bl) {
    if (dsu.merges(U[i], V[i])) {
      need.emplace_back(i);
    }
  }
  if (need.size() > N / 2) {
    cout << -1;
    return 0;
  }
  dsu.init(N);
  for (auto& i : need) dsu.merges(U[i], V[i]);
  for (auto& i : bl) {
    if (need.size() < N / 2 && dsu.merges(U[i], V[i])) {
      need.emplace_back(i);
    }
  }
  if (need.size() != N / 2) {
    cout << -1;
    return 0;
  }
  for (auto& i : re) {
    if (dsu.merges(U[i], V[i])) need.emplace_back(i);
  }
  if (dsu.cc != 1) {
    cout << -1;
    return 0;
  }
  cout << need.size() << '\n';
  assert(need.size() == N - 1);
  for (auto& i : need) cout << i << ' ';
}
