#include <bits/stdc++.h>
using namespace std;
inline int read() {
  int x = 0, f = 1;
  char ch = getchar();
  while (ch < '0' || ch > '9') {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (ch >= '0' && ch <= '9') {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  return x * f;
}
int n, m;
int head[200005], nxt[400005], v[400005], w[400005], cnt = 1;
inline void add(int x, int y, int z) {
  v[++cnt] = y;
  w[cnt] = z;
  nxt[cnt] = head[x];
  head[x] = cnt;
}
int dis[200005], len[200005], fa[200005];
bool vis[200005];
priority_queue<pair<int, int>, vector<pair<int, int> >,
               greater<pair<int, int> > >
    Q;
queue<int> q;
inline void dijkstra(int start) {
  memset(dis, 999999, sizeof(dis));
  memset(len, 999999, sizeof(len));
  memset(fa, -1, sizeof(fa));
  dis[start] = 0;
  len[start] = 1;
  q.push(start);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    Q.push(make_pair(0, x));
    for (int i = head[x]; ~i; i = nxt[i])
      if (dis[x] && !w[i])
        q.push(v[i]), dis[v[i]] = 0, fa[v[i]] = (i ^ 1), len[v[i]] = len[x] + 1;
  }
  int rank = 0, las = -1;
  while (!Q.empty()) {
    int x = Q.top().second;
    Q.pop();
    if (vis[x]) continue;
    vis[x] = 1;
    if (las != dis[x]) las = dis[x], rank++;
    for (int i = head[x]; ~i; i = nxt[i])
      if (dis[v[i]] > rank * 10 + w[i]) {
        dis[v[i]] = rank * 10 + w[i];
        fa[v[i]] = (i ^ 1);
        len[v[i]] = len[x] + 1;
        Q.push(make_pair(dis[v[i]], v[i]));
      } else if (dis[v[i]] == rank * 10 + w[i] && len[v[i]] > len[x] + 1) {
        fa[v[i]] = (i ^ 1);
        len[v[i]] = len[x] + 1;
        Q.push(make_pair(dis[v[i]], v[i]));
      }
  }
}
int main() {
  n = read();
  m = read();
  memset(head, -1, sizeof(head));
  cnt = -1;
  int x, y, z;
  for (int i = 1; i <= m; i++) {
    x = read();
    y = read();
    z = read();
    x++;
    y++;
    add(x, y, z), add(y, x, z);
  }
  dijkstra(n);
  int i = 1;
  stack<int> s;
  while (i != n) s.push(w[fa[i]]), i = v[fa[i]];
  while (!s.empty() && s.top() == 0) s.pop();
  if (s.empty())
    printf("0");
  else
    while (!s.empty()) printf("%d", s.top()), s.pop();
  puts("");
  printf("%d\n", len[1]);
  i = 1;
  printf("0 ");
  while (i != n) i = v[fa[i]], printf("%d ", i - 1);
  return 0;
}
