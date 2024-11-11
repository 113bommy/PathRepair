#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 5;
int n, m, h, C[maxn];
int head[maxn], to[maxn << 1], nex[maxn << 1], cnt, degree[maxn];
int dfn[maxn], low[maxn], scc, siz[maxn], idx, vis[maxn], answer[maxn], ans;
stack<int> S;
inline void get_min(int &a, int b) {
  if (a > b) a = b;
}
struct Graph {
  inline void add_edge(int u, int v) {
    nex[++cnt] = head[u];
    head[u] = cnt;
    to[cnt] = v;
  }
  void tarjan(int u) {
    low[u] = dfn[u] = ++scc;
    S.push(u);
    vis[u] = 1;
    for (int v = head[u]; v; v = nex[v]) {
      if (!vis[to[v]]) {
        tarjan(to[v]);
        low[u] = min(low[u], low[to[v]]);
      } else if (!answer[to[v]])
        get_min(low[u], dfn[to[v]]);
    }
    if (dfn[u] == low[u]) {
      ++idx;
      for (;;) {
        int x = S.top();
        S.pop();
        answer[x] = idx;
        ++siz[idx];
        if (u == x) break;
      }
    }
  }
  inline void solve() {
    siz[0] = maxn;
    for (int i = 1; i <= n; ++i)
      if (!vis[i]) tarjan(i);
    for (int i = 1; i <= n; ++i) {
      for (int j = head[i]; j; j = nex[j]) {
        if (answer[to[j]] != answer[i]) ++degree[answer[i]];
      }
    }
    for (int i = 1; i <= idx; ++i) {
      if (degree[i]) continue;
      if (siz[ans] > siz[i]) ans = i;
    }
    printf("%d\n", ans);
    for (int i = 1; i <= n; ++i) {
      if (answer[i] == ans) printf("%d ", i);
    }
    printf("\n");
  }
} T;
int main() {
  scanf("%d%d%d", &n, &m, &h);
  for (int i = 1; i <= n; ++i) scanf("%d", &C[i]);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    if (((C[a] + 1) % h) == C[b]) T.add_edge(a, b);
    if (((C[b] + 1) % h) == C[a]) T.add_edge(b, a);
  }
  T.solve();
  return 0;
}
