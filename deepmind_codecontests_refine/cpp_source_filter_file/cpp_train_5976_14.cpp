#include <bits/stdc++.h>
using namespace std;
inline long long next_int() {
  int32_t x;
  scanf("%d", &x);
  return x;
}
const long long maxn = 2e5 + 10;
vector<long long> g[maxn], centroidTree[maxn];
long long mark[maxn];
long long sz[maxn];
inline void pre_calc(long long node, long long fa = -1) {
  sz[node] = 1;
  for (auto u : g[node])
    if (u - fa && !mark[u]) {
      pre_calc(u, node);
      sz[node] += sz[u];
    }
}
long long rt;
inline long long getCentroid(long long node, long long fa = -1) {
  for (auto u : g[node])
    if (u - fa && !mark[u] && sz[u] * 2 > sz[rt]) return getCentroid(u, node);
  return node;
}
long long Root = -1;
inline void dfs(long long node, long long preCentroid = -1) {
  pre_calc(node);
  rt = node;
  long long centroid = getCentroid(node);
  mark[centroid] = true;
  if (Root == -1) Root = centroid;
  if (preCentroid + 1) centroidTree[preCentroid].push_back(centroid);
  mark[centroid] = true;
  for (auto u : g[centroid])
    if (!mark[u]) dfs(u, centroid);
}
char res[maxn];
inline void dfs2(long long node, long long h = 0) {
  res[node] = 'Z' - h;
  for (auto u : centroidTree[node]) dfs2(u, h + 1);
}
int32_t main() {
  long long n = next_int();
  for (long long i = 0; i < n - 1; i++) {
    long long v = next_int() - 1, u = next_int() - 1;
    g[v].push_back(u);
    g[u].push_back(v);
  }
  dfs(0);
  dfs2(Root);
  for (long long i = 0; i < n; i++) cout << res[i] << " ";
  cout << "\n";
}
