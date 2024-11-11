#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
struct Edge {
  int from, to, next;
} edge[300005];
int head[300005], edgenum;
vector<int> G[300005];
int in[300005];
int low[300005], dfn[300005];
int dfs_clock;
int sccno[300005], scc_cnt;
stack<int> S;
bool Instack[300005];
int color[300005];
int fp[300005];
int N, n, m, b[300005];
vector<int> a[300005];
void init() {
  edgenum = 0;
  memset(head, -1, sizeof(head));
}
void addEdge(int u, int v) {
  Edge E = {u, v, head[u]};
  edge[edgenum] = E;
  head[u] = edgenum++;
}
void tarjan(int u) {
  int v;
  low[u] = dfn[u] = ++dfs_clock;
  S.push(u);
  Instack[u] = true;
  for (int i = head[u]; i != -1; i = edge[i].next) {
    v = edge[i].to;
    if (!dfn[v]) {
      tarjan(v);
      low[u] = min(low[u], low[v]);
    } else if (Instack[v])
      low[u] = min(low[u], dfn[v]);
  }
  if (low[u] == dfn[u]) {
    scc_cnt++;
    for (;;) {
      v = S.top();
      S.pop();
      Instack[v] = false;
      sccno[v] = scc_cnt;
      if (v == u) break;
    }
  }
}
void find_cut(int l, int r) {
  memset(low, 0, sizeof(low));
  memset(dfn, 0, sizeof(dfn));
  memset(sccno, 0, sizeof(sccno));
  memset(Instack, false, sizeof(Instack));
  dfs_clock = scc_cnt = 0;
  for (int i = l; i <= r; i++)
    if (!dfn[i]) tarjan(i);
}
void reMap() {
  for (int i = 1; i <= scc_cnt; i++) G[i].clear(), in[i] = 0;
  for (int i = 0; i < edgenum; i++) {
    int u = sccno[edge[i].from];
    int v = sccno[edge[i].to];
    if (u != v) G[v].push_back(u), in[u]++;
  }
}
void toposort() {
  queue<int> Q;
  memset(color, 0, sizeof(color));
  for (int i = 1; i <= scc_cnt; i++)
    if (in[i] == 0) Q.push(i);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    if (color[u] == 0) {
      color[u] = 1;
      color[fp[u]] = 2;
    }
    for (int i = 0; i < int(G[u].size()); i++) {
      int v = G[u][i];
      if (--in[v] == 0) Q.push(v);
    }
  }
}
void solve() {
  memset(fp, 0, sizeof(fp));
  for (int i = 0; i < N; i++) {
    if (sccno[2 * i] == sccno[2 * i + 1]) {
      printf("No\n");
      return;
    } else {
      fp[sccno[2 * i]] = sccno[2 * i + 1];
      fp[sccno[2 * i + 1]] = sccno[2 * i];
    }
  }
  reMap();
  toposort();
  printf("Yes\n");
  int tot = 0;
  for (int i = 0; i < N; i++)
    if (color[sccno[2 * i + 1]] == 1) tot++;
  printf("%d\n", tot);
  for (int i = 0; i < N; i++)
    if (color[sccno[2 * i + 1]] == 1) printf("%d ", i + 1);
  printf("\n");
}
int main() {
  init();
  n = read();
  N = read();
  for (int i = (1); i <= (n); ++i) {
    b[i] = read();
    for (int j = (1); j <= (b[i]); ++j) a[i].push_back(read() - 1);
  }
  for (int i = (1); i <= (n - 1); ++i) {
    int x = -1;
    for (int j = (0); j <= (min(b[i], b[i + 1]) - 1); ++j)
      if (a[i][j] != a[i + 1][j]) {
        x = j;
        break;
      }
    if (x != -1) {
      if (a[i][x] < a[i + 1][x]) {
        addEdge(a[i][x] * 2, a[i + 1][x] * 2);
        addEdge(a[i + 1][x] * 2 + 1, a[i][x] * 2 + 1);
      } else {
        addEdge(a[i][x] * 2, a[i][x] * 2 + 1);
        addEdge(a[i + 1][x] * 2 + 1, a[i + 1][x] * 2);
      }
    } else if (b[i] > b[i + 1]) {
      printf("No\n");
      return 0;
    }
  }
  find_cut(0, 2 * N - 1);
  solve();
  return 0;
}
