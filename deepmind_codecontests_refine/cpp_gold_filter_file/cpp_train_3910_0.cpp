#include <bits/stdc++.h>
using namespace std;
const int maxn = 200009;
vector<int> e[maxn];
int weight[maxn], size[maxn];
int n, m, u, v;
int best = 1e9, root;
inline int read() {
  char ch = getchar();
  int x = 0;
  while (ch < '0' || '9' < ch) ch = getchar();
  while ('0' <= ch && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x;
}
void getRoot(int u, int fa) {
  int heavy = 0;
  size[u] = weight[u];
  for (int i = e[u].size() - 1; i >= 0; i--)
    if (e[u][i] != fa) {
      getRoot(e[u][i], u);
      size[u] += size[e[u][i]];
      heavy = max(heavy, size[e[u][i]]);
    }
  heavy = max(heavy, 2 * m - size[u]);
  if (heavy < best) {
    best = heavy;
    root = u;
  }
}
long long dfs(int u, int fa, int dep) {
  long long res = 0;
  if (weight[u]) res += dep;
  for (int i = e[u].size() - 1; i >= 0; i--)
    if (e[u][i] != fa) res += dfs(e[u][i], u, dep + 1);
  return res;
}
int main() {
  n = read();
  m = read();
  for (int i = 1; i <= 2 * m; i++) weight[read()] = 1;
  for (int i = 1; i <= n - 1; i++) {
    u = read();
    v = read();
    e[u].push_back(v);
    e[v].push_back(u);
  }
  getRoot(1, 0);
  printf("%I64d\n", dfs(root, 0, 0));
  return 0;
}
