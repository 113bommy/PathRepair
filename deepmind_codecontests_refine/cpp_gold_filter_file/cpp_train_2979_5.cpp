#include <bits/stdc++.h>
using namespace std;
inline int readIn() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
const int MAX_N = 200000 + 3;
const int INF = 0x3f3f3f3f;
int n;
int val[MAX_N], f[MAX_N];
vector<int> G[MAX_N], res[MAX_N];
inline int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
void dfs(int u, int fa) {
  if (u == 1) {
    f[u] = val[u];
    res[u].push_back(0);
  } else {
    f[u] = gcd(val[u], f[fa]);
    res[u].push_back(f[fa]);
    for (int i = 0; i < (int)res[fa].size(); ++i) {
      res[u].push_back(gcd(res[fa][i], val[u]));
    }
    res[u].erase(unique(res[u].begin(), res[u].end()), res[u].end());
  }
  for (int i = 0; i < (int)G[u].size(); ++i)
    if (G[u][i] != fa) dfs(G[u][i], u);
}
int main() {
  n = readIn();
  for (int i = 1; i <= n; ++i) val[i] = readIn();
  for (int i = 0; i < MAX_N; ++i) G[i].clear(), res[i].clear();
  for (int i = 1; i < n; ++i) {
    int u = readIn(), v = readIn();
    G[u].push_back(v);
    G[v].push_back(u);
  }
  dfs(1, 0);
  for (int i = 1; i <= n; ++i) {
    if (i == 1)
      printf("%d ", val[i]);
    else {
      sort(res[i].begin(), res[i].end());
      printf("%d ", max(f[i], res[i][res[i].size() - 1]));
    }
  }
  return 0;
}
