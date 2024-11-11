#include <bits/stdc++.h>
using namespace std;
const int maxn = 5e6 + 100;
char sch[55];
int cur, scc;
stack<int> st;
int dfn[maxn], low[maxn], bel[maxn];
int n, m, d;
struct edge {
  int to, nxt;
} edges[maxn], edges2[maxn];
int head[maxn], cnt2, head2[maxn], cnt3;
void init() {
  cnt2 = cnt3 = 0;
  memset(head, -1, sizeof(head));
  memset(head2, -1, sizeof(head2));
}
void addedge(int u, int v) {
  edges[cnt2] = {v, head[u]};
  head[u] = cnt2++;
}
void addedge2(int u, int v) {
  edges2[cnt3] = {v, head2[u]};
  head2[u] = cnt3++;
}
void dfs(int u) {
  dfn[u] = low[u] = ++cur;
  st.push(u);
  for (int i = head[u]; i != -1; i = edges[i].nxt) {
    int v = edges[i].to;
    if (!dfn[v]) {
      dfs(v);
      low[u] = min(low[v], low[u]);
    } else if (!bel[v])
      low[u] = min(low[u], dfn[v]);
  }
  if (dfn[u] == low[u]) {
    scc++;
    while (1) {
      int t = st.top();
      st.pop();
      bel[t] = scc;
      if (t == u) break;
    }
  }
}
int cnt[maxn];
void SCC() {
  for (int i = 0; i < n * d; i++)
    if (!dfn[i]) dfs(i);
  memset(dfn, 0, sizeof(dfn));
  for (int i = 0; i < n * d; i++) {
    for (int j = head[i]; j != -1; j = edges[j].nxt) {
      int u = i, v = edges[j].to;
      if (bel[u] != bel[v]) {
        addedge2(bel[v], bel[u]);
        dfn[bel[u]]++;
      }
    }
  }
}
inline int getid(int i, int j) { return (i - 1) * d + j % d; }
int dp[maxn];
int solve() {
  queue<int> q;
  for (int i = 1; i <= scc; i++)
    if (!dfn[i]) {
      q.push(i);
      dp[i] = cnt[i];
    }
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int j = head2[u]; j != -1; j = edges2[j].nxt) {
      int v = edges2[j].to;
      dp[v] = max(dp[v], dp[u] + cnt[u]);
      dfn[v]--;
      if (!dfn[v]) q.push(v);
    }
  }
  return dp[bel[0]];
}
int main() {
  init();
  scanf("%d%d%d", &n, &m, &d);
  for (int i = 0, u, v; i < m; i++) {
    scanf("%d%d", &u, &v);
    for (int j = 0; j < d; j++) addedge(getid(u, j), getid(v, j + 1));
  }
  SCC();
  vector<int> vis(scc + 1, 0);
  for (int i = 1; i <= n; i++) {
    scanf("%s", sch);
    for (int j = 0; j < d; j++) {
      int id = getid(i, j);
      if (sch[j] == '1' && !vis[bel[id]]) {
        vis[bel[id]] = 1;
        cnt[bel[id]]++;
      }
    }
    for (int j = 0; j < d; j++) vis[bel[getid(i, j)]] = 0;
  }
  printf("%d\n", solve());
}
