#include <bits/stdc++.h>
using namespace std;
vector<int> v[305];
int lk[305], vis[305], S, T, x[305];
int h[305 * 305 << 1], to[305 * 305 << 1], ne[305 * 305 << 1],
    en = 0, fl[305 * 305 << 1];
void add(int a, int b, int c) {
  to[en] = b;
  ne[en] = h[a];
  fl[en] = c;
  h[a] = en++;
  to[en] = a;
  ne[en] = h[b];
  fl[en] = 0;
  h[b] = en++;
}
bool dfs(int o) {
  for (int i = 0; i < (int)v[o].size(); ++i)
    if (!vis[v[o][i]]) {
      vis[v[o][i]] = 1;
      if ((!lk[v[o][i]]) || (dfs(lk[v[o][i]]))) {
        lk[v[o][i]] = o;
        return true;
      }
    }
  return false;
}
queue<int> q;
int dis[305];
bool tell() {
  memset(dis, -1, sizeof dis);
  dis[S] = 0;
  q.push(S);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = h[x]; i >= 0; i = ne[i])
      if (dis[to[i]] == -1 && fl[i] > 0) {
        dis[to[i]] = dis[x] + 1;
        q.push(to[i]);
      }
  }
  return dis[T] != -1;
}
int zeng(int k, int now) {
  if (k == T) return now;
  int ret = 0;
  for (int i = h[k]; i >= 0; i = ne[i])
    if (dis[to[i]] == dis[k] + 1 && fl[i] > 0) {
      int tmp = zeng(to[i], min(now - ret, fl[i]));
      fl[i] -= tmp;
      fl[i ^ 1] += tmp;
      ret += tmp;
    }
  if (!ret) dis[k] = -1;
  return ret;
}
int dinic() {
  int tmp, ret = 0;
  while (tell()) {
    while ((tmp = zeng(S, 0x3f3f3f3f))) ret += tmp;
  }
  return ret;
}
int main() {
  memset(h, -1, sizeof h);
  int n;
  scanf("%d", &n);
  S = n + 1;
  T = n + 2;
  for (int i = 1; i <= n; ++i) {
    int y;
    scanf("%d", &x[i]);
    for (int j = 1; j <= x[i]; ++j) {
      scanf("%d", &y);
      v[i].push_back(y);
    }
  }
  for (int i = 1; i <= n; ++i) {
    memset(vis, 0, sizeof vis);
    dfs(i);
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j < (int)v[i].size(); ++j) {
      if (lk[v[i][j]] != i) {
        add(i, lk[v[i][j]], 0x3f3f3f3f);
      }
    }
    int w;
    scanf("%d", &w);
    if (w >= 0)
      add(i, T, w);
    else
      add(S, i, -w), ans -= w;
  }
  printf("%d\n", -(ans - dinic()));
}
