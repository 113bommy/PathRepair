#include <bits/stdc++.h>
using namespace std;
const int N = 205, M = 40005;
struct edge {
  int to, next, f;
} e[M];
int head[N], tot = 1, sum;
int dis[N], q[N], n, top;
int fl[M], a[N], SS[2];
int id[N][N], vis[N], S, T;
vector<int> vec[N];
vector<int> ans[N];
void init() {
  for (int i = (int)(2); i <= (int)((M - 1)); i++)
    for (int j = (int)(2); j <= (int)((M - 1) / i); j++) fl[i * j] = 1;
}
void add(int x, int y, int f) {
  e[++tot] = (edge){y, head[x], f};
  head[x] = tot;
  e[++tot] = (edge){x, head[y], 0};
  head[y] = tot;
}
bool bfs() {
  for (int i = (int)(1); i <= (int)(T); i++) dis[i] = -1;
  int h = 0, t = 1;
  q[1] = S;
  dis[S] = 0;
  while (h != t) {
    int x = q[++h];
    for (int i = head[x]; i; i = e[i].next)
      if (dis[e[i].to] == -1 && e[i].f) {
        dis[e[i].to] = dis[x] + 1;
        q[++t] = e[i].to;
      }
  }
  return dis[T] != -1;
}
int dfs(int x, int flow) {
  if (x == T) return flow;
  int k, rest = flow;
  for (int i = head[x]; i && rest; i = e[i].next)
    if (dis[e[i].to] == dis[x] + 1 && e[i].f) {
      k = dfs(e[i].to, min(rest, e[i].f));
      e[i].f -= k;
      e[i ^ 1].f += k;
      rest -= k;
    }
  if (rest) dis[x] = -1;
  return flow - rest;
}
void getans(int x, int be) {
  ans[be].push_back(x);
  vis[x] = 1;
  for (auto i : vec[x])
    if (!vis[i]) getans(i, be);
}
int main() {
  init();
  scanf("%d", &n);
  for (int i = (int)(1); i <= (int)(n); i++) {
    scanf("%d", &a[i]);
    ++SS[a[i] & 1];
  }
  if (SS[0] != SS[1]) return puts("Impossible"), 0;
  S = n + 1;
  T = S + 1;
  for (int i = (int)(1); i <= (int)(n); i++)
    if (a[i] & 1)
      add(i, T, 2);
    else
      add(S, i, 2);
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(n); j++)
      if (a[i] % 2 == 0 && !fl[a[i] + a[j]]) add(i, j, 1), id[i][j] = tot;
  for (; bfs(); sum += dfs(S, 1 << 30))
    ;
  if (sum != n) return puts("Impossible"), 0;
  for (int i = (int)(1); i <= (int)(n); i++)
    for (int j = (int)(1); j <= (int)(n); j++)
      if (id[i][j] && e[id[i][j]].f) vec[i].push_back(j), vec[j].push_back(i);
  for (int i = (int)(1); i <= (int)(n); i++)
    if (!vis[i]) getans(i, ++top);
  printf("%d\n", top);
  for (int i = (int)(1); i <= (int)(top); i++) {
    printf("%d", ans[i].size());
    for (auto j : ans[i]) printf(" %d", j);
    puts("");
  }
}
