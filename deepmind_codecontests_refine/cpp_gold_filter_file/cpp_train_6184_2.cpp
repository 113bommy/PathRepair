#include <bits/stdc++.h>
using namespace std;
const long long base = 311, mod = 1e9 + 7, N = 1e5 + 11, inf = LLONG_MAX;
long long n, child[N];
char a[N];
bool visited[N];
vector<long long> adj[N];
void dfs(long long s, long long e) {
  child[s] = 1;
  for (auto u : adj[s]) {
    if (u != e && !visited[u]) {
      dfs(u, s);
      child[s] += child[u];
    }
  }
}
long long findcen(long long s, long long e, long long size) {
  for (auto u : adj[s]) {
    if (u != e && !visited[u]) {
      if (child[u] > size / 2) {
        return findcen(u, s, size);
      }
    }
  }
  return s;
}
void centroid(long long root, char c) {
  dfs(root, root);
  long long cen = findcen(root, root, child[root]);
  visited[cen] = 1;
  a[cen] = c;
  for (auto u : adj[cen]) {
    if (!visited[u]) {
      centroid(u, c + 1);
    }
  }
}
signed main() {
  cin >> n;
  for (long long i = 1, u, v; i < n; i++) {
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  centroid(1, 'A');
  for (long long i = 1; i <= n; i++) {
    cout << a[i] << ' ';
  }
}
