#include <bits/stdc++.h>
const int inf = 1e9;
using namespace std;
int s, t, n, m, tot, res, x, y, cnt, now;
int head[205], cur[205], uu[205], dis[205], c[10050][205];
map<int, int> mp;
struct node {
  int x, y;
} a[205];
struct edge {
  int obj, pre, c;
} e[200500];
void insert(int x, int y, int c) {
  e[++tot].obj = y;
  e[tot].pre = head[x];
  head[x] = tot;
  e[tot].c = c;
  e[++tot].obj = x;
  e[tot].pre = head[y];
  head[y] = tot;
  e[tot].c = 0;
}
bool bfs() {
  for (int i = 0; i <= t; i++) uu[i] = -1;
  queue<int> q;
  q.push(0);
  uu[0] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (int j = head[u]; j; j = e[j].pre) {
      int v = e[j].obj;
      if (uu[v] == -1 && e[j].c) {
        uu[v] = uu[u] + 1;
        q.push(v);
      }
    }
  }
  if (uu[t] == -1) return 0;
  return 1;
}
int dfs(int x, int mx) {
  if (x == t) return mx;
  int used = 0;
  for (int j = cur[x]; j; j = e[j].pre) {
    int v = e[j].obj;
    if (uu[v] == uu[x] + 1 && e[j].c) {
      int w = dfs(v, min(e[j].c, mx - used));
      e[j].c -= w;
      e[j ^ 1].c += w;
      used += w;
      if (e[j].c) cur[x] = j;
      if (used == mx) return mx;
    }
  }
  if (!used) uu[x] = -1;
  return used;
}
int dinic() {
  int ans = 0;
  while (bfs()) {
    for (int i = 0; i <= t; i++) cur[i] = head[i];
    ans += dfs(0, inf);
  }
  return ans;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &x);
    for (int j = 2; j * j <= x; j++) {
      if (x % j == 0) {
        if (!mp[j]) mp[j] = ++cnt;
        now = mp[j];
        while (x % j == 0) x /= j, c[now][i]++;
      }
    }
    if (x != 1) {
      if (!mp[x]) mp[x] = ++cnt;
      now = mp[x];
      c[now][i] = 1;
    }
  }
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &a[i].x, &a[i].y);
    if (a[i].y & 1) swap(a[i].x, a[i].y);
  }
  s = 0;
  t = 2 * n + 1;
  for (int o = 1; o <= cnt; o++) {
    tot = 1;
    for (int i = 0; i <= t; i++) head[i] = 0;
    for (int i = 1; i <= n; i++) {
      if (!c[o][i]) continue;
      if (i & 1)
        insert(s, i, c[o][i]);
      else
        insert(i + n, t, c[o][i]);
    }
    for (int i = 1; i <= m; i++) {
      x = a[i].x, y = a[i].y;
      if (!c[o][x] || !c[o][y]) continue;
      insert(x, y + n, inf);
    }
    res += dinic();
  }
  printf("%d\n", res);
  return 0;
}
