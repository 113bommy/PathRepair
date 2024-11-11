#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
vector<int> g[50010];
long long c[50010][501];
int k;
void dfs(int u, int p) {
  c[u][0] = 1;
  for (int i = 0; i < (int)g[u].size(); ++i) {
    int v = g[u][i];
    if (v == p) continue;
    dfs(v, u);
    for (int j = 1; j <= k; ++j) {
      c[u][j] += c[v][j - 1];
    }
  }
}
long long dfs2(int u, int p) {
  long long res = 2 * c[u][k];
  for (int i = 0; i < (int)g[u].size(); ++i) {
    int v = g[u][i];
    if (v == p) continue;
    res += dfs2(v, u);
    for (int j = 1; j < k; ++j) {
      res += c[v][j - 1] * (c[u][k - j] - c[v][k - j - 1]);
    }
  }
  return res;
}
int main(int argc, char **argv) {
  int n;
  int u, v;
  scanf("%d %d", &n, &k);
  for (int i = 1; i < n; ++i) {
    scanf("%d %d", &u, &v);
    u--;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, -1);
  cout << dfs2(0, -1) / 2 << endl;
  return 0;
}
