#include <bits/stdc++.h>
using namespace std;
int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch - '0' < 0 || ch - '0' > 9) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch - '0' >= 0 && ch - '0' <= 9) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
int n, m, ans, s, t;
int deg[105];
int head[105], nxt[410 * 2], to[410 * 2], c[410 * 2], v[410 * 2], tot = 1;
void add(int x, int y, int z, int h) {
  tot++;
  nxt[tot] = head[x];
  head[x] = tot;
  to[tot] = y;
  c[tot] = z;
  v[tot] = h;
}
void work(int x, int y, int z, int h) {
  add(x, y, z, h);
  add(y, x, 0, -h);
}
int dis[105], pre[105], pre_num[105], in[105];
queue<int> q;
int spfa() {
  for (int i = 1; i <= t; i++) dis[i] = 1000000007;
  q.push(s);
  dis[s] = 0;
  in[s] = 1;
  while (q.size()) {
    int now = q.front();
    q.pop();
    in[now] = 0;
    for (int i = head[now]; i; i = nxt[i]) {
      if (dis[to[i]] > dis[now] + v[i] && c[i]) {
        dis[to[i]] = dis[now] + v[i];
        pre[to[i]] = now;
        pre_num[to[i]] = i;
        if (!in[to[i]]) q.push(to[i]), in[to[i]] = 1;
      }
    }
  }
  if (dis[t] == 1000000007) return 0;
  int di = 1000000007;
  for (int i = t; i != s; i = pre[i]) di = min(di, c[pre_num[i]]);
  for (int i = t; i != s; i = pre[i])
    c[pre_num[i]] -= di, c[pre_num[i] ^ 1] += di;
  ans += di * dis[t];
  return di;
}
int main() {
  n = read();
  m = read();
  s = n + 1;
  t = n + 2;
  for (int i = 1; i <= m; i++) {
    int u = read(), v = read(), x = read(), y = read();
    deg[v] += y;
    deg[u] -= y;
    if (y > x)
      ans += y - x, work(u, v, 1000000007, 2), work(v, u, y - x, 0),
          work(v, u, x, 1);
    else
      work(u, v, 1000000007, 2), work(u, v, x - y, 1), work(v, u, y, 1);
  }
  work(n, 1, 1000000007, 0);
  for (int i = 1; i <= n; i++) {
    if (deg[i] > 0)
      add(s, i, deg[i], 0), add(i, s, 0, 0);
    else
      add(i, t, -deg[i], 0), add(t, i, 0, 0);
  }
  while (spfa()) {
  }
  printf("%d\n", ans);
  return 0;
}
