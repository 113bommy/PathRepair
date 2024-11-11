#include <bits/stdc++.h>
using namespace std;
using LL = long long;
inline void NO() {
  cout << "No\n";
  exit(0);
}
const int N = 2e5 + 10;
int n, k;
int col[N];
void YES() {
  cout << "Yes\n";
  for (int u = 0; u < n; u++) {
    cout << (col[u] + 1) << ' ';
  }
  cout << '\n';
  exit(0);
}
vector<int> adj[N];
int dep[N];
void compute_dep(int u, int p = -1, int d = 0) {
  dep[u] = d;
  for (int v : adj[u]) {
    if (v == p) continue;
    compute_dep(v, u, d + 1);
  }
}
int cdep[N], ht[N];
void compute_cdep(int u, int p = -1) {
  cdep[u] = dep[u];
  ht[u] = 1;
  for (int v : adj[u]) {
    if (v == p) continue;
    compute_cdep(v, u);
    cdep[u] = max(cdep[u], cdep[v]);
    ht[u] = max(ht[u], 1 + ht[v]);
  }
}
void assign_col(int u, int p = -1, int c = -1) {
  if (col[u] == -1) {
    col[u] = c;
  } else {
    c = col[u];
  }
  for (int v : adj[u]) {
    if (v == p) continue;
    assign_col(v, u, (c - 1 + k) % k);
  }
}
void check(int u, int p = -1) {
  int inc[] = {0, 0}, dec[] = {0, 0};
  for (int v : adj[u]) {
    if (v == p) continue;
    check(v, u);
    if (col[v] == (col[u] + 1) % k) {
      if (ht[v] > inc[1]) inc[1] = ht[v];
      if (inc[1] > inc[0]) swap(inc[1], inc[0]);
    }
    if (col[u] == (col[v] + 1) % k) {
      if (ht[v] > dec[1]) dec[1] = ht[v];
      if (dec[1] > dec[0]) swap(dec[1], dec[0]);
    }
  }
  if (inc[1] > 0 && inc[0] + inc[1] + 1 >= k) {
    NO();
  }
  if (dec[1] > 0 && dec[0] + dec[1] + 1 >= k) {
    NO();
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    adj[u - 1].push_back(v - 1);
    adj[v - 1].push_back(u - 1);
  }
  int root = 0;
  compute_dep(root);
  for (int u = 0; u < n; u++) {
    if (dep[u] > dep[root]) root = u;
  }
  compute_dep(root);
  int maxd = 0;
  for (int u = 0; u < n; u++) {
    maxd = max(maxd, dep[u]);
  }
  if (maxd + 1 < k) YES();
  compute_cdep(root);
  memset(col, -1, sizeof col);
  for (int u = 0; u < n; u++) {
    if (cdep[u] >= k - 1) {
      col[u] = dep[u] % k;
    }
  }
  assign_col(root);
  if (k == 2) YES();
  check(root);
  YES();
  return 0;
}
