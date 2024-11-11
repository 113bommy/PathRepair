#include <bits/stdc++.h>
using namespace std;
int n, s, m, tot = 0, nowt;
struct data {
  int next, num;
} edge[1001];
int head[1001], dis[201][201], d[1001], f[201][201];
int son[1001], vis[1001], is_[1001], sumx[1001];
void add(int u, int v, int w) {
  edge[++tot].next = head[u];
  edge[tot].num = v;
  head[u] = tot;
  return;
}
void pre_work() {
  for (int i = 1; i <= n; i++) dis[i][i] = 0;
  for (int k = 1; k <= n; k++)
    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= n; j++)
        if (dis[i][k] + dis[k][j] < dis[i][j])
          dis[i][j] = dis[j][i] = dis[i][k] + dis[k][j];
}
int find(int x, int nowm, int lim) {
  int l = 0, r = nowm;
  while (l < r) {
    int mid = (l + r) / 2;
    if (mid != nowm && f[x][mid] < lim)
      l = mid + 1;
    else
      r = mid;
  }
  return l;
}
bool check(int nowi, int nowm, int x) {
  int sum = 0;
  for (int i = 1; i <= nowt; i++) {
    int ai = dis[nowi][son[i]];
    int now = find(son[i], nowm, x - ai);
    sum += nowm - now;
  }
  if (sum >= nowm) return 1;
  return 0;
}
void dfs(int x, int fat) {
  sumx[x] = is_[x];
  for (int i = head[x]; i != -1; i = edge[i].next) {
    int kx = edge[i].num;
    if (kx == fat) continue;
    dfs(kx, x);
    vis[x] += vis[kx];
    sumx[x] += sumx[kx];
  }
}
bool check2(int x) {
  memset(vis, 0, sizeof(vis));
  memset(sumx, 0, sizeof(sumx));
  int sum = 0;
  for (int i = 1; i <= nowt; i++) {
    int ai = dis[s][son[i]];
    vis[son[i]] = m - find(son[i], m, x - ai);
    sum += vis[son[i]];
  }
  for (int i = head[s]; i != -1; i = edge[i].next) {
    int kx = edge[i].num;
    dfs(kx, s);
    if (vis[kx] < sumx[kx]) return 0;
  }
  return 1;
}
int calc(int nowi, int nowm) {
  nowt = 0;
  for (int i = 1; i <= n; i++) {
    if (i == nowi) continue;
    if (d[i] > 1) continue;
    son[++nowt] = i;
  }
  int l = 0, r = 1e6;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check(nowi, nowm, mid))
      l = mid;
    else
      r = mid - 1;
  }
  return l;
}
void output() {
  nowt = 0;
  for (int i = 1; i <= n; i++) {
    if (i == s) continue;
    if (d[i] != 1) continue;
    son[++nowt] = i;
  }
  for (int i = 1; i <= m; i++) {
    int x;
    scanf("%d", &x);
    is_[x]++;
  }
  int l = 0, r = 1e6;
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (check2(mid))
      l = mid;
    else
      r = mid - 1;
  }
  printf("%d\n", l);
}
void work() {
  scanf("%d%d", &s, &m);
  for (int i = 1; i <= m; i++)
    for (int j = 1; j <= n; j++) f[j][i] = calc(j, i);
  output();
}
int main() {
  memset(head, -1, sizeof(head));
  memset(dis, 0x3f, sizeof(dis));
  scanf("%d", &n);
  for (int i = 1; i < n; i++) {
    int u, v, w;
    scanf("%d%d%d", &u, &v, &w);
    add(u, v, w);
    add(v, u, w);
    d[u]++;
    d[v]++;
    dis[u][v] = dis[v][u] = w;
  }
  pre_work();
  work();
  return 0;
}
