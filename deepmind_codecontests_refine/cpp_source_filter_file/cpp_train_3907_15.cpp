#include <bits/stdc++.h>
using namespace std;
const int N = 500101;
vector<int> e[N];
int n, m, i, a, b;
long long ans, size[N], f[N], g[N], c;
int jump[N][20], deep[N];
void dfs(int x, int fa) {
  int i;
  jump[x][0] = fa;
  deep[x] = deep[fa] + 1;
  for (i = 1; i <= 17; i++) jump[x][i] = jump[jump[x][i - 1]][i - 1];
  size[x] = 1;
  for (i = 0; i < e[x].size(); i++)
    if (e[x][i] != fa) {
      dfs(e[x][i], x);
      size[x] += size[e[x][i]];
      f[x] += f[e[x][i]] + size[e[x][i]];
    }
}
void gao(int x, int fa, long long cnt) {
  g[x] = cnt;
  int i;
  for (i = 0; i < e[x].size(); i++)
    if (e[x][i] != fa) gao(e[x][i], x, cnt - size[e[x][i]] + n - size[e[x][i]]);
}
int go(int a, int b) {
  int i;
  for (i = 17; i >= 1; i--)
    if (deep[jump[a][i]] > deep[b]) a = jump[a][i];
  return a;
}
int lca(int a, int b) {
  int i;
  if (deep[a] < deep[b]) a ^= b ^= a ^= b;
  for (i = 17; i >= 0; i--)
    if (deep[jump[a][i]] >= deep[b]) a = jump[a][i];
  if (a == b) return a;
  for (i = 17; i >= 0; i--)
    if (jump[a][i] != jump[b][i]) a = jump[a][i], b = jump[b][i];
  return jump[a][0];
}
int main() {
  scanf("%d%d", &n, &m);
  for (i = 1; i < n; i++) {
    scanf("%d%d", &a, &b);
    e[a].push_back(b);
    e[b].push_back(a);
  }
  dfs(1, 0);
  gao(1, 0, f[1]);
  for (i = 1; i <= m; i++) {
    scanf("%d%d", &a, &b);
    c = lca(a, b);
    if ((a != c) && (b != c)) {
      ans = size[b] * f[a] + size[a] * f[b] +
            size[a] * size[b] * (deep[a] + deep[b] - 2 * deep[c] + 1);
      printf("%.9f\n", ans * 1.0 / (size[a] * size[b]));
    } else {
      if (a != c) a ^= b ^= a ^= b;
      c = go(b, a);
      ans = size[b] * (g[a] - f[c] - size[c]) + (n - size[c]) * f[b] +
            size[b] * (n - size[c]) * (deep[b] - deep[a] + 1);
      printf("%.9f\n", ans * 1.0 / (size[b] * (n - size[c])));
    }
  }
}
