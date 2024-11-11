#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 5;
const int Mod = 1000000007;
const int INF = 0x3f3f3f3f;
const long long LL_INF = 0x3f3f3f3f3f3f3f3f;
const double e = exp(1);
const double PI = acos(-1);
const double ERR = 1e-10;
int head[maxn], n, m, cnt, tot, top, num, s;
int dfn[maxn], low[maxn], st[maxn], col[maxn], indeg[maxn], topo[maxn],
    pos[maxn];
bool instack[maxn];
long long a[maxn], prefix[maxn], dp[maxn];
struct edge {
  int u, v, nxt;
  long long w;
} Edge[maxn];
void init() {
  for (int i = 0; i <= n; i++) head[i] = -1;
  cnt = 0;
}
void addedge(int u, int v, long long w) {
  Edge[cnt].u = u;
  Edge[cnt].v = v;
  Edge[cnt].w = w;
  Edge[cnt].nxt = head[u];
  head[u] = cnt++;
}
void tarjan(int id) {
  dfn[id] = low[id] = ++tot;
  st[++top] = id;
  instack[id] = true;
  for (int i = head[id]; i != -1; i = Edge[i].nxt) {
    int v = Edge[i].v;
    if (!dfn[v]) {
      tarjan(v);
      low[id] = min(low[id], low[v]);
    } else if (instack[v])
      low[id] = min(low[id], dfn[v]);
  }
  if (dfn[id] == low[id]) {
    int v;
    num++;
    do {
      v = st[top--];
      instack[v] = false;
      col[v] = num;
    } while (v != id);
  }
}
void toposort() {
  queue<int> que;
  for (int i = 1; i <= num; i++) {
    if (!indeg[i]) que.push(i);
  }
  int flag = 0;
  while (!que.empty()) {
    int now = que.front();
    que.pop();
    topo[++flag] = now;
    for (int i = head[now]; i != -1; i = Edge[i].nxt) {
      int v = Edge[i].v;
      --indeg[v];
      if (!indeg[v]) que.push(v);
    }
  }
}
int main() {
  int u, v;
  long long w;
  scanf("%d%d", &n, &m);
  init();
  for (int i = 1; i <= m; i++) {
    scanf("%d%d%lld", &u, &v, &w);
    addedge(u, v, w);
  }
  scanf("%d", &s);
  for (int i = 1; i <= n; i++) {
    if (!dfn[i]) tarjan(i);
  }
  init();
  long long sum = 0;
  for (int i = 1; i <= 20000; i++) {
    sum = sum + 1LL * i;
    prefix[i] = prefix[i - 1] + sum;
  }
  for (int i = 0; i < m; i++) {
    u = Edge[i].u;
    v = Edge[i].v;
    w = Edge[i].w;
    if (col[u] == col[v]) {
      long long k = sqrt(8.0 * w + 1.0) / 2;
      a[col[u]] += ((k + 1) * w - prefix[k]);
      continue;
    } else {
      addedge(col[u], col[v], w);
      indeg[col[v]]++;
    }
  }
  toposort();
  for (int i = 1; i <= num; i++) pos[topo[i]] = i;
  for (int i = 1; i <= num; i++) dp[i] = -0x3f3f3f3f3f3f3f3f;
  dp[col[s]] = a[col[s]];
  for (int i = 1; i <= num; i++) {
    int u = topo[i];
    for (int j = head[u]; j != -1; j = Edge[j].nxt) {
      int v = Edge[j].v;
      if (pos[v] > pos[u]) dp[v] = max(dp[v], dp[u] + Edge[j].w + a[v]);
    }
  }
  long long ans = 0;
  for (int i = 1; i <= num; i++) ans = max(ans, dp[i]);
  printf("%lld\n", ans);
  return 0;
}
