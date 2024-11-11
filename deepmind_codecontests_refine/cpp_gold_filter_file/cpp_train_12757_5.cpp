#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 6;
vector<int> adj[N];
int sub[N], in[N], out[N], ans[N], big[N], p[N];
int t = 1;
void dfs(int u) {
  sub[u] = 1;
  in[u] = t++;
  for (auto v : adj[u]) {
    dfs(v);
    sub[u] += sub[v];
    if (sub[v] > sub[big[u]]) big[u] = v;
  }
  out[u] = t - 1;
}
bool is_centeroid(int u, int root) {
  int mx = max(sub[big[u]], sub[root] - sub[u]);
  return 2 * mx <= sub[root];
}
int get_centeroid(int u, int root) {
  if (is_centeroid(u, root)) return u;
  return get_centeroid(big[u], root);
}
bool is_anc(int u, int v) { return in[v] >= in[u] && out[v] <= out[u]; }
void solve(int u) {
  if (is_anc(u, ans[p[u]]))
    ans[u] = get_centeroid(ans[p[u]], u);
  else
    ans[u] = get_centeroid(u, u);
  for (auto v : adj[u]) solve(v);
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, q;
  cin >> n >> q;
  for (int i = 2; i <= n; i++) {
    int x;
    cin >> x;
    adj[x].push_back(i);
    p[i] = x;
  }
  dfs(1);
  solve(1);
  for (int i = 0; i < q; i++) {
    int x;
    cin >> x;
    cout << ans[x] << '\n';
  }
  return 0;
}
