#include <bits/stdc++.h>
using namespace std;
int read() {
  int ret = 0;
  char c = getchar();
  while (c < '0' || c > '9') c = getchar();
  while (c >= '0' && c <= '9') {
    ret = ret * 10 + c - '0';
    c = getchar();
  }
  return ret;
}
const int MAXN = 2000, MAXM = 100000;
struct Graph {
  pair<int, int> front[(MAXM << 1) + 10];
  int orderx[(MAXM << 1) + 10], stdx[MAXN + 10];
  int n, m;
  void sortx() {
    static int num[MAXN + 10];
    memset(num, 0, sizeof(num));
    for (int i = 1; i <= m; i++) num[front[i].first]++;
    for (int i = 1; i <= n; i++) stdx[i] = num[i] += num[i - 1];
    for (int i = 1; i <= m; i++) orderx[++num[front[i].first - 1]] = i;
    return;
  }
} G, tr;
int Time, ans;
int dfn[MAXN + 10], low[MAXN + 10];
int st[MAXN + 10], top;
int pos[MAXN + 10];
bool vis[MAXN + 10];
void dfs(int pre, int first) {
  vis[first] = true;
  st[++top] = first;
  dfn[first] = low[first] = ++Time;
  for (int i = G.stdx[first - 1] + 1; i <= G.stdx[first]; i++)
    if (pre != ((G.orderx[i]) + (((G.orderx[i]) & 1) << 1) - 1)) {
      int next = G.front[G.orderx[i]].second;
      if (!dfn[next]) {
        dfs(G.orderx[i], next);
        low[first] = ((low[first]) < (low[next]) ? (low[first]) : (low[next]));
      } else
        low[first] = ((low[first]) < (dfn[next]) ? (low[first]) : (dfn[next]));
    }
  if (low[first] == dfn[first]) {
    tr.n++;
    while (st[top] != first) {
      ans++;
      pos[st[top--]] = tr.n;
    }
    pos[st[top--]] = tr.n;
  }
  return;
}
int leng;
int f[MAXN + 10], g[MAXN + 10];
void count(int fa, int first) {
  int son = 0;
  f[first] = g[first] = -1;
  vis[first] = true;
  for (int i = tr.stdx[first - 1] + 1; i <= tr.stdx[first]; i++) {
    int next = tr.front[tr.orderx[i]].second;
    if (!vis[next]) {
      son++;
      count(first, next);
      if (f[next] + 1 > f[first]) {
        g[first] = f[first];
        f[first] = f[next] + 1;
      } else if (f[next] + 1 > g[first])
        g[first] = f[next] + 1;
    }
  }
  leng = ((leng) > (g[first] + f[first]) ? (leng) : (g[first] + f[first]));
  if (son == 0 || (fa == -1 && son == 1)) ans--;
  return;
}
void init() {
  G.n = read();
  int M = read();
  for (int i = 1; i <= M; i++) {
    int first = read(), second = read();
    G.front[++G.m] = make_pair(first, second);
    G.front[++G.m] = make_pair(second, first);
  }
  G.sortx();
  ans--;
  for (int i = 1; i <= G.n; i++)
    if (!vis[i]) {
      ans++;
      dfs(-1, i);
    }
  ans += tr.n;
  for (int i = 1; i <= G.m; i += 2) {
    int first = G.front[i].first, second = G.front[i].second;
    if (pos[first] != pos[second]) {
      tr.front[++tr.m] = make_pair(pos[first], pos[second]);
      tr.front[++tr.m] = make_pair(pos[second], pos[first]);
    }
  }
  tr.sortx();
  memset(vis, false, sizeof(vis));
  for (int i = 1; i <= tr.n; i++)
    if (!vis[i]) {
      leng = 0;
      count(-1, i);
      leng++;
      ans -= leng;
    }
  cout << ans;
  return;
}
int main() {
  init();
  return 0;
}
