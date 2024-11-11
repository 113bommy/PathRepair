#include <bits/stdc++.h>
using namespace std;
struct Edge {
  long long l;
  int e, n;
} e[2000020 << 1];
int hd[2000020], cur[2000020], cnt = 1;
void add(int a, int b, long long l) {
  e[++cnt].e = b;
  e[cnt].l = l;
  e[cnt].n = hd[a];
  hd[a] = cnt;
  e[++cnt].e = a;
  e[cnt].l = 0;
  e[cnt].n = hd[b];
  hd[b] = cnt;
}
long long inf = 1e15;
int n, m, s, t;
int dep[2000020];
queue<int> Q;
long long dfs(int p, long long flow) {
  if (p == t) return flow;
  int i;
  for (i = cur[p]; i; i = e[i].n) {
    int q = e[i].e;
    cur[p] = i;
    if (dep[q] > dep[p] && e[i].l) {
      long long ans = dfs(q, min(flow, e[i].l));
      if (ans) {
        e[i].l -= ans;
        e[i ^ 1].l += ans;
        return ans;
      }
    }
  }
  return 0;
}
int bfs() {
  memset(dep, 0, sizeof(dep));
  Q.push(s);
  dep[s] = 1;
  int i;
  while (!Q.empty()) {
    int p = Q.front();
    Q.pop();
    for (i = hd[p]; i; i = e[i].n) {
      int q = e[i].e;
      if (!dep[q] && e[i].l) dep[q] = dep[p] + 1, Q.push(q);
    }
  }
  return dep[t];
}
long long dinic() {
  int i;
  long long d, ans = 0;
  while (bfs()) {
    for (i = 0; i <= t; i++) cur[i] = hd[i];
    while ((d = dfs(s, inf))) ans += d;
  }
  return ans;
}
char a[25][25];
int sign[25][25];
struct Per {
  int x, y;
  long long v;
} boy[2000020], gir[2000020];
int boyn, girn;
struct QUEUE {
  int x, y;
  long long time;
};
int vis[25][25];
int num;
int in(int flag, int NUM, int x, int y) {
  if (!vis[x][y] && x >= 0 && y >= 0 && x < n && y < m && a[x][y] == '.') {
    vis[x][y] = 1;
    if (flag)
      add(NUM, sign[x][y] + boyn + girn, 1);
    else
      add(sign[x][y] + boyn + girn + num, NUM, 1);
    return 1;
  }
  return 0;
}
int jud(long long tim) {
  int i, j;
  int now = 0;
  memset(hd, 0, sizeof(hd));
  cnt = 1;
  for (i = 0; i < n; i++)
    for (j = 0; j < m; j++)
      if (a[i][j] == '.') {
        sign[i][j] = ++now;
        add(boyn + girn + now, boyn + girn + num + now, 1);
      }
  for (i = 0; i < boyn; i++) add(s, i + 1, 1);
  for (i = 0; i < girn; i++) add(i + 1 + boyn, t, 1);
  for (i = 0; i < boyn; i++) {
    int p = i + 1;
    memset(vis, 0, sizeof(vis));
    queue<QUEUE> Q;
    while (!Q.empty()) Q.pop();
    in(1, p, boy[i].x - 1, boy[i].y - 1);
    Q.push({boy[i].x - 1, boy[i].y - 1, 0});
    while (!Q.empty()) {
      int x = Q.front().x, y = Q.front().y;
      long long t = Q.front().time;
      Q.pop();
      if (t + boy[i].v > tim) break;
      if (in(1, p, x + 1, y)) Q.push({x + 1, y, t + boy[i].v});
      if (in(1, p, x - 1, y)) Q.push({x - 1, y, t + boy[i].v});
      if (in(1, p, x, y + 1)) Q.push({x, y + 1, t + boy[i].v});
      if (in(1, p, x, y - 1)) Q.push({x, y - 1, t + boy[i].v});
    }
  }
  for (i = 0; i < girn; i++) {
    int p = i + 1 + boyn;
    memset(vis, 0, sizeof(vis));
    queue<QUEUE> Q;
    while (!Q.empty()) Q.pop();
    in(0, p, gir[i].x - 1, gir[i].y - 1);
    Q.push({gir[i].x - 1, gir[i].y - 1, 0});
    while (!Q.empty()) {
      int x = Q.front().x, y = Q.front().y;
      long long t = Q.front().time;
      Q.pop();
      if (t + gir[i].v > tim) break;
      if (in(0, p, x + 1, y)) Q.push({x + 1, y, t + gir[i].v});
      if (in(0, p, x - 1, y)) Q.push({x - 1, y, t + gir[i].v});
      if (in(0, p, x, y + 1)) Q.push({x, y + 1, t + gir[i].v});
      if (in(0, p, x, y - 1)) Q.push({x, y - 1, t + gir[i].v});
    }
  }
  return dinic() == (boyn + girn) / 2;
}
int main() {
  int i, j, u, v, girnum = 0, boynum = 0;
  scanf("%d%d%d%d", &n, &m, &boyn, &girn);
  for (i = 0; i < n; i++) {
    scanf("%s", a[i]);
    for (j = 0; j < m; j++)
      if (a[i][j] == '.') num++;
  }
  if (num < (boyn + girn + 1) / 2 || (boyn - girn != 1 && girn - boyn != 1))
    return printf("-1"), 0;
  long long l = 0, r = 1e11, ans = 1e15;
  if (boyn - girn == 1)
    scanf("%d%d%I64d", &gir[girnum].x, &gir[girnum].y, &gir[girnum].v),
        girnum++, girn++;
  else
    scanf("%d%d%I64d", &boy[boynum].x, &boy[boynum].y, &boy[boynum].v),
        boynum++, boyn++;
  while (boynum < boyn)
    scanf("%d%d%I64d", &boy[boynum].x, &boy[boynum].y, &boy[boynum].v),
        boynum++;
  while (girnum < girn)
    scanf("%d%d%I64d", &gir[girnum].x, &gir[girnum].y, &gir[girnum].v),
        girnum++;
  s = 0;
  t = boyn + girn + num * 2 + 2;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (jud(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  printf("%I64d", ans < 1e14 ? ans : -1);
  return 0;
}
