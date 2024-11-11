#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pci = pair<char, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
const ll infll = 1e18 + 3;
const int maxn = 1e6 + 77;
const int nmax = 1e6 + 77;
const ll basell = 1e18 + 3;
const int mod = 1e9 + 7;
const ld eps = 1e-7;
const int inf = 1009000999;
const int nv = 100505;
const int baseint = 1000200013;
const ld PI = acos(-1.0);
inline bool EQ(ld a, ld b) { return fabs(a - b) < 1e-9; }
struct lis {
  int x, y, z;
};
vector<lis> ans;
int vis[2 * nv];
int used[2 * nv];
vi g[2 * nv];
int h[2 * nv];
void dfs(int v, int p) {
  vis[v] = 1;
  vector<int> q;
  for (int u : g[v]) {
    if (u == p) continue;
    if (!vis[u]) {
      h[u] = h[v] + 1;
      dfs(u, v);
      if (!used[u]) q.push_back(u);
    } else {
      if (h[u] > h[v]) q.push_back(u);
    }
  }
  for (int i = 0; i + 1 < ((int)(q).size()); i += 2) {
    ans.push_back({q[i], v, q[i + 1]});
  }
  if (((int)(q).size()) % 2 == 1 && p != -1) {
    ans.push_back({q.back(), v, p});
    used[v] = 1;
  }
}
int inline solve() {
  ios::sync_with_stdio(NULL), cin.tie(NULL), cout.tie(NULL);
  ;
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int a, b;
    cin >> a >> b;
    g[a - 1].push_back(b - 1);
    g[b - 1].push_back(a - 1);
  }
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) dfs(i, -1);
  }
  cout << ((int)(ans).size()) << '\n';
  for (lis u : ans) cout << u.x + 1 << " " << u.y + 1 << " " << u.z + 1 << '\n';
  return 0;
}
int32_t main() {
  solve();
  return 0;
}
