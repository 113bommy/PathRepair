#include <bits/stdc++.h>
using namespace std;
int n, q, cnt, k, m, r, ans;
int fa[20][100010], dep[100010], st[100010], ed[100010], h[100010];
int f[100010][310];
int t[100010];
bool vis[100010];
struct node {
  int id, num;
  bool operator<(const node &T) const { return num < T.num; }
} s[100010];
vector<int> e[100010], Q;
inline void insert(int u, int v) {
  e[u].push_back(v);
  e[v].push_back(u);
}
int find(int x) {
  int sum = 0;
  for (; x; x -= (x & -x)) sum += t[x];
  return sum;
}
void add(int x, int k) {
  for (; x <= n; x += (x & -x)) t[x] += k;
}
void dfs(int x) {
  st[x] = ++cnt;
  for (int i = 0; i < e[x].size(); i++)
    if (fa[0][x] != e[x][i]) {
      fa[0][e[x][i]] = x;
      dep[e[x][i]] = dep[x] + 1;
      dfs(e[x][i]);
    }
  ed[x] = cnt;
}
int lca(int a, int b) {
  int i, kk;
  if (dep[a] != dep[b]) {
    if (dep[a] < dep[b]) swap(a, b);
    i = 0;
    kk = 1;
    while (kk <= dep[a] - dep[b]) {
      i++;
      kk <<= 1;
    }
    while (dep[a] > dep[b]) {
      if (kk <= dep[a] - dep[b]) a = fa[i][a];
      i--;
      kk >>= 1;
    }
  }
  if (a == b) return a;
  i = 0;
  while (fa[i][a] != fa[i][b]) i++;
  while (fa[0][a] != fa[0][b]) {
    if (fa[i][a] != fa[i][b]) {
      a = fa[i][a];
      b = fa[i][b];
    }
    i--;
  }
  return fa[0][a];
}
int main() {
  int a, b;
  scanf("%d%d", &n, &q);
  for (int i = 1; i < n; i++) {
    scanf("%d%d", &a, &b);
    insert(a, b);
  }
  dfs(1);
  f[0][0] = 1ll;
  for (int i = 1; i <= 20; i++)
    for (int j = 1; j <= n; j++) fa[i][j] = fa[i - 1][fa[i - 1][j]];
  while (q--) {
    scanf("%d%d%d", &k, &m, &r);
    Q.clear();
    cnt = ans = 0;
    for (int j = 1; j <= k; j++) {
      scanf("%d", &a);
      Q.push_back(a);
      vis[a] = 1;
      add(st[a], 1);
      add(ed[a] + 1, -1);
    }
    for (int j = 0; j < k; j++) {
      a = Q[j];
      b = lca(r, a);
      h[a] = find(st[a]) + find(st[r]) - 2 * find(st[b]) + vis[b] - 1;
      s[++cnt].id = a;
      s[cnt].num = h[a];
    }
    sort(s + 1, s + 1 + cnt);
    for (int i = 0; i <= m; i++) f[1][i] = 0ll;
    for (int i = 1; i <= k; i++)
      for (int j = 1; j <= m; j++)
        f[i][j] = ((long long)f[i - 1][j] * (j - s[i].num) % 1000000007 +
                   f[i - 1][j - 1]) %
                  1000000007;
    for (int j = 1; j <= m; j++) ans = (ans + f[k][j]) % 1000000007;
    printf("%d\n", ans);
    for (int j = 0; j < k; j++) {
      a = Q[j];
      add(st[a], -1);
      add(ed[a] + 1, 1);
      vis[a] = 0;
    }
  }
  return 0;
}
