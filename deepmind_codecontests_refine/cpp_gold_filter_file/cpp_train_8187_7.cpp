#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const long long INFF = 0x3f3f3f3f3f3f3f3fll;
const long long M = 1e9 + 9;
const long long maxn = 4000 + 7;
const double pi = acos(-1.0);
const double eps = 0.00000001;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
template <typename T>
inline T abs(T a) {
  return a > 0 ? a : -a;
}
template <typename T>
inline T powMM(T a, T b) {
  T ret = 1;
  for (; b; b >>= 1ll, a = (long long)a * a % M)
    if (b & 1) ret = (long long)ret * a % M;
  return ret;
}
struct node {
  int to, cap, next;
  node(int t = 0, int c = 0, int n = 0) : to(t), cap(c), next(n) {}
} edge[maxn * 5];
int head[maxn];
int tot;
inline int addedge(int from, int to, int cap, int rcap = 0) {
  edge[tot] = node(to, cap, head[from]);
  head[from] = tot++;
  edge[tot] = node(from, rcap, head[to]);
  head[to] = tot++;
  return tot - 2;
}
queue<int> Q;
bool vis[4007];
int d[4007];
bool bfs(int s, int t) {
  memset(vis, 0, sizeof(vis));
  while (Q.size()) Q.pop();
  Q.push(s);
  d[s] = 0;
  vis[s] = 1;
  while (Q.size()) {
    int x = Q.front();
    Q.pop();
    for (int i = head[x]; ~i; i = edge[i].next) {
      int v = edge[i].to;
      if (!vis[v] && edge[i].cap) {
        vis[v] = 1;
        d[v] = d[x] + 1;
        Q.push(v);
      }
    }
  }
  return vis[t];
}
int dfs(int x, int t, int flow) {
  if (x == t || flow == 0) return flow;
  int i, ret = 0, f;
  for (i = head[x]; ~i; i = edge[i].next) {
    if (d[x] + 1 == d[edge[i].to] &&
        ((f = dfs(edge[i].to, t, min(flow, edge[i].cap))) > 0)) {
      edge[i].cap -= f;
      edge[i ^ 1].cap += f;
      ret += f;
      flow -= f;
      if (flow == 0) break;
    }
  }
  return ret;
}
int sid[maxn], tid[maxn], eid[maxn], d1[maxn], d2[maxn];
vector<int> ans[maxn];
int main() {
  int i, j;
  int n1, n2, m;
  scanf("%d%d%d", &n1, &n2, &m);
  for (i = 1; i <= n1 + n2 + 2; i++) head[i] = -1;
  int s = n1 + n2 + 1, t = n1 + n2 + 2;
  for (i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    d1[u]++;
    d2[v]++;
    eid[i] = addedge(u, v + n1, 1);
  }
  int all = m;
  for (i = 1; i <= n1; i++) all = min(all, d1[i]);
  for (i = 1; i <= n2; i++) all = min(all, d2[i]);
  for (i = 1; i <= n1; i++) sid[i] = addedge(s, i, d1[i] - all);
  for (i = 1; i <= n2; i++) tid[i] = addedge(i + n1, t, d2[i] - all);
  for (j = all; j >= 0; j--) {
    while (bfs(s, t)) dfs(s, t, n1);
    for (i = 1; i <= m; i++)
      if (edge[eid[i]].cap) ans[j].push_back(i);
    for (i = 1; i <= n1; i++) edge[sid[i]].cap++;
    for (i = 1; i <= n2; i++) edge[tid[i]].cap++;
  }
  for (j = 0; j <= all; j++) {
    printf("%d", (int)ans[j].size());
    for (int v : ans[j]) printf(" %d", v);
    puts("");
  }
  return 0;
}
