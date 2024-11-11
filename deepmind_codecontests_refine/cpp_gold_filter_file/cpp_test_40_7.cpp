#include <bits/stdc++.h>
using namespace std;
const int maxn = 3e5 + 7;
int n, q, m, k, tot;
struct _ {
  int u, v;
} e[maxn];
struct que {
  int a, b;
} qq[maxn];
vector<int> adj[maxn];
int fa[maxn], deg[maxn], dep[maxn];
int get(int x) { return fa[x] == x ? x : fa[x] = get(fa[x]); }
bool merge(int x, int y) {
  int fx = get(x), fy = get(y);
  if (fx ^ fy) {
    fa[fx] = fy;
    adj[x].push_back(y);
    adj[y].push_back(x);
    return true;
  }
  return false;
}
void dfs(int u) {
  for (int i = 0; i < adj[u].size(); i++) {
    int v = adj[u][i];
    if (!dep[v]) {
      fa[v] = u;
      dep[v] = dep[u] + 1;
      dfs(v);
    }
  }
}
vector<int> ansl, ansr;
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &e[i].u, &e[i].v);
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &qq[i].a, &qq[i].b);
    deg[qq[i].a]++;
    deg[qq[i].b]++;
  }
  for (int i = 1; i <= n; i++) {
    k += (deg[i] & 1);
  }
  if (k) {
    printf("NO\n%d\n", k / 2);
    return 0;
  }
  puts("YES");
  for (int i = 1; i <= n; i++) fa[i] = i;
  int rst = n;
  for (int i = 1; i <= m; i++) {
    rst -= merge(e[i].u, e[i].v);
    if (rst == 1) break;
  }
  fa[1] = dep[1] = 1;
  dfs(1);
  for (int i = 1; i <= q; i++) {
    int u = qq[i].a, v = qq[i].b;
    ansl.clear();
    ansr.clear();
    while (u != v) {
      if (dep[u] < dep[v]) {
        ansr.push_back(v);
        v = fa[v];
      } else {
        ansl.push_back(u);
        u = fa[u];
      }
    }
    printf("%d\n", ansl.size() + ansr.size() + 1);
    for (int j = 0; j < ansl.size(); j++) {
      printf("%d ", ansl[j]);
    }
    printf("%d ", u);
    for (int j = ansr.size() - 1; j >= 0; j--) {
      printf("%d ", ansr[j]);
    }
    printf("\n");
  }
}
