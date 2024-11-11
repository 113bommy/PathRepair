#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 2e5 + 10;
int tot, col, n, m, ans, c[maxn], head[maxn];
int vis[maxn], dfn[maxn], low[maxn], nn, val[maxn], in[maxn], in2[maxn];
vector<int> link[maxn];
stack<int> s;
int readint() {
  int x;
  scanf("%d", &x);
  return x;
}
struct node {
  int from, to, nxt;
} p[600010];
void add(int x, int y) {
  tot++;
  p[tot].from = x;
  p[tot].to = y;
  p[tot].nxt = head[x];
  head[x] = tot;
}
void tarjan(int x) {
  vis[x] = 1;
  dfn[x] = ++nn;
  low[x] = nn;
  s.push(x);
  for (int i = head[x]; i; i = p[i].nxt) {
    int nc = p[i].to;
    if (!dfn[nc]) {
      tarjan(nc);
      low[x] = min(low[x], low[nc]);
    } else if (vis[nc])
      low[x] = min(low[x], dfn[nc]);
  }
  if (low[x] == dfn[x]) {
    col++;
    while (s.size() && s.top() != x) {
      vis[s.top()] = 0;
      c[s.top()] = col;
      link[col].push_back(s.top());
      s.pop();
    }
    c[s.top()] = col;
    link[col].push_back(s.top());
    vis[s.top()] = 0;
    s.pop();
  }
  return;
}
bool check(int x) {
  for (auto i : link[x])
    if (vis[i] < 2) return 0;
  return 1;
}
void bfs(int x) {
  queue<int> q1, q2;
  in[x] = vis[x] = 1;
  q1.push(x);
  q2.push(x);
  while (q1.size()) {
    int cur = q1.front();
    q1.pop();
    for (int i = head[cur]; i; i = p[i].nxt) {
      int nc = p[i].to;
      if (in2[nc]) continue;
      if (vis[nc] < 2) {
        vis[nc]++;
        q1.push(nc);
        if (!in[nc]) {
          in[nc] = 1;
          q2.push(nc);
        }
      }
    }
  }
  while (q2.size()) {
    in2[q2.front()] = 1;
    q2.pop();
  }
  return;
}
int main() {
  n = readint();
  for (int i = 1; i <= n; i++) val[i] = readint();
  for (int i = 1; i <= n; i++) add(i, readint());
  for (int i = 1; i <= n; i++)
    if (!c[i]) tarjan(i);
  memset(vis, 0, sizeof(vis));
  for (int i = 1; i <= n; i++)
    if (!in2[i]) bfs(i);
  for (int i = 1; i <= col; i++) {
    int minn = INF;
    if (!check(i)) continue;
    for (auto j = link[i].begin(); j != link[i].end(); j++)
      minn = min(minn, val[*j]);
    ans += minn;
  }
  printf("%d\n", ans);
}
