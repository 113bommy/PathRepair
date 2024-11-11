#include <bits/stdc++.h>
using namespace std;
template <class T>
void _R(T &x) {
  cin >> x;
}
void _R(int &x) { scanf("%d", &x); }
void _R(long long &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template <class T, class... U>
void R(T &head, U &...tail) {
  _R(head);
  R(tail...);
}
const int inf = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int maxn = 55;
int st[maxn];
struct E {
  int u, v, w, cost;
  int nxt;
} edge[500009];
int gtot = 0, head[maxn * 100];
void addedge(int u, int v, int w, int cost) {
  edge[gtot].v = v;
  edge[gtot].w = w;
  edge[gtot].cost = cost;
  edge[gtot].nxt = head[u];
  head[u] = gtot++;
  edge[gtot].v = u;
  edge[gtot].w = 0;
  edge[gtot].cost = -cost;
  edge[gtot].nxt = head[v];
  head[v] = gtot++;
}
int dis[maxn * 100], path[500009], vis[maxn * 100], pre[maxn * 100];
bool spfa(int s, int t) {
  memset(pre, -1, sizeof(pre));
  memset(dis, inf, sizeof(dis));
  memset(vis, 0, sizeof(vis));
  queue<int> que;
  que.push(s);
  vis[s] = 1;
  dis[s] = 0;
  while (!que.empty()) {
    int u = que.front();
    que.pop();
    vis[u] = 0;
    for (int i = head[u]; ~i; i = edge[i].nxt) {
      int v = edge[i].v, val = edge[i].w, cost = edge[i].cost;
      if (val > 0 && dis[v] > dis[u] + cost) {
        dis[v] = dis[u] + cost;
        pre[v] = u;
        path[v] = i;
        if (vis[v] == 0) {
          vis[v] = 1;
          que.push(v);
        }
      }
    }
  }
  return pre[t] != -1;
}
int mcmf(int s, int t) {
  int flow = 0, cost = 0;
  while (spfa(s, t)) {
    int f = inf;
    for (int i = t; i != s; i = pre[i]) {
      f = min(f, edge[path[i]].w);
    }
    flow += f;
    cost += f * dis[t];
    for (int i = t; i != s; i = pre[i]) {
      edge[path[i]].w -= f;
      edge[path[i] ^ 1].w += f;
    }
  }
  return cost;
}
int main() {
  memset(head, -1, sizeof(head));
  gtot = 0;
  int n, m, k, c, d;
  R(n, m, k, c, d);
  for (int i = 1; i <= k; i++) {
    int x;
    scanf("%d", &x);
    st[x]++;
  }
  int s = 0, t = 100 * n + 1;
  for (int i = 1; i <= n; i++) {
    for (int j = 2; j <= 100; j++) {
      addedge((i - 1) * 100 + j - 1, (i - 1) * 100 + j, inf, c);
    }
  }
  for (int i = 2; i <= n; i++) {
    if (st[i]) addedge(s, (i - 1) * 100 + 1, st[i], 0);
  }
  for (int i = 1; i <= 100; i++) addedge(i, t, inf, 0);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d%d", &u, &v);
    for (int j = 2; j <= 100; j++) {
      for (int k = 1; k <= 13; k++) {
        addedge((u - 1) * 100 + j - 1, (v - 1) * 100 + j, 1,
                (k * k - (k - 1) * (k - 1)) * d + c);
        addedge((v - 1) * 100 + j - 1, (u - 1) * 100 + j, 1,
                (k * k - (k - 1) * (k - 1)) * d + c);
      }
    }
  }
  printf("%d\n", mcmf(s, t));
  return 0;
}
