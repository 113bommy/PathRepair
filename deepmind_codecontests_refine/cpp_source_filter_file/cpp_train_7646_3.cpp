#include <bits/stdc++.h>
using namespace std;
const int inf = ~0U >> 1;
const long long INF = ~0ULL >> 1;
template <class T>
inline void read(T &n) {
  char c;
  for (c = getchar(); !(c >= '0' && c <= '9'); c = getchar())
    ;
  n = c - '0';
  for (c = getchar(); c >= '0' && c <= '9'; c = getchar()) n = n * 10 + c - '0';
}
int Pow(int base, int n, int mo) {
  if (n == 0) return 1;
  if (n == 1) return base % mo;
  int tmp = Pow(base, n >> 1, mo);
  tmp = (long long)tmp * tmp % mo;
  if (n & 1) tmp = (long long)tmp * base % mo;
  return tmp;
}
const int maxn = 2200;
stack<int> sta;
vector<int> E[maxn];
int dfn[maxn], low[maxn], vis[maxn], belong[maxn], size[maxn], son[maxn];
int fa[maxn], knapsack[maxn][4500], bottom[maxn], top[maxn];
int m, x, y, G[maxn][maxn], Index, n, N, ans;
int extra_ans = 0;
void tarjan(int u, int fa) {
  sta.push(u);
  dfn[u] = low[u] = ++Index;
  vis[u] = 1;
  for (int i = (0); i < (E[u].size()); ++i)
    if (E[u][i] != fa) {
      if (!vis[E[u][i]]) tarjan(E[u][i], u);
      low[u] = min(low[u], low[E[u][i]]);
    }
  if (low[u] == dfn[u]) {
    ++N;
    int v;
    do {
      v = sta.top();
      belong[v] = N;
      size[N]++;
      sta.pop();
    } while (v != u);
  }
}
void dfs(int u, int par) {
  son[u] = size[u];
  fa[u] = par;
  knapsack[u][0] = 1;
  for (int i = (0); i < (E[u].size()); ++i)
    if (E[u][i] != par) {
      int v = E[u][i];
      dfs(v, u);
      son[u] += son[v];
      bottom[u] += bottom[v];
      for (int j = (N); j >= (0); --j)
        knapsack[u][j + son[v]] |= knapsack[u][j];
    }
  bottom[u] += size[u] * son[u];
}
void dfs2(int u) {
  if (fa[u])
    top[u] = top[fa[u]] + bottom[fa[u]] - size[fa[u]] * son[u] - bottom[u] +
             size[u] * (n - son[u]);
  for (int i = (0); i < (E[u].size()); ++i)
    if (E[u][i] != fa[u]) dfs2(E[u][i]);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = (1); i <= (m); ++i)
    scanf("%d%d", &x, &y), E[x].push_back(y), E[y].push_back(x);
  tarjan(1, 0);
  for (int i = (1); i <= (n); ++i)
    for (int j = (0); j < (E[i].size()); ++j)
      if (belong[i] != belong[E[i][j]]) G[belong[i]][belong[E[i][j]]] = 1;
  for (int i = (1); i <= (n); ++i) E[i].clear();
  for (int i = (1); i <= (N); ++i)
    for (int j = (1); j <= (N); ++j)
      if (G[i][j]) E[i].push_back(j);
  dfs(1, 0);
  dfs2(1);
  for (int root = (1); root <= (N); ++root) {
    int ret = bottom[root] + top[root];
    for (int j = (N); j >= (0); --j)
      knapsack[root][j + n - son[root]] |= knapsack[root][j];
    for (int j = (0); j <= (N); ++j)
      if (knapsack[root][j]) ans = max(ans, ret + j * (n - size[root] - j));
  }
  printf("%d\n", extra_ans + ans);
  return 0;
}
