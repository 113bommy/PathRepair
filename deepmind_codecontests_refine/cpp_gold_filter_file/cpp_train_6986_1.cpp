#include <bits/stdc++.h>
using namespace std;
const int INF = 1e6;
struct Edge {
  int to;
  int next;
  int flow;
  int cost;
} e[2005 << 1];
struct Limit {
  int a, b;
} l[2][2005];
int n;
int in;
int out;
int cnt = 1;
int val[2005];
int dis[2005];
int head[2005];
bool vis[2005];
void Insert(int x, int y, int f, int c) {
  e[++cnt] = (Edge){y, head[x], f, c}, head[x] = cnt;
  e[++cnt] = (Edge){x, head[y], 0, -c}, head[y] = cnt;
}
bool spfa(int s, int t) {
  memset(dis, 0x3f, sizeof(dis));
  memset(vis, 0, sizeof(vis));
  queue<int> q;
  q.push(s);
  dis[s] = 0, vis[s] = 1;
  while (!q.empty()) {
    s = q.front();
    q.pop();
    vis[s] = 0;
    for (int i = head[s]; i; i = e[i].next) {
      int y = e[i].to;
      if (e[i].flow > 0 && dis[y] > dis[s] + e[i].cost) {
        dis[y] = dis[s] + e[i].cost;
        if (!vis[y]) q.push(y), vis[y] = 1;
      }
    }
  }
  return dis[t] < dis[0];
}
int dfs(int s, int flow, int t) {
  if (s == t || flow <= 0) return flow;
  int rest = flow;
  vis[s] = 1;
  for (int i = head[s]; i; i = e[i].next) {
    int y = e[i].to;
    if (e[i].flow > 0 && dis[y] == dis[s] + e[i].cost && !vis[y]) {
      int tmp = dfs(y, min(e[i].flow, rest), t);
      rest -= tmp;
      e[i].flow -= tmp;
      e[i ^ 1].flow += tmp;
      if (rest <= 0) break;
    }
  }
  return flow - rest;
}
int Dinic(int s, int t) {
  int cost = 0, flow = 0;
  while (spfa(s, t)) {
    int tmp = dfs(s, INF, t);
    cost += dis[t] * tmp;
    flow += tmp;
  }
  if (flow ^ in) {
    puts("-1");
    exit(0);
  }
  return cost;
}
int R_int(int x = 0, char c = getchar()) {
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) x = x * 10 + (c ^ '0'), c = getchar();
  return x;
}
namespace Tree_Work {
int cnt[2];
int vis[2][2005];
int tmp[2][2005];
int prt[2][2005];
int head[2][2005];
int size[2][2005];
struct Edge {
  int to;
  int next;
} e[2][2005];
void Insert(int x, int y, int id) {
  e[id][++cnt[id]] = (Edge){y, head[id][x]}, head[id][x] = cnt[id];
}
void dfs(int x, int prt, int id) {
  tmp[id][x] = vis[id][x];
  Tree_Work::prt[id][x] = prt;
  for (int i = head[id][x]; i; i = e[id][i].next) {
    int y = e[id][i].to;
    if (y == prt) continue;
    dfs(y, x, id);
    size[id][x] += tmp[id][y];
    if (!vis[id][x]) tmp[id][x] += tmp[id][y];
  }
}
void Work() {
  int root1 = R_int();
  int root2 = R_int();
  for (int i = 1; i <= n; ++i) ::val[i] = R_int();
  for (int i = 1; i < n; ++i) {
    int x = R_int(), y = R_int();
    Insert(x, y, 0), Insert(y, x, 0);
  }
  for (int i = 1; i < n; ++i) {
    int x = R_int(), y = R_int();
    Insert(x, y, 1), Insert(y, x, 1);
  }
  int q1 = R_int();
  for (int i = 1; i <= q1; ++i) {
    l[0][i].a = R_int();
    l[0][i].b = R_int();
    vis[0][l[0][i].a] = l[0][i].b;
  }
  int q2 = R_int();
  for (int i = 1; i <= q2; ++i) {
    l[1][i].a = R_int();
    l[1][i].b = R_int();
    vis[1][l[1][i].a] = l[1][i].b;
  }
  dfs(root1, 0, 0);
  dfs(root2, 0, 1);
  int S = n * 2 + 1, T = n * 2 + 2;
  for (int i = 1; i <= n; ++i) {
    if (vis[0][i]) {
      if (vis[0][i] < size[0][i]) {
        puts("-1");
        exit(0);
      }
      ::Insert(S, i, vis[0][i] - size[0][i], 0), in += vis[0][i] - size[0][i];
    }
    if (vis[1][i]) {
      if (vis[1][i] < size[1][i]) {
        puts("-1");
        exit(0);
      }
      ::Insert(i + n, T, vis[1][i] - size[1][i], 0),
          out += vis[1][i] - size[1][i];
    }
    int fa1, fa2;
    fa1 = fa2 = i;
    while (!vis[0][fa1]) fa1 = prt[0][fa1];
    while (!vis[1][fa2]) fa2 = prt[1][fa2];
    ::Insert(fa1, fa2 + n, 1, -val[i]);
  }
  if (in ^ out) {
    puts("-1");
    return;
  }
  cout << -Dinic(S, T) << endl;
}
}  // namespace Tree_Work
int main() {
  n = R_int();
  Tree_Work::Work();
  return 0;
}
