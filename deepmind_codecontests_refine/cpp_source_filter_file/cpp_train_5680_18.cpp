#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
int n, m;
struct Edge {
  int v, c, cost, nxt;
} e[50010];
int tot = 1;
int first[10010];
void build(int u, int v, int c, int cost) {
  e[++tot] = (Edge){v, c, cost, first[u]};
  first[u] = tot;
}
void adde(int u, int v, int c, int cost) {
  build(u, v, c, cost);
  build(v, u, 0, -cost);
  return;
}
int w[10010];
long long ans = 0;
void ADD(int u, int v, int c, int f, bool flag = false) {
  if (c >= f) {
    adde(u, v, c - f, 1);
    adde(v, u, f, 1);
    adde(u, v, INF, 2);
  } else {
    ans += f - c;
    adde(u, v, INF, 2);
    adde(u, v, f - c, 0);
    adde(v, u, c, 1);
  }
  w[u] += f;
  w[v] -= f;
  return;
}
int S, T;
int dis[10010], lste[10010], lstn[10010];
bool book[10010];
queue<int> q;
bool spfa() {
  for (int i = 1; i <= T; i++) dis[i] = INF, book[i] = false;
  q.push(S);
  dis[S] = 0;
  book[S] = true;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    book[u] = false;
    for (int i = first[u]; i; i = e[i].nxt)
      if (e[i].c && dis[u] + e[i].cost < dis[e[i].v]) {
        dis[e[i].v] = dis[u] + e[i].cost;
        lstn[e[i].v] = u;
        lste[e[i].v] = i;
        if (!book[e[i].v]) {
          book[e[i].v] = true;
          q.push(e[i].v);
        }
      }
  }
  return dis[T] != INF;
}
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v, c, f;
    scanf("%d %d %d %d", &u, &v, &c, &f);
    ADD(u, v, c, f);
  }
  adde(1, n, INF, 0);
  adde(n, 1, INF, 0);
  w[1] -= INF;
  w[n] += INF;
  S = n + 1;
  T = n + 2;
  for (int i = 1; i <= n; i++) {
    if (w[i] < 0)
      adde(S, i, -w[i], 0);
    else
      adde(i, T, w[i], 0);
  }
  while (spfa()) {
    int mn = 2 * INF;
    for (int i = T; i != S; i = lstn[i]) {
      int ee = lste[i];
      mn = min(mn, e[ee].c);
    }
    ans = ans + (long long)mn * dis[T];
    for (int i = T; i != S; i = lstn[i]) {
      int ee = lste[i];
      e[ee].c -= mn;
      e[ee ^ 1].c += mn;
    }
  }
  printf("%I64d\n", ans);
  return 0;
}
