#include <bits/stdc++.h>
using namespace std;
long long i, i1, j, k, k1, t, n, m, res, flag[10], a[100010], b, tot,
    sz[100010], parent[100010], u, v;
vector<long long> adj[100010];
long long find(long long x) {
  while (x != parent[x]) x = parent[x];
  return x;
}
bool same(long long a, long long b) { return find(a) == find(b); }
void merge(long long a, long long b) {
  a = find(a);
  b = find(b);
  if (sz[a] < sz[b]) swap(a, b);
  for (auto u : adj[b]) {
    u = find(u);
    if (u == a)
      tot--;
    else
      adj[a].push_back(u);
  }
  parent[b] = a;
}
int main() {
  mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (i = 1; i <= m; i++) {
    sz[i] = i;
    parent[i] = i;
  }
  shuffle(sz + 1, sz + m + 1, rng);
  tot = 0;
  for (i = 1; i < n; i++) {
    if (a[i] != a[i - 1]) {
      adj[a[i - 1]].push_back(a[i]);
      adj[a[i]].push_back(a[i - 1]);
      tot++;
    }
  }
  cout << tot << "\n";
  m--;
  while (m--) {
    cin >> u >> v;
    merge(u, v);
    cout << tot << "\n";
  }
  return 0;
}
