#include <bits/stdc++.h>
using namespace std;
int n, m;
int fa[500010], ind[500010];
struct node {
  int to, next;
} edge[500010 * 10];
int head[500010], sumedge, poi[500010], tot, pos[500010];
int cnt, num[500010];
vector<int> v[500010];
bool used[500010], g[1005][1005];
map<pair<int, int>, bool> mmm;
int getfa(int x) { return fa[x] == x ? x : fa[x] = getfa(fa[x]); }
void add(int u, int v) {
  edge[++sumedge].to = v;
  edge[sumedge].next = head[u];
  head[u] = sumedge;
}
void merge(int u, int v) { fa[getfa(u)] = getfa(v); }
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    fa[i] = i;
  }
  int ui, vi;
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &ui, &vi);
    if (ui == vi) continue;
    if (vi < ui) swap(ui, vi);
    if (mmm.count(make_pair(ui, vi))) continue;
    add(ui, vi);
    add(vi, ui);
    ind[ui]++;
    ind[vi]++;
    mmm[make_pair(ui, vi)] = 1;
  }
  for (int i = 1; i <= n; ++i) fa[i] = i;
  int id = 1, rem = 0;
  for (int i = 2; i <= n; ++i) {
    if (ind[i] < ind[id]) id = i;
  }
  for (int i = head[id]; i; i = edge[i].next) {
    int v = edge[i].to;
    if (used[v]) continue;
    used[v] = 1;
    poi[++tot] = v;
    pos[v] = tot;
  }
  used[id] = 1;
  poi[++tot] = id;
  pos[id] = tot;
  for (int i = 1; i <= n; ++i) {
    if (!used[i]) {
      merge(id, i);
      ++rem;
    }
  }
  memset(g, 1, sizeof(g));
  for (int i = 1; i <= tot; ++i) {
    int u = poi[i];
    for (int j = head[u]; j; j = edge[j].next) {
      int v = edge[j].to;
      if (used[v]) {
        g[pos[v]][pos[u]] = 0;
        g[pos[u]][pos[v]] = 0;
      }
    }
  }
  for (int i = 1; i <= tot; ++i) {
    int t = 0;
    for (int j = 1; j <= tot; ++j) {
      if (i == j) continue;
      if (g[i][j]) {
        merge(poi[i], poi[j]);
      } else {
        ++t;
      }
    }
    if (ind[poi[i]] - t < rem) merge(poi[i], id);
  }
  for (int i = 1; i <= n; ++i) {
    if (i == getfa(i)) num[i] = ++cnt;
  }
  for (int i = 1; i <= n; ++i) {
    v[getfa(i)].push_back(i);
  }
  printf("%d\n", cnt);
  for (int i = 1; i <= n; ++i) {
    if (i == getfa(i)) {
      int s = v[i].size();
      printf("%d", s);
      for (int j = 0; j < s; ++j) {
        printf(" %d", v[i][j]);
      }
      putchar('\n');
    }
  }
  return 0;
}
