#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200000 + 5;
vector<int> tree[MAXN];
int siz[MAXN], g[MAXN][5];
int k;
void dfs1(int u, int pa) {
  siz[u] = 1;
  g[u][0] = 1;
  for (auto v : tree[u]) {
    if (v == pa) continue;
    dfs1(v, u);
    siz[u] += siz[v];
    for (int j = 0; j < k; ++j) g[u][(j + 1) % k] += g[v][j];
  }
}
void dfs2(int u, int pa) {
  for (auto v : tree[u]) {
    if (v == pa) continue;
    int tmp[5] = {0};
    for (int i = 0; i < k; ++i)
      tmp[(i + 1) % k] = g[u][i] - g[v][(i - 1 + k) % k];
    for (int i = 0; i < k; ++i) g[v][i] += tmp[i];
    dfs2(v, u);
  }
}
long long solve(int n) {
  dfs1(1, 1);
  dfs2(1, 1);
  long long s[5] = {0};
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < k; ++j) s[j] += g[i][j];
  for (int i = 1; i < k; ++i) s[i] /= 2;
  long long dis = 0, sum = 0;
  for (int i = 1; i <= n; ++i) dis += 1LL * siz[i] * (n - siz[i]);
  for (int i = 1; i < k; ++i) {
    dis -= 1LL * i * s[i];
    sum += s[i];
  }
  dis = dis / k + sum;
  return dis;
}
int main() {
  int n;
  scanf("%d %d", &n, &k);
  for (int i = 1, u, v; i < n; ++i) {
    scanf("%d %d", &u, &v);
    tree[u].push_back(v);
    tree[v].push_back(u);
  }
  printf("%lld\n", solve(n));
  return 0;
}
