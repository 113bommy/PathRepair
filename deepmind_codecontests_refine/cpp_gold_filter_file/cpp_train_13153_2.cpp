#include <bits/stdc++.h>
using namespace std;
const int mn = 410, mm = 101000, inf = 1 << 30;
bool vis[mn];
int X[mm], Y[mm], du[mn];
int n, m, K, t, S, T, ans[mm], answer;
int dis[mm], pre[mm], Q[mm];
struct network {
  int tt, la[mn], next[mm], y[mm], f[mm], co[mm];
  void clear() {
    tt = 1;
    memset(la, 0, (T + 2) * 4);
  }
  void add(int i, int j, int u, int v) {
    ++tt, next[tt] = la[i], la[i] = tt, y[tt] = j, f[tt] = u, co[tt] = v;
    ++tt, next[tt] = la[j], la[j] = tt, y[tt] = i, f[tt] = 0, co[tt] = -v;
  }
} e;
int spfa() {
  memset(vis, 0, T + 2);
  memset(pre, 0, (T + 2) * 4);
  fill(dis + 1, dis + 1 + T, inf);
  dis[S] = 0;
  int st = 1, ed = 2;
  Q[1] = S, vis[S] = 1;
  while (st != ed) {
    int r = Q[st];
    for (int p = e.la[r], i; p; p = e.next[p]) {
      if (!e.f[p]) continue;
      i = e.y[p];
      if (dis[r] + e.co[p] < dis[i]) {
        dis[i] = dis[r] + e.co[p], pre[i] = p;
        if (!vis[i]) {
          Q[ed] = i, vis[i] = 1;
          ed = (ed + 1) % (T + 2);
        }
      }
    }
    st = (st + 1) % (T + 2);
    vis[r] = 0;
  }
  return dis[T];
}
void repair() {
  for (int i = T, p; i != S; i = e.y[p ^ 1]) {
    p = pre[i];
    --e.f[p], ++e.f[p ^ 1];
  }
}
int main() {
  scanf("%d%d%d%d", &n, &m, &K, &t);
  for (int i = 1; i <= K; ++i) {
    scanf("%d%d", X + i, Y + i);
    ++du[X[i]], ++du[Y[i] + n];
  }
  for (int i = 1; i <= n + m; ++i) answer += (du[i] % t) != 0;
  S = n + m + 1, T = S + 1;
  while (t) {
    e.clear();
    for (int i = 1; i <= K; ++i) {
      if (ans[i]) continue;
      e.add(X[i], Y[i] + n, 1, 0);
    }
    for (int i = 1; i <= n; ++i) {
      e.add(S, i, du[i] / t, 0);
      if (du[i] % t != 0) e.add(S, i, 1, 1);
    }
    for (int i = n + 1; i <= n + m; ++i) {
      e.add(i, T, du[i] / t, 0);
      if (du[i] % t != 0) e.add(i, T, 1, 1);
    }
    while (spfa() < inf) repair();
    int tot = 0;
    for (int i = 1; i <= K; ++i) {
      if (ans[i]) continue;
      ++tot;
      if (e.f[tot * 2] == 0) {
        ans[i] = t;
        --du[X[i]], --du[Y[i] + n];
      }
    }
    --t;
  }
  printf("%d\n", answer);
  for (int i = 1; i <= K - 1; ++i) printf("%d ", ans[i]);
  printf("%d\n", ans[K]);
  return 0;
}
