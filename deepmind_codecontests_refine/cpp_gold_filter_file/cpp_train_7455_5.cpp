#include <bits/stdc++.h>
using namespace std;
int n, m, fa[200010][20] = {0}, dep[200010], first[200010] = {0}, tot = 0;
int in[200010], out[200010], tim = 0, a[200010], b[200010], val[200010];
int sum[200010] = {0}, f[200010];
vector<int> p[200010];
struct edge {
  int v, next;
} e[200010];
void insert(int a, int b) {
  e[++tot].v = b;
  e[tot].next = first[a];
  first[a] = tot;
}
void dfs(int v) {
  in[v] = ++tim;
  for (int i = first[v]; i; i = e[i].next) {
    dep[e[i].v] = dep[v] + 1;
    dfs(e[i].v);
  }
  out[v] = tim;
}
int lca(int a, int b) {
  if (dep[a] < dep[b]) swap(a, b);
  for (int i = 18; i >= 0; i--)
    if (dep[fa[a][i]] >= dep[b]) a = fa[a][i];
  if (a == b) return a;
  for (int i = 18; i >= 0; i--)
    if (fa[a][i] != fa[b][i]) a = fa[a][i], b = fa[b][i];
  return fa[a][0];
}
int lowbit(int x) { return x & (-x); }
void add(int x, int c) {
  for (int i = x; i <= n; i += lowbit(i)) sum[i] += c;
}
int calc_sum(int x) {
  int ans = 0;
  for (int i = x; i; i -= lowbit(i)) ans += sum[i];
  return ans;
}
void dp(int v) {
  int downsum = 0;
  for (int i = first[v]; i; i = e[i].next) {
    dp(e[i].v);
    downsum += f[e[i].v];
  }
  f[v] = downsum;
  for (int i = 0; i < p[v].size(); i++) {
    int x = a[p[v][i]], y = b[p[v][i]], V = val[p[v][i]];
    f[v] = max(f[v], downsum + calc_sum(in[x]) + calc_sum(in[y]) + V);
  }
  add(in[v], downsum - f[v]);
  add(out[v] + 1, f[v] - downsum);
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 2; i <= n; i++) {
    scanf("%d", &fa[i][0]);
    insert(fa[i][0], i);
  }
  dep[0] = -1, dep[1] = 0;
  dfs(1);
  for (int i = 1; i <= 18; i++)
    for (int j = 1; j <= n; j++) fa[j][i] = fa[fa[j][i - 1]][i - 1];
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%d", &a[i], &b[i], &val[i]);
    p[lca(a[i], b[i])].push_back(i);
  }
  dp(1);
  printf("%d", f[1]);
  return 0;
}
