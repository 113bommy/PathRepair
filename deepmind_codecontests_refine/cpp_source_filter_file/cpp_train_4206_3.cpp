#include <bits/stdc++.h>
using namespace std;
long long int pw(long long int a, long long int b, long long int mod) {
  if (!b) return 1;
  if (b & 1) return a * pw(a * a % mod, b / 2, mod) % mod;
  return pw(a * a % mod, b / 2, mod) % mod;
}
const long long int MAXN = 3e2 + 10;
const long long int INF = 8e18;
const long long int MOD = 1e9 + 7;
long long int n, mn[MAXN], ind[MAXN];
vector<long long int> adj[MAXN], ord, ans, vec;
void DFS1(long long int u, long long int p = -1) {
  for (long long int v : adj[u]) {
    if (v == p) continue;
    DFS1(v, u);
    mn[u] = min(mn[u], mn[v]);
  }
  if (p != -1 && adj[u].size() == 1) {
    mn[u] = ind[u];
  }
}
bool cmp(long long int u, long long int v) { return mn[u] < mn[v]; }
void DFS2(long long int u, long long int p = -1) {
  sort(adj[u].begin(), adj[u].end());
  ans.push_back(u);
  for (long long int v : adj[u]) {
    if (v == p) continue;
    DFS2(v, u);
    ans.push_back(u);
  }
  if (p != -1 && adj[u].size() == 1) {
    vec.push_back(u);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  fill(mn, mn + MAXN, INF);
  cin >> n;
  for (long long int i = 0; i < n - 1; i++) {
    long long int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  long long int x;
  while (cin >> x) {
    ord.push_back(x);
    ind[x] = ord.size() - 1;
  }
  DFS1(1);
  DFS2(1);
  for (long long int i = 0; i < ord.size(); i++) {
    if (ord[i] != vec[i]) return cout << -1 << '\n', 0;
    ;
  }
  for (long long int u : ans) {
    cout << u << ' ';
  }
  cout << '\n';
  return 0;
}
