#include <bits/stdc++.h>
using namespace std;
const long long inf = 0x3f3f3f3f;
const int maxn = 1111;
vector<int> g[maxn];
int n, m;
bool used[maxn];
void dfs(int u) {
  if (used[u]) return;
  used[u] = true;
  for (int i = 0; i < g[u].size(); ++i) {
    int v = g[u][i];
    dfs(v);
  }
}
int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  memset(used, 0, sizeof used);
  dfs(1);
  bool flag = (m == n - 1);
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) flag = false;
  }
  if (flag)
    puts("yes");
  else
    puts("no");
}
