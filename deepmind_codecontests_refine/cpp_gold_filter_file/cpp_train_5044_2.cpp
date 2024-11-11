#include <bits/stdc++.h>
using namespace std;
int parent[500005], size[500005];
void make_set(int v) {
  parent[v] = v;
  size[v] = 1;
}
int find_set(int v) {
  if (v == parent[v]) return v;
  return parent[v] = find_set(parent[v]);
}
void union_sets(int a, int b) {
  a = find_set(a);
  b = find_set(b);
  if (a != b) {
    if (size[a] < size[b]) swap(a, b);
    parent[b] = a;
    size[a] += size[b];
  }
}
vector<long long> v[300005];
bool vis1[300005], vis2[300005];
long long diam[300005];
long long mx, curr;
void dfs1(long long node, long long sz) {
  vis1[node] = true;
  for (long long i = 0; i < v[node].size(); i++) {
    if (!vis1[v[node][i]]) dfs1(v[node][i], sz + 1);
  }
  if (sz > mx) {
    mx = sz;
    curr = node;
  }
}
void dfs2(long long node, long long sz) {
  vis2[node] = true;
  for (long long i = 0; i < v[node].size(); i++) {
    if (!vis2[v[node][i]]) dfs2(v[node][i], sz + 1);
  }
  if (sz > mx) {
    mx = sz;
    curr = node;
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long n, m, q;
  cin >> n >> m >> q;
  long long x, y;
  for (long long i = 1; i < n + 1; i++) make_set(i);
  for (long long i = 0; i < m; i++) {
    cin >> x >> y;
    v[x].push_back(y);
    v[y].push_back(x);
    union_sets(x, y);
  }
  memset(vis1, 0, sizeof vis1);
  memset(vis2, 0, sizeof vis2);
  curr = 1;
  for (long long i = 1; i < n + 1; i++) {
    mx = 0;
    if (!vis1[i]) {
      dfs1(i, 0);
      dfs2(curr, 0);
      diam[find_set(i)] = mx;
    }
  }
  while (q--) {
    long long a, b;
    cin >> a;
    if (a == 1) {
      cin >> x;
      cout << diam[find_set(x)] << "\n";
    } else {
      cin >> x >> y;
      if (find_set(x) != find_set(y)) {
        b = max(diam[find_set(x)], diam[find_set(y)]);
        a = (diam[find_set(x)] + 1) / 2 + (diam[find_set(y)] + 1) / 2 + 1;
        union_sets(x, y);
        diam[find_set(x)] = max(a, b);
      }
    }
  }
  return 0;
}
