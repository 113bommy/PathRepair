#include <bits/stdc++.h>
using namespace std;
int n, m, p, head[160010], o = 1, S, T, id[210][210][2], cnt = 0, dep[160010],
                           tmp[160010], ans = 0;
char s[210][210];
struct edge {
  int to, link, w;
} e[320010];
void add_edge(int u, int v, int w) {
  e[++o].to = v, e[o].link = head[u], head[u] = o, e[o].w = w;
  e[++o].to = u, e[o].link = head[v], head[v] = o, e[o].w = 0;
}
queue<int> q;
bool bfs() {
  for (int i = 1; i <= cnt; i++) dep[i] = 0, tmp[i] = head[i];
  dep[S] = 1;
  q.push(S);
  while (!q.empty()) {
    int now = q.front();
    q.pop();
    for (int i = head[now]; i; i = e[i].link) {
      if (dep[e[i].to] || !e[i].w) continue;
      dep[e[i].to] = dep[now] + 1;
      q.push(e[i].to);
    }
  }
  return dep[T];
}
int dfs(int u, int in) {
  if (u == T) return in;
  int out = 0;
  for (int i = tmp[u]; i && in; i = e[i].link) {
    if (!e[i].w || dep[e[i].to] != dep[u] + 1) continue;
    int res = dfs(e[i].to, min(in, e[i].w));
    in -= res, out += res;
    e[i].w -= res, e[i ^ 1].w += res;
    tmp[u] = i;
  }
  if (!out) dep[u] = 0;
  return out;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) scanf("%s", s[i] + 1);
  S = ++cnt, T = ++cnt;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= m; j++)
      if (s[i][j] == '#') {
        ans++;
        if (s[i][j + 1] == '#')
          id[i][j][1] = ++cnt, add_edge(S, id[i][j][1], 1);
        if (s[i + 1][j] == '#')
          id[i][j][0] = ++cnt, add_edge(id[i][j][0], T, 1);
      }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (s[i][j] == '#') {
        for (int k = -1; k <= 1; k += 2) {
          if (s[i][j + k] == '#') {
            for (int l = -1; l <= 1; l += 2) {
              if (s[i + l][j] == '#')
                add_edge(id[i][j + (k < 0 ? -1 : 0)][1],
                         id[i + (l < 0 ? -1 : 0)][j][0], 1);
            }
          }
        }
      }
    }
  }
  while (bfs()) ans += dfs(S, 2e9);
  printf("%d\n", ans - cnt + 2);
}
