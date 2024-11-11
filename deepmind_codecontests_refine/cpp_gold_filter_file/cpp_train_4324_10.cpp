#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int du[N];
vector<int> g[N];
struct Edge {
  int from, to, nex;
} edge[N];
int h[N], idx, ans;
void add(int u, int v) {
  Edge E = {u, v, h[u]};
  edge[idx] = E;
  h[u] = idx++;
}
int n;
void dfs(int u, int fa, int last) {
  int j = 1;
  for (int i = h[u]; ~i; i = edge[i].nex) {
    int v = edge[i].to;
    if (v == fa) continue;
    if (j == last) ++j;
    g[j].push_back(i / 2 + 1);
    dfs(v, u, j);
    ++j;
  }
  return;
}
int main() {
  memset(h, -1, sizeof(h));
  idx = 0;
  ans = 0;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    du[u]++, du[v]++;
    ans = max(ans, max(du[u], du[v]));
    add(u, v);
    add(v, u);
  }
  cout << ans << endl;
  dfs(1, -1, 0);
  for (int i = 1; i <= ans; ++i) {
    printf("%d ", g[i].size());
    for (int j = 0; j < g[i].size(); ++j) printf("%d ", g[i][j]);
    printf("\n");
  }
  return 0;
}
