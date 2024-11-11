#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 10000 + 16;
int head[maxn];
struct Edge {
  int v, next;
  long long w;
  bool f;
} edge[maxn * 2];
int cnt;
int n, m, s, t;
long long L;
int inque[maxn];
long long d[maxn];
int vis[maxn];
void add(int u, int v, long long w, bool f) {
  edge[cnt].v = v;
  edge[cnt].w = w;
  edge[cnt].f = f;
  edge[cnt].next = head[u];
  head[u] = cnt++;
}
void add_edge(int u, int v, long long w, bool f) {
  add(u, v, w, f);
  add(v, u, w, f);
}
void init() {
  cnt = 0;
  memset(head, -1, sizeof(head));
}
void spfa(int s) {
  memset(vis, 0, sizeof(vis));
  memset(d, INF, sizeof(d));
  memset(inque, false, sizeof(inque));
  queue<int> Q;
  d[s] = 0;
  Q.push(s);
  while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    inque[u] = false;
    for (int i = head[u]; i != -1; i = edge[i].next) {
      int v = edge[i].v;
      long long w = edge[i].w;
      if (d[v] > d[u] + w) {
        d[v] = d[u] + w;
        if (!inque[v]) {
          inque[v] = true;
          Q.push(v);
          if (vis[v] == n) {
            return;
          }
        }
      }
    }
  }
}
bool cal() {
  memset(vis, 0, sizeof(vis));
  queue<int> q;
  q.push(s);
  vis[s] = 1;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int i = head[u]; i != -1; i = edge[i].next) {
      int v = edge[i].v;
      if (v == t) return true;
      if (vis[v]) continue;
      vis[v] = 1;
      q.push(v);
    }
  }
  return false;
}
bool solve() {
  spfa(s);
  if (d[t] > L) return false;
  for (int u = 0; u < n; u++) {
    for (int i = head[u]; i != -1; i = edge[i].next) {
      if (!edge[i].f || (i & 1)) continue;
      if (d[t] == L) return true;
      edge[i].w = edge[i ^ 1].w = L - d[t] + 1;
      spfa(s);
    }
  }
  return d[t] == L;
}
int main() {
  cin >> n >> m >> L >> s >> t;
  init();
  int u, v;
  long long w;
  for (int i = 0; i < m; i++) {
    cin >> u >> v >> w;
    add_edge(u, v, (w ? w : 1), w == 0);
  }
  if (!cal() || !solve()) {
    cout << "NO" << endl;
  } else {
    cout << "YES" << endl;
    for (int i = 0; i < n; i++) {
      for (int j = head[i]; j != -1; j = edge[j].next) {
        if (!(j & 1)) printf("%d %d %I64d\n", i, edge[j].v, edge[j].w);
      }
    }
  }
  return 0;
}
