#include <bits/stdc++.h>
using namespace std;
using lli = long long;
using lld = long double;
using ulli = unsigned long long int;
using pll = pair<lli, lli>;
using ttt = pair<lli, pll>;
using vttt = vector<ttt>;
using vll = vector<pll>;
using vl = vector<lli>;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using cd = complex<lld>;
const double PI = acos(-1);
int timer;
int tin[100005], tout[100005];
lli depth[100005];
vvi adj(100005);
vi cr, cb;
ttt mini({0x3f3f3f3f3f3f3f3f, {0x3f3f3f3f3f3f3f3f, 0x3f3f3f3f3f3f3f3f}});
int vis[100005];
void dfs(int v, int p) {
  vis[v] = 1;
  tin[v] = ++timer;
  depth[v] = depth[p] + 1;
  if (depth[v] % 2)
    cb.push_back(v);
  else
    cr.push_back(v);
  for (auto& to : adj[v])
    if (to != p) {
      if (!vis[to])
        dfs(to, v);
      else if (depth[to] < depth[v]) {
        mini = min(mini, {depth[v] - depth[to] + 1, {to, v}});
      }
    }
  tout[v] = ++timer;
}
bool is_ancestor(int par, int v) {
  return tin[par] <= tin[v] && tout[par] >= tout[v];
}
int tejas_919(int kkkk) {
  lli n, m, k, q, u, v, temp = 0, ans = 0;
  cin >> n >> m >> k;
  for (int i = 0; i < m; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(1, 1);
  if (mini.first == 0x3f3f3f3f3f3f3f3f) {
    cout << 1 << '\n';
    if (((lli)(cr).size()) < ((lli)(cb).size())) swap(cr, cb);
    cr.resize((k + 1) / 2);
    for (auto& x : cr) cout << x << " ";
    cout << '\n';
    return 0;
  }
  cr.clear();
  {}
  for (int i = 1; i < n + 1; i++)
    if (is_ancestor(mini.second.first, i) &&
        is_ancestor(i, mini.second.second)) {
      cr.push_back(i);
    }
  assert(((lli)(cr).size()) == mini.first);
  sort(cr.begin(), cr.end(), is_ancestor);
  if (((lli)(cr).size()) > k) {
    cout << 1 << '\n';
    for (int i = 0; i < k; i += 2) cout << cr[i] << " ";
    cout << '\n';
  } else {
    cout << 2 << '\n' << ((lli)(cr).size()) << '\n';
    for (auto& x : cr) cout << x << " ";
    cout << '\n';
  }
  return 0;
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cout << fixed << setprecision(10);
  int t = 1;
  for (int i = 0; i < t; i++) {
    tejas_919(i + 1);
  }
  {};
}
