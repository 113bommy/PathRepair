#include <bits/stdc++.h>
using namespace std;
inline long long getnum() {
  register long long r = 0;
  register bool ng = 0;
  register char c;
  c = getchar();
  while (c != '-' && (c < '0' || c > '9')) c = getchar();
  if (c == '-') ng = 1, c = getchar();
  while (c != ' ' && c != '\n') r = r * 10 + c - '0', c = getchar();
  if (ng) r = -r;
  return r;
}
inline void putnum(int x) {
  if (x < 0) putchar('-'), x = -x;
  register short a[20] = {}, sz = 0;
  while (x > 0) a[sz++] = x % 10, x /= 10;
  if (sz == 0) putchar('0');
  for (int i = sz - 1; i >= 0; i--) putchar('0' + a[i]);
}
inline void putsp() { putchar(' '); }
inline void putendl() { putchar('\n'); }
inline char mygetchar() {
  register char c = getchar();
  while (c == ' ' || c == '\n') c = getchar();
  return c;
}
const long long INF = 1 << 29;
const long long LINF = 1ll << 61;
int n, m;
int head[400111], to[400111], nxt[400111], cost[400111], tot, len[500111];
bool vis[100111];
int ans[200111], anssz, dis[100111], q[500111], mn[100111], qb, qe, pre[100111],
    prec[100111], plen[100111];
vector<int> anss;
void add_edge(int x, int y, int c) {
  nxt[++tot] = head[x];
  to[tot] = y;
  head[x] = tot;
  cost[tot] = c;
  nxt[++tot] = head[y];
  to[tot] = x;
  head[y] = tot;
  cost[tot] = c;
}
int main() {
  memset(head, -1, sizeof(head));
  n = getnum(), m = getnum();
  for (int i = 1; i <= m; i++) {
    int x, y, c;
    x = getnum(), y = getnum(), c = getnum();
    add_edge(x, y, c);
  }
  for (int i = 0; i < n; i++) dis[i] = -1;
  qb = qe = 0;
  q[qe++] = 0;
  dis[0] = 0;
  while (qb < qe) {
    int u = q[qb++];
    for (int i = head[u]; i >= 0; i = nxt[i]) {
      if (dis[to[i]] == -1) {
        dis[to[i]] = dis[u] + 1;
        q[qe++] = to[i];
      }
    }
  }
  for (int i = 0; i < n; i++) mn[i] = plen[i] = INF;
  qb = qe = 0;
  len[qe] = 0;
  q[qe++] = n - 1;
  int mnd = INF;
  pre[n - 1] = -1;
  vis[n - 1] = 1;
  while (qb < qe) {
    int u = q[qb], l = len[qb++];
    mnd = min(mnd, dis[u]);
    for (int i = head[u]; i >= 0; i = nxt[i]) {
      if (cost[i] == 0 && !vis[to[i]]) {
        pre[to[i]] = u;
        len[to[i]] = l + 1;
        vis[to[i]] = 1;
        q[qe++] = to[i];
      }
    }
  }
  memset(vis, 0, sizeof(vis));
  qe = 0;
  for (int i = 0; i < qb; i++) {
    if (dis[q[i]] == mnd) {
      len[qe] = len[i];
      q[qe++] = q[i];
    }
  }
  qb = 0;
  while (qb < qe) {
    int l = len[qb], u = q[qb++], d = dis[u];
    if (prec[u] > mn[d] || l > plen[d] || vis[u]) continue;
    vis[u] = 1;
    for (int i = head[u]; i >= 0; i = nxt[i]) {
      int &v = to[i];
      if (dis[u] - 1 == dis[v] &&
          (cost[i] < mn[d - 1] ||
           (cost[i] == mn[d - 1] && l + 1 <= plen[d - 1]))) {
        prec[v] = cost[i];
        pre[v] = u;
        plen[d - 1] = l + 1;
        mn[d - 1] = cost[i];
        len[qe] = l + 1;
        q[qe++] = v;
      }
    }
  }
  for (int i = mnd - 1; i >= 0; i--) putchar('0' + mn[i]);
  if (mnd == 0) {
    printf("0");
  }
  putchar('\n');
  int p = 0;
  while (p != -1) {
    anss.push_back(p);
    p = pre[p];
  }
  putnum(anss.size()), putendl();
  for (int i = 0; i < anss.size(); i++) putnum(anss[i]), putsp();
  return 0;
}
