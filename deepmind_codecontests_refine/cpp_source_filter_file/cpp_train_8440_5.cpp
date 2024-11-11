#include <bits/stdc++.h>
using namespace std;
const long long N = 3e5 + 10;
const long long P = 1e9 + 7;
const long long inf = 1e9 + 7;
int n, m;
int dfn[N], low[N], idfn;
int Tnum = 1, Tlast[N], Tnxt[2 * N], Tto[2 * N];
int num, last[N], nxt[2 * N], to[2 * N];
bool isbri[N];
int edcc[N], iedcc;
int ans;
void TAdd(int u, int v) {
  Tnxt[++Tnum] = Tlast[u];
  Tto[Tnum] = v;
  Tlast[u] = Tnum;
}
void Add(int u, int v) {
  nxt[++num] = last[u];
  to[num] = v;
  last[u] = num;
}
void Tarjan(int u, int in_edge) {
  dfn[u] = low[u] = ++idfn;
  for (int e = Tlast[u]; e; e = Tnxt[e]) {
    int v = Tto[e];
    if (dfn[v] == 0) {
      Tarjan(v, e);
      low[u] = min(low[u], low[v]);
      if (dfn[u] < low[v]) {
        isbri[e] = 1;
        isbri[e ^ 1] = 1;
      }
    } else if (e != (in_edge ^ 1))
      low[u] = min(low[u], dfn[v]);
  }
}
void dfs(int u, int id) {
  edcc[u] = id;
  for (int e = Tlast[u]; e; e = Tnxt[e]) {
    int v = Tto[e];
    if (edcc[v] || isbri[e] || isbri[e ^ 1]) continue;
    dfs(v, id);
  }
}
void Build() {
  for (int i = 1; i <= n; ++i) {
    if (edcc[i] == 0) {
      iedcc++;
      dfs(i, iedcc);
    }
  }
  for (int u = 1; u <= n; ++u) {
    for (int e = Tlast[u]; e; e = Tnxt[e]) {
      int v = Tto[e];
      if (isbri[e]) {
        Add(edcc[u], edcc[v]);
      }
    }
  }
}
int Find(int u, int fa) {
  int v;
  int L1 = 0, L2 = 0;
  for (int e = last[u]; e; e = nxt[e]) {
    v = to[e];
    if (v == fa) continue;
    int L = Find(v, u);
    if (L + 1 >= L1) {
      L2 = L1;
      L1 = L + 1;
    } else if (L + 1 > L2)
      L2 = L + 1;
  }
  ans = max(ans, L1 + L2);
  return L1;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);
    TAdd(x, y);
    TAdd(y, x);
  }
  Tarjan(1, 0);
  Build();
  Find(1, 0);
  printf("%d", ans);
  return 0;
}
