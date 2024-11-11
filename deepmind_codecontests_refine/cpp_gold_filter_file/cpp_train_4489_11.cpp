#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int n;
int anc[maxn], sz[maxn][2];
long long dist[maxn][2];
vector<int> e[maxn];
long long ans = 0;
void dfs(int u) {
  sz[u][0] = 1;
  dist[u][0] = dist[u][1] = 0;
  for (auto v : e[u]) {
    if (anc[u] == v) continue;
    anc[v] = u;
    dfs(v);
    ans += (long long)dist[u][0] * sz[v][0] + (long long)dist[v][0] * sz[u][0] +
           (long long)sz[u][0] * sz[v][0];
    ans += (long long)dist[u][0] * sz[v][1] + (long long)dist[v][1] * sz[u][0] +
           (long long)sz[u][0] * sz[v][1];
    ans += (long long)dist[u][1] * sz[v][0] + (long long)dist[v][0] * sz[u][1] +
           (long long)sz[u][1] * sz[v][0];
    ans += (long long)dist[u][1] * sz[v][1] + (long long)dist[v][1] * sz[u][1] +
           (long long)2 * sz[u][1] * sz[v][1];
    sz[u][0] += sz[v][1];
    sz[u][1] += sz[v][0];
    dist[u][0] += dist[v][1] + sz[v][1];
    dist[u][1] += dist[v][0];
  }
}
int main() {
  scanf("%d", &n);
  for (int i = 1, u, v; i < n; i++) {
    scanf("%d%d", &u, &v);
    e[u].push_back(v);
    e[v].push_back(u);
  }
  dfs(1);
  cout << ans << endl;
  return 0;
}
